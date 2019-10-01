// -----------------------------------------------------------------------------------
// Command processing

class cb {
  public:
    bool checksum = false;
    bool add(char c) {
      // (chr)6 is a special status command for the LX200 protocol
      if ((c==(char)6) && (cbp==0)) {
        #ifdef MOUNT_TYPE_ALTAZM
          cb[0]=':'; cb[1]=(char)6; cb[2]='A'; cb[3]=0; cbp=3; c='#';
        #else
          cb[0]=':'; cb[1]=(char)6; cb[2]='P'; cb[3]=0; cbp=3; c='#';
        #endif
      }

      // ignore spaces/lf/cr
      if ((c!=(char)32) && (c!=(char)10) && (c!=(char)13) && (c!=(char)6)) {
        if (cbp>bufferSize-2) cbp=bufferSize-2;
        cb[cbp]=c; cbp++; cb[cbp]=(char)0;
      }

      if (c=='#') {
        // validate the command frame, normal command
        if (!(cbp>1) && (cb[0]==':') && (cb[cbp-1]=='#')) { flush(); return false; }
        if ((cb[0]==':') && (cb[1]=='#') && (cb[2]==0)) { flush(); return false; }

        if (checksum) {
          // checksum the data, for example ":11111126".  I don't include the command frame in the checksum.  The error response is a checksumed null string "00#" which means re-transmit.
          byte len=strlen(cb)-1;
          byte cks=0; for (int cksCount0=1; cksCount0<len-2; cksCount0++) {  cks+=cb[cksCount0]; }
          char chkSum[3]; sprintf(chkSum,"%02X",cks); if (!((chkSum[0]==cb[len-2]) && (chkSum[1]==cb[len-1]))) { flush(); cb[0]=':'; cb[1]=(char)6; cb[2]='0'; cb[3]='#'; cb[4]=0; cbp=4; }
          --len; cb[--len]=0;
        }

        return true;
      } else {
        return false;
      }
    }
    char* getCmd() {
      // the command is either one or two chars in length
      cmd[0]=0;
      memmove(cmd,(char *)&cb[1],2); cmd[2]=0;
      if ((cmd[1]=='#') && (cmd[2]==0)) cmd[1]=0;
      return cmd;
    }
    char* getParameter() {
      // the remaining parameter
      pb[0]=0;
      if (cbp>4) memmove(pb,(char *)&cb[3],cbp-4); pb[cbp-4]=0;
      return pb;
    }
    bool ready() {
      if (!cbp) return false;
      if ((cb[cbp-1]=='#') && (cbp==1)) flush();
      return (cb[cbp-1]=='#');
    }
    bool flush() {
      cbp=0;
      cb[0]=(char)0;
      return true;
    }
  private:
    const static int bufferSize=25;
    char cmd[4]="";
    char pb[bufferSize]="";
    char cb[bufferSize]="";
    int cbp=0;
};

