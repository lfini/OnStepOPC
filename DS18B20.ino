/********************************************************************/
// First we include the libraries
#include <OneWire.h> 
#include <DallasTemperature.h>
#include "DS18B20.h"
/********************************************************************/
// Data wire is plugged into pin 14 on the Arduino 
#define ONE_WIRE_BUS 14 
/********************************************************************/
// Setup a oneWire instance to communicate with any OneWire devices  
// (not just Maxim/Dallas temperature ICs) 
OneWire oneWire(ONE_WIRE_BUS); 
/********************************************************************/
// Pass our oneWire reference to Dallas Temperature. 
DallasTemperature sensors(&oneWire);
/********************************************************************/ 

float Temperatures[NSENSORS];


void DS18setup(void) 
{ 
    sensors.begin(); 
    for(int i=0; i<NSENSORS; i++) Temperatures[i]=0.0;
} 

float* readDS18(void) 
{ 

 sensors.requestTemperatures(); // Send the command to get temperature readings 
 for (int i=0; i<NSENSORS;i++) Temperatures[i]= sensors.getTempCByIndex(i);
 return Temperatures;
/********************************************************************/

} 
