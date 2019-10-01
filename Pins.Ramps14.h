// -------------------------------------------------------------------------------------------------
// Pin map for OnStep using RAMPS 1.4 Shield (Arduino Mega2560 or Arduino DUE)

#if defined(__AVR_ATmega2560__) || defined(__SAM3X8E__)

// The PEC index sense is a 5V logic input, resets the PEC index on rising edge then waits for 60 seconds before allowing another reset
#define PecPin        57    // RAMPS AUX1, A-OUT (1=+5V, 2=GND, 3=PEC)
#define AnalogPecPin  A3    // Note A3 is (57)

// The limit switch sense is a 5V logic input which uses the internal pull up, shorted to ground it stops gotos/tracking
#define LimitPin       3    // RAMPS X- (1=LMT, 2=GND, 3=+5)

// The status LED is a two wire jumper with a 10k resistor in series to limit the current to the LED
#define LEDnegPin     11    // Pin 11 RAMPS SER1 (1=GND, 2=LED-, 3=+5) (active LOW)
#define LEDneg2Pin     6    // Pin 6  RAMPS SER2 (1=GND, 2=LED-, 3=+5) (active LOW)
#define ReticulePin    5    // Pin 5  RAMPS SER3 (1=GND, 2=LED-, 3=+5) (active LOW)

// Pin for a piezo buzzer output on RAMPS Y-MIN
#define TonePin        4    // Pin 4  RAMPS SER4 (1=GND, 2=LED-, 3=+5)

// The PPS pin is a 5V logic input, OnStep measures time between rising edges and adjusts the internal sidereal clock frequency
#define PpsPin         2    // RAMPS X+, Interrupt 0 on Pin 2
#define DS3234_CS_PIN 53

// Pins to Axis1 RA/Azm on RAMPS X
#define Axis1DirPin   55    // Pin A1 (Dir)
#define Axis1DirBit    1    //
#define Axis1DirPORT  PORTF //
#define Axis1StepPin  54    // Pin A0 (Step)
#define Axis1StepBit   0    //
#define Axis1StepPORT PORTF //
#define Axis1_Aux     29    // Pin 29 (Aux - ESP8266 GPIO0 or SPI MISO)
#define Axis1_M2      27    // Pin 27 (Microstep Mode 2 or SPI CS)
#define Axis1_M1      25    // Pin 25 (Microstep Mode 1 or SPI SCK)
#define Axis1_M0      23    // Pin 23 (Microstep Mode 0 or SPI MOSI)
#define Axis1_EN      38    // Pin 38 (Enable)

// Pins to Axis2 Dec/Alt on RAMPS Y
#define Axis2DirPin    61   // Pin A7 (Dir)
#define Axis2DirBit    7    //
#define Axis2DirPORT  PORTF //
#define Axis2StepPin   60   // Pin A6 (Step)
#define Axis2StepBit   6    //
#define Axis2StepPORT PORTF //
#define Axis2_Aux     37    // Pin 37 (Aux - ESP8266 GPIO0 or SPI MISO)
#define Axis2_M2      35    // Pin 35 (Microstep Mode 2 or SPI CS)
#define Axis2_M1      33    // Pin 33 (Microstep Mode 1 or SPI SCK)
#define Axis2_M0      31    // Pin 31 (Microstep Mode 0 or SPI MOSI)
#define Axis2_EN      56    // Pin A2 (Enable)

// Pins to rotator stepper driver on RAMPS Z
#define Axis3DirPin   48    // Pin 48 (Dir)
#define Axis3StepPin  46    // Pin 46 (Step)
#define Axis3_EN      62    // Pin A8 (Enable)

// Pins to focuser1 stepper driver on RAMPS E0
#define Axis4DirPin   28    // Pin 28 (Dir)
#define Axis4StepPin  26    // Pin 26 (Step)
#define Axis4_EN      24    // Pin 24 (Enable)

// Pins to focuser2 stepper driver on RAMPS E1
#define Axis5DirPin   34    // Pin 34 (Dir)
#define Axis5StepPin  36    // Pin 36 (Step)
#define Axis5_EN      30    // Pin 30 (Enable)

// ST4 interface on RAMPS AUX-2
#define ST4RAw        A9    // Pin A9  ST4 RA- West
#define ST4DEs        40    // Pin 40  ST4 DE- South
#define ST4DEn        42    // Pin 42  ST4 DE+ North
#define ST4RAe        A11   // Pin A11 ST4 RA+ East

#else
#error "Wrong processor for this configuration!"

#endif

