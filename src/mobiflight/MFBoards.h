//
// MFBoards.h (Arduino Custom)
//
// (C) MobiFlight Project 2022
//

#ifndef MFBoardMega_h
#define MFBoardMega_h

//#ifndef MF_SEGMENT_SUPPORT
//#define MF_SEGMENT_SUPPORT 0
//#endif
//#ifndef MF_LCD_SUPPORT
//#define MF_LCD_SUPPORT 0
//#endif
//#ifndef MF_STEPPER_SUPPORT
//#define MF_STEPPER_SUPPORT 0
//#endif
#ifndef MF_SERVO_SUPPORT
#define MF_SERVO_SUPPORT 0
#endif
#ifndef MF_ANALOG_SUPPORT
#define MF_ANALOG_SUPPORT 1
#endif
#ifndef MF_OUTPUT_SHIFTER_SUPPORT
#define MF_OUTPUT_SHIFTER_SUPPORT 0
#endif
#ifndef MF_INPUT_SHIFTER_SUPPORT
#define MF_INPUT_SHIFTER_SUPPORT 0
#endif
#ifndef MF_MUX_SUPPORT
#define MF_MUX_SUPPORT 0
#endif
#ifndef MF_DIGIN_MUX_SUPPORT
#define MF_MUX_SUPPORT       0
#define MF_DIGIN_MUX_SUPPORT 0
#endif

#define MAX_OUTPUTS         200
#define MAX_BUTTONS         200
#define MAX_LEDSEGMENTS     0
#define MAX_ENCODERS        0
#define MAX_STEPPERS        0
#define MAX_MFSERVOS        0
#define MAX_MFLCD_I2C       0
#define MAX_ANALOG_INPUTS   200
#define MAX_OUTPUT_SHIFTERS 0
#define MAX_INPUT_SHIFTERS  0
#define MAX_DIGIN_MUX       0

#define STEPS         64
#define STEPPER_SPEED 400 // 300 already worked, 467, too?
#define STEPPER_ACCEL 800

#define MOBIFLIGHT_TYPE     "MobiFlight Hub"
#define MOBIFLIGHT_SERIAL   "1234567890"
#define MOBIFLIGHT_NAME     "MobiFlight Hub"
#define EEPROM_SIZE         4096 // EEPROMSizeMega
#define MEMLEN_CONFIG       1496 // max. size for config which wil be stored in EEPROM
#define MEMLEN_NAMES_BUFFER 1000 // max. size for configBuffer, contains only names from inputs
#define MF_MAX_DEVICEMEM    1500 // max. memory size for devices

#define RANDOM_SEED_INPUT A0

#endif

// MFBoards.h
