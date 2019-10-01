// -------------------------------------------------------------------------------------------------
// Pin map for OnStep MaxPCB (Teensy3.5/3.6)

#if defined(__MK64FX512__) || defined(__MK66FX1M0__)

// The PEC index sense is a logic level input, resets the PEC index on rising edge then waits for 60 seconds before allowing another reset
#define PecPin        23
#define AnalogPecPin  23    // Pin 23 (PEC Sense, analog or digital)

// The status LED is a two wire jumper with a 10k resistor in series to limit the current to the LED
#define LEDnegPin     19    // Pin 19 (Drain)
#define LEDneg2Pin    22    // Pin 22 (Drain)
#define ReticulePin   22    // Pin 22 (Drain)

// For a piezo buzzer
#define TonePin       29    // Pin 29 (Tone)

// The PPS pin is a 3.3V logic input, OnStep measures time between rising edges and adjusts the internal sidereal clock frequency
#define PpsPin        28    // Pin 28 (PPS time source, GPS for example)
#define DS3234_CS_PIN 10

#define Axis1DirPin   21    // Pin 21 (Dir)
#define Axis1StepPin  20    // Pin 20 (Step)
#define RstPin        19    // Pin 19 (Reset)
#define Axis1_FAULT   18    // Pin 18 (Fault)
#define Axis1_Aux     18    // Pin 18 (Aux1 - ESP8266 GPIO0 or SPI MISO)
#define Axis1_M2      17    // Pin 17 (Microstep Mode 2 or SPI CS)
#define Axis1_M1      16    // Pin 16 (Microstep Mode 1 or SPI SCK)
#define Axis1_M0      15    // Pin 15 (Microstep Mode 0 or SPI MOSI)
#define Axis1_EN      14    // Pin 14 (Enable)
#define Axis1_SDO     18    // Pin 18 (SPI Slave SDO)
#define Axis1_CS      17    // Pin 17 (SPI Slave CS)
#define Axis1_SCK     16    // Pin 16 (SPI Slave SCK)
#define Axis1_SDI     15    // Pin 15 (SPI Slave SDI)

#define Axis2DirPin    2    // Pin  2 (Dir)
#define Axis2StepPin   3    // Pin  3 (Step)
#define LimitPin       4    // Pin  4 (The limit switch sense is a logic level input which uses the internal pull up, shorted to ground it stops gotos/tracking)
#define Axis2_FAULT    5    // Pin  5 (Fault)
#define Axis2_Aux      5    // Pin  5 (Aux2 - ESP8266 RST or SPI MISO)
#define Axis2_M2       6    // Pin  6 (Microstep Mode 2 or SPI CS)
#define Axis2_M1       7    // Pin  7 (Microstep Mode 1 or SPI SCK)
#define Axis2_M0       8    // Pin  8 (Microstep Mode 0 or SPI MOSI)
#define Axis2_EN       9    // Pin  9 (Enable)

// Pins to rotator stepper driver
#define Axis3DirPin   33    // Pin 33 (Dir)
#define Axis3StepPin  30    // Pin 30 (Step)
#define Axis3_EN      36    // Pin 36 (Aux3 - Enable)

// Pins to focuser1 stepper driver
#define Axis4DirPin   35    // Pin 35 (Dir)
#define Axis4StepPin  34    // Pin 34 (Step)
#define Axis4_EN      39    // Pin 39 (Aux4 - Enable)

// Pins to focuser2 stepper driver
#define Axis5DirPin   33    // Pin 33 (Dir)
#define Axis5StepPin  30    // Pin 30 (Step)

// ST4 interface
#define ST4RAw        24    // Pin 24 ST4 RA- West
#define ST4DEs        25    // Pin 25 ST4 DE- South
#define ST4DEn        26    // Pin 26 ST4 DE+ North
#define ST4RAe        27    // Pin 27 ST4 RA+ East

#else
#error "Wrong processor for this configuration!"

#endif

