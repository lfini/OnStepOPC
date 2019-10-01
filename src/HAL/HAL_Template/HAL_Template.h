// Platform setup ------------------------------------------------------------------------------------

// We define a more generic symbol, in case more Platform_Name boards based on different lines are supported
#define __Platform_Name__

#include <EEPROM.h>

// New symbols for the Serial ports so they can be remapped if necessary -----------------------------
#define PSerial Serial
// SERIAL is always enabled SERIAL1 and SERIAL4 are optional
//#define PSerial1 Serial1

//--------------------------------------------------------------------------------------------------
// Initialize timers

// frequency compensation (F_COMP/1000000.0) for adjusting microseconds to timer counts
#define F_COMP 1000000

#define ISR(f) void f (void)
void TIMER1_COMPA_vect(void);  // Sidereal timer
void TIMER3_COMPA_vect(void);  // Axis1 RA/Azm timer
void TIMER4_COMPA_vect(void);  // Axis2 DEC/Alt timer

// if possible run TIMER3 and TIMER4 at the highest priority level with everything else below

// Init sidereal clock timer
void HAL_Init_Timer_Sidereal() {
}

// Init Axis1 and Axis2 motor timers and set their priorities
void HAL_Init_Timers_Motor() {
}

//--------------------------------------------------------------------------------------------------
// Set timer1 to interval (in microseconds*16), for the 1/100 second sidereal timer

void Timer1SetInterval(long iv, double rateRatio) {
}

//--------------------------------------------------------------------------------------------------
// Quickly reprogram the interval (in microseconds*(F_COMP/1000000.0)) for the motor timers, must work from within the motor ISR timers

void QuickSetIntervalAxis1(uint32_t r) {
}

void QuickSetIntervalAxis2(uint32_t r) {
}

// --------------------------------------------------------------------------------------------------
// Fast port writing help

#define CLR(x,y) (x&=(~(1<<y)))
#define SET(x,y) (x|=(1<<y))
#define TGL(x,y) (x^=(1<<y))

// We use standard #define's to do **fast** digitalWrite's to the step and dir pins for the Axis1/2 stepper drivers
#define StepPinAxis1_HIGH digitalWrite(Axis1StepPin, HIGH)
#define StepPinAxis1_LOW digitalWrite(Axis1StepPin, LOW)
#define DirPinAxis1_HIGH digitalWrite(Axis1DirPin, HIGH)
#define DirPinAxis1_LOW digitalWrite(Axis1DirPin, LOW)

#define StepPinAxis2_HIGH digitalWrite(Axis2StepPin, HIGH)
#define StepPinAxis2_LOW digitalWrite(Axis2StepPin, LOW)
#define DirPinAxis2_HIGH digitalWrite(Axis2DirPin, HIGH)
#define DirPinAxis2_LOW digitalWrite(Axis2DirPin, LOW)

