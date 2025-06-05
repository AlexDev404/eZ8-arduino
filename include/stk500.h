//**** ATMEL AVR - A P P L I C A T I O N   N O T E  ************************
//*
//* Title:		AVR061 - STK500 Communication Protocol
//* Filename:		command.h
//* Version:		1.0
//* Last updated:	05.20.2024
//* Modified on 06.03.2025 by AlexDev404 (Immanuel DGarcia)
//* Support E-mail:	avr@atmel.com
//*
//**************************************************************************

// *****************[ STK Version constants ]***************************

#define HW_VER      0x02  // Hardware version
#define SW_MAJOR    0x01  // Software major version
#define SW_MINOR    0x12  // Software minor version

// *****************[ STK Message constants ]***************************

//#define PROPS_SIGNATURE_0__  0xF0
//#define PROPS_SIGNATURE_1__  0x08
//#define PROPS_SIGNATURE_2__ 0xFF

// Custom AVDUDE configuration for Z8 Encore! (1E 95 0F for spoofing ATMega328p)
#define PROPS_SIGNATURE_H 0x1E
#define PROPS_SIGNATURE_M 0x95
#define PROPS_SIGNATURE_L 0x0F

/*#define PROPS_SIGNATURE_0 0x1E
#define PROPS_SIGNATURE_1 0x94
#define PROPS_SIGNATURE_2 0x06*/
#define STK_SIGN_ON_MESSAGE "Z8 Encore! STK"   // Sign on string for CMD_STK_GET_SIGN_ON

// *****************[ STK Response constants ]***************************

/* STK500 constants list, from AVRDUDE */
#define STK_NULL            0x00  // Covers various responses we do not care about
#define STK_OK              0x10
#define STK_FAILED          0x11  // Not used
#define STK_UNKNOWN         0x12  // Not used
#define STK_NODEVICE        0x13  // Not used
#define STK_INSYNC          0x14  // ' '
#define STK_NOSYNC          0x15  // Used
#define ADC_CHANNEL_ERROR   0x16  // Not used
#define ADC_MEASURE_OK      0x17  // Not used
#define PWM_CHANNEL_ERROR   0x18  // Not used
#define PWM_ADJUST_OK       0x19  // Not used

// *****************[ STK Special constants ]***************************

#define SPECIAL_Sync_CRC_EOP               0x20  // 'SPACE'


// *****************[ STK Command constants ]***************************

#define CMD_STK_GET_SYNC          0x30  // '0'
#define CMD_STK_GET_SIGN_ON       0x31  // '1'
#define CMD_STK_SET_PARAMETER     0x40  // '@'
#define CMD_STK_GET_PARAMETER     0x41  // 'A'
#define CMD_STK_SET_DEVICE        0x42  // 'B'
#define CMD_STK_SET_DEVICE_EXT    0x45  // 'E'
#define CMD_STK_ENTER_PROGMODE    0x50  // 'P'
#define CMD_STK_LEAVE_PROGMODE    0x51  // 'Q'
#define CMD_STK_CHIP_ERASE        0x52  // 'R'
#define CMD_STK_CHECK_AUTOINC     0x53  // 'S'
#define CMD_STK_LOAD_ADDRESS      0x55  // 'U'
#define CMD_STK_UNIVERSAL         0x56  // 'V'
#define CMD_STK_UNIVERSAL_MULTI   0x57  // ' '
#define CMD_STK_PROG_FLASH        0x60  // '`'
#define CMD_STK_PROG_DATA         0x61  // 'a'
#define CMD_STK_PROG_FUSE         0x62  // 'b'
#define CMD_STK_PROG_LOCK         0x63  // 'c'
#define CMD_STK_PROG_PAGE         0x64  // 'd'
#define CMD_STK_PROG_FUSE_EXT     0x65  // 'e'
#define CMD_STK_READ_FLASH        0x70  // 'p'
#define CMD_STK_READ_DATA         0x71  // 'q'
#define CMD_STK_READ_FUSE         0x72  // 'r'
#define CMD_STK_READ_LOCK         0x73  // 's'
#define CMD_STK_READ_PAGE         0x74  // 't'
#define CMD_STK_READ_SIGN         0x75  // 'u'
#define CMD_STK_READ_OSCCAL       0x76  // 'v'
#define CMD_STK_READ_FUSE_EXT     0x77  // 'w'
#define CMD_STK_READ_OSCCAL_EXT   0x78  // 'x'

// *****************[ STK Parameter constants ]***************************

#define PARAM_STK_HW_VER            0x80  // ' ' - R
#define PARAM_STK_SW_MAJOR          0x81  // ' ' - R
#define PARAM_STK_SW_MINOR          0x82  // ' ' - R
#define PARAM_STK_LEDS              0x83  // ' ' - R/W
#define PARAM_STK_VTARGET           0x84  // ' ' - R/W
#define PARAM_STK_VADJUST           0x85  // ' ' - R/W
#define PARAM_STK_OSC_PSCALE        0x86  // ' ' - R/W
#define PARAM_STK_OSC_CMATCH        0x87  // ' ' - R/W
#define PARAM_STK_RESET_DURATION    0x88  // ' ' - R/W
#define PARAM_STK_SCK_DURATION      0x89  // ' ' - R/W

#define PARAM_STK_BUFSIZEL          0x90  // ' ' - R/W, Range {0..255}
#define PARAM_STK_BUFSIZEH          0x91  // ' ' - R/W, Range {0..255}
#define PARAM_STK_DEVICE            0x92  // ' ' - R/W, Range {0..255}
#define PARAM_STK_PROGMODE          0x93  // ' ' - 'P' or 'S'
#define PARAM_STK_PARAMODE          0x94  // ' ' - TRUE or FALSE
#define PARAM_STK_POLLING           0x95  // ' ' - TRUE or FALSE
#define PARAM_STK_SELFTIMED         0x96  // ' ' - TRUE or FALSE
#define PARAM_STK500_TOPCARD_DETECT 0x98  // ' ' - Detect top-card attached

// *****************[ STK status bit definitions ]***************************

#define Stat_STK_INSYNC            0x01  // INSYNC status bit, '1' - INSYNC
#define Stat_STK_PROGMODE          0x02  // Programming mode,  '1' - PROGMODE
#define Stat_STK_STANDALONE        0x04  // Standalone mode,   '1' - SM mode
#define Stat_STK_RESET             0x08  // RESET button,      '1' - Pushed
#define Stat_STK_PROGRAM           0x10  // Program button, '   1' - Pushed
#define Stat_STK_LEDG              0x20  // Green LED status,  '1' - Lit
#define Stat_STK_LEDR              0x40  // Red LED status,    '1' - Lit
#define Stat_STK_LEDBLINK          0x80  // LED blink ON/OFF,  '1' - Blink


// *****************************[ End Of COMMAND.H ]**************************