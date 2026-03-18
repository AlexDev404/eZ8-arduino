/*************************************************
 *  Copyright (C) 1999-2018 by  Zilog, Inc.
 *  All Rights Reserved
 *************************************************/

#pragma once // Include this file only once
#ifndef EZ8_H
#define EZ8_H

#if defined(_Z8ENCORE_F642X) || defined(_Z8ENCORE_64K_SERIES) || defined(_Z8ENCORE_XP_64XX_SERIES)
#define _Z8F642
#endif

#if defined(_Z8ENCORE_F640X) || defined(_Z8ENCORE_640_FAMILY)
#define _Z8F640
#endif

#if defined(_Z8ENCORE_F08X) || defined(_Z8ENCORE_8K_SERIES) || defined(_Z8ENCORE_XP_F0822_SERIES)
#define _Z8F08
#endif

#if defined(_Z8ENCORE_F04XA) || defined(_Z8ENCORE_XP_4K_SERIES)
#define _Z8F04A
#endif

#if defined(_Z8ENCORE_4K_SERIES)
#define _Z8F04
#endif

#if defined(_Z8ENCORE_4K_8PIN_SERIES)
#define _Z8F04_8PIN
#define _Z8F04
#endif

#if defined(_Z8ENCORE_XP_4K_8PIN_SERIES)
#define _Z8F04A_8PIN
#define _Z8F04A
#endif

#if defined(_Z8ENCORE_XP_F08XA_SERIES) || defined(_Z8ENCORE_XP_F082A_SERIES) || defined(_Z8ENCORE_ZMOTION_F04_SERIES)
#define _Z8F04A
#endif

#if defined(_Z8ENCORE_XP_F0830_SERIES) || defined(_Z8ENCORE_XP_F083A_SERIES) || defined(_Z8ENCORE_F0830_SERIES) || defined(_Z8ENCORE_F083A_SERIES)
#define _Z8F04A
#define _Z8F0830A
#endif

#if defined(_Z8ENCORE_XP_F0830_SERIES) || defined(_Z8ENCORE_F0830_SERIES)
#define _Z8F0830S
#endif

#if defined(_Z8ENCORE_XP_F08XA_8PIN_SERIES) || defined(_Z8ENCORE_XP_F082A_8PIN_SERIES) || defined(_Z8ENCORE_ZMOTION_F04_8PIN_SERIES)
#define _Z8F04A
#define _Z8F04A_8PIN
#endif

#if defined(_Z8ENCORE_F0823_SERIES) || defined(_Z8ENCORE_XP_F0823_SERIES)
#define _Z8F04
#endif

#if defined(_Z8ENCORE_F0823_8PIN_SERIES) || defined(_Z8ENCORE_XP_F0823_8PIN_SERIES)
#define _Z8F04
#define _Z8F04_8PIN
#endif

#if defined(_Z8ENCORE_Z8FMC16100_SERIES)
#define _Z8FMC16
#endif

#if defined(_Z8ENCORE_XP_F1680_SERIES)
#define _Z8F1680
#endif

#if defined(_Z8ENCORE_XP_F1680_SERIES_24K) || defined(_Z8ENCORE_XP_F1680_SERIES_16K) 
#define _Z8F1680
#endif

#if defined(_Z8ENCORE_XP_F1680_SERIES_8K) || defined(_Z8ENCORE_XP_F1680_SERIES_4K)
#define _Z8F1680
#endif

#if defined(_Z8ENCORE_F648)
#define _Z8F648		// Don't use _Z8F6482 for the family symbol, because that is the symbol for an individual part
#endif

#if defined(_Z8ENCORE_ZMOTION_F6482_SERIES_64K) || defined(_Z8ENCORE_ZMOTION_F6482_SERIES_16K)
#define _Z8F648	
#endif

#if defined(_Z8ENCORE_XP_F3224_SERIES_32K) || defined(_Z8ENCORE_XP_F3224_SERIES_16K)  || defined (_Z8ENCORE_ZMOTION_F3224_SERIES_32K)
#define _Z8F3224		
#endif

#if (defined(_Z8F1680) || defined(_Z8F648)) && (!defined(_Z8F3224))
#define _Z8F1680_OR_Z8F648
#endif

#if defined(_Z8F1680) || defined(_Z8F648) || defined(_Z8F3224)
#define _Z8F1680_OR_Z8F648_OR_Z8F3224
#endif

#if 0              
//These macros are not needed now, they are defined in the project settings
#if defined(_Z8F1624xH) || defined(_Z8F3224xH) || defined(_Z8F3224xH_2258)
#define _Z8FXX24xH
#endif

#if defined(_Z8F1624xK) || defined(_Z8F3224xK) || defined(_Z8F3224xK_2258)
#define _Z8FXX24xK
#endif

#if defined(_Z8F1624xN) || defined(_Z8F3224xN) || defined(_Z8F3224xN_2258)
#define _Z8FXX24xN
#endif
#endif

#if defined(_Z8F0830) || defined(_Z8F0831) || defined(_Z8F1232) || defined(_Z8F1233) \
 || defined(_Z8F083A) || defined(_Z8ENCORE_XP_64XX_SERIES) \
 || defined(_Z8F0811) || defined(_Z8F0812) || defined(_Z8F0821) || defined(_Z8F0822) \
 || defined(_Z8F0813XB) || defined(_Z8F0823XB) \
 || defined(_Z8F0813) || defined(_Z8F0823) \
 || defined(_Z8F081AXB) || defined(_Z8F082AXB) \
 || defined(_Z8F081A) || defined(_Z8F082A) \
 || defined(_Z8ENCORE_F1680) || defined(_Z8FXX24) || defined(_Z8ENCORE_F648) \
 || defined(_Z8FMC08100) || defined(_Z8FMC16100)  
#define ENCORE_HAS_MIN_8K
#endif

#if defined(_Z8F642) || defined(_Z8F640) || defined(_Z8F08) || defined(_Z8F04)
#define ENCORE_VECTORS
#endif

#if defined(_Z8F04A)
#define ENCORE_XP_VECTORS
#endif

#if defined(_Z8FMC16)
#define ENCORE_MC_VECTORS
#endif

#if defined(_Z8F1680)
#define ENCORE_XP16K_VECTORS
#endif

#if defined(_Z8F648) || defined(_Z8F3224)
#define ENCORE_F6482_VECTORS
#endif

#define EZ8_IRQ3
#define EZ8_TIMER2
#define EZ8_UART0

#if defined(_Z8F640) || defined(_Z8F642)
#define EZ8_SPI
#define EZ8_ADC
#define EZ8_TIMER3
#define EZ8_PORT4
#define EZ8_I2C
#endif

#if defined(_Z8F640) || defined(_Z8F642) || defined(__ZSLBUILD)
#define EZ8_UART1
#define EZ8_DMA
#endif

#if defined(_Z8F08)
#define EZ8_I2C
#endif

#if defined(_Z8F04A)
#define EZ8_NVDS
#endif

#if defined(_Z8F04A) || defined(_Z8F04) || defined(__ZSLBUILD)
#define EZ8_PORT4
#endif

#if defined(_Z8F04A_8PIN) || defined(_Z8F04_8PIN)
#define EZ8_PORT1
#undef EZ8_IRQ3
#endif

#if defined(_Z8F0830A)
#undef EZ8_UART0
#endif

#if defined(_Z8FMC16)
#define EZ8_ADC_NEW
#define EZ8_PWM
#undef EZ8_TIMER2
#undef EZ8_IRQ3
#endif

#if defined(_Z8F1680_OR_Z8F648)
#define EZ8_TIMER3
#define EZ8_I2C
#define EZ8_PORT4
#define EZ8_NVDS
#endif

#if defined(_Z8F2480XH) || defined(_Z8F2480XJ) || defined(_Z8F2480XM) || defined(_Z8F2480XN)
#undef EZ8_NVDS
#endif

#if defined(_Z8F2481XH) || defined(_Z8F2481XJ) || defined(_Z8F2481XM) || defined(_Z8F2481XN)
#undef EZ8_NVDS
#endif

#if defined(_Z8ENCORE_XP_F6482_SERIES_64K)
#undef EZ8_NVDS
#endif

#if defined(_Z8F2480XH) || defined(_Z8F1680XH) || defined(_Z8F0880XH) || defined(_Z8F0480XH)
#define EZ8_ADC_NEW
#endif

#if defined(_Z8F2480XJ) || defined(_Z8F1680XJ) || defined(_Z8F0880XJ) || defined(_Z8F0480XJ)
#define EZ8_ESPI
#define EZ8_ADC_NEW
#endif

#if defined(_Z8F2480XM) || defined(_Z8F1680XM) || defined(_Z8F0880XM) || defined(_Z8F0480XM)
#define EZ8_ESPI
#define EZ8_UART1
#define EZ8_CMP1
#define EZ8_ADC_NEW
#define EZ8_PORT5 
#endif

#if defined(_Z8F2480XN) || defined(_Z8F1680XN) || defined(_Z8F0880XN) || defined(_Z8F0480XN)
#define EZ8_ESPI
#define EZ8_UART1
#define EZ8_CMP1
#define EZ8_ADC_NEW
#define EZ8_PORT5
#define EZ8_MCT
#endif

#if defined(_Z8F2481XJ) || defined(_Z8F1681XJ) || defined(_Z8F0881XJ) || defined(_Z8F0481XJ)
#define EZ8_ESPI
#endif

#if defined(_Z8F2481XM) || defined(_Z8F1681XM) || defined(_Z8F0881XM) || defined(_Z8F0481XM)
#define EZ8_ESPI
#define EZ8_UART1
#define EZ8_CMP1
#define EZ8_PORT5 
#endif

#if defined(_Z8F2481XN) || defined(_Z8F1681XN) || defined(_Z8F0881XN) || defined(_Z8F0481XN) || defined(_Z8F1681xN_2247) 
#define EZ8_ESPI
#define EZ8_UART1
#define EZ8_CMP1
#define EZ8_PORT5 
#define EZ8_MCT
#endif

#if defined(_Z8FMC16100) || defined(_Z8FMC08100) || defined(_Z8FMC04100)
#define EZ8_I2C
#define EZ8_SPI
#endif

#if  defined(_Z8F6423) || defined(_Z8F6422) || defined(_Z8F4823) || defined(_Z8F4822)
#define EZ8_TIMER4
#endif

#if  defined(_Z8F3222) || defined(_Z8F2422) || defined(_Z8F1622)    
#define EZ8_TIMER4
#endif

#if  defined(_Z8F6423) || defined(_Z8F6422) || defined(_Z8F4823) || defined(_Z8F4822) || defined(__ZSLBUILD)
#define EZ8_PORT8
#endif

#if  defined(_Z8F3222) || defined(_Z8F2422) || defined(_Z8F1622)
#define EZ8_PORT8
#endif

#if  defined(_Z8F6403) || defined(_Z8F6402) || defined(_Z8F4803) || defined(_Z8F4802)
#define EZ8_TIMER4
#endif

#if  defined(_Z8F3202) || defined(_Z8F2402) || defined(_Z8F1602)    
#define EZ8_TIMER4
#endif

#if  defined(_Z8F6403) || defined(_Z8F6402) || defined(_Z8F4803) || defined(_Z8F4802)
#define EZ8_PORT8
#endif

#if  defined(_Z8F3202) || defined(_Z8F2402) || defined(_Z8F1602)
#define EZ8_PORT8
#endif


#if defined(_Z8F0822) || defined(_Z8F0812) || defined(_Z8F0422) || defined(_Z8F0412)
#define EZ8_SPI 
#endif

#if defined(_Z8F0822) || defined(_Z8F0821) || defined(_Z8F0422) || defined(_Z8F0421)
#define EZ8_ADC 
#endif

#if defined(_Z8F042A) || defined(_Z8F022A) || defined(_Z8F012A) || defined(_Z8F082A) \
 || defined(_Z8ENCORE_ZMOTION_F04_SERIES) || defined(_Z8ENCORE_ZMOTION_F04_8PIN_SERIES) 
#define EZ8_ADC
#endif

#if defined(_Z8F042AXB) || defined(_Z8F022AXB) || defined(_Z8F012AXB) || defined(_Z8F082AXB)
#define EZ8_ADC
#endif

#if defined(_Z8FS040xSB) || defined(_Z8FS040xHH) || defined(_Z8FS040xHJ)
#define EZ8_ADC
#endif

#if defined(_Z8FS021xSB) || defined(_Z8FS021xHH) || defined(_Z8FS021xHJ)
#define EZ8_ADC
#endif

#if defined(_Z8F0423XH) || defined(_Z8F0223XH) || defined(_Z8F0123XH)
#define EZ8_ADC
#endif

#if defined(_Z8F0423XJ) || defined(_Z8F0223XJ) || defined(_Z8F0123XJ) 
#define EZ8_ADC
#endif

#if defined(_Z8F0423) || defined(_Z8F0223) || defined(_Z8F0123)
#define EZ8_ADC
#endif

#if defined(_Z8F0423XB) || defined(_Z8F0223XB) || defined(_Z8F0123XB)
#define EZ8_ADC
#endif

#if defined(_Z8F0823) || defined(_Z8F0823XB)
#define EZ8_ADC
#endif

#if defined(_Z8F1232) || defined(_Z8F0832) || defined(_Z8F0830) || defined(_Z8F0430) || defined(_Z8F0432)
#define EZ8_ADC_NEW
#endif

#if defined(_Z8F0232) || defined(_Z8F0230) || defined(_Z8F0132) || defined(_Z8F0130)
#define EZ8_ADC_NEW
#endif

#if defined(_Z8F1232) || defined(_Z8F1233) || defined(_Z8F0832) || defined(_Z8F0833) || defined(_Z8F0432)
#undef EZ8_NVDS
#endif

#if defined(_Z8F0433) || defined(_Z8F0232) || defined(_Z8F0233) || defined(_Z8F0132) || defined(_Z8F0133)
#undef EZ8_NVDS
#endif

#if defined(_Z8F083A) || defined(_Z8F043A)
#define EZ8_ADC_NEW
#endif

#if defined(_Z8F081A) || defined(_Z8F082A) || defined(_Z8F081AXB) || defined(_Z8F082AXB) \
 || defined(_Z8ENCORE_ZMOTION_F04_SERIES) || defined(_Z8ENCORE_ZMOTION_F04_8PIN_SERIES)
#undef EZ8_NVDS
#endif

#if defined(_Z8F648)
#define EZ8_DUAL_ESPI
#define EZ8_DUAL_ESPI_ESPI1
#define EZ8_UART1
#define EZ8_DUAL_CMP
#define EZ8_DUAL_CMP_CMP1
#define EZ8_ADC_NEWER
#define EZ8_DAC
#define EZ8_MCT
#define EZ8_RTC
#define EZ8_USB
#define EZ8_CLKCTL
#define EZ8_OP_AMPS_AB
#define EZ8_OP_AMPS_AB_AMP_B
#define EZ8_EVENT_SYS
#define EZ8_DMA_NEW
#define EZ8_LCD
#define EZ8_AES
#define EZ8_IRQ4
#define EZ8_PORT5
#endif

#if defined (_Z8F3224)
#define EZ8_TIMER3
#define EZ8_UART
#define EZ8_DUAL_CMP
#define EZ8_DUAL_CMP_CMP1
#define EZ8_I2C
#define EZ8_ADC_NEWER
#define EZ8_ESPI
#define EZ8_TIMERA
#define EZ8_MCT
#define EZ8_REF
#define EZ8_CLKCTL
#define EZ8_OP_AMPS_A0_A1
#define EZ8_EVENT_SYS
#define EZ8_IRQ4
#define EZ8_PORT4
#define EZ8_PORT5
#endif

#if defined(_Z8F3224)
#undef EZ8_UART0
#endif

#if defined(_Z8FXX24xK) || defined (_Z8FXX24xH)
#undef EZ8_MCT
#undef EZ8_PORT5
#endif

#if defined (_Z8FXX24xH)
#define EZ8_NO_PORT3
#endif

#if (!defined(_Z8F6482XR)) && (!defined(_Z8F6482XT)) && (!defined(_Z8F6082XR)) && (!defined(_Z8F6082XT)) \
 && (!defined(_Z8F3282XR)) && (!defined(_Z8F3282XT)) && (!defined(_Z8F1682XR)) && (!defined(_Z8F1682XT))
// Part is an FXX81 MCU: no LCD
#undef EZ8_LCD
#else
// Part is an FXX82 MCU: has Ports H & J
#define EZ8_PORT9
#endif

#if defined(_Z8F6482XR) || defined(_Z8F6082XR) || defined(_Z8F3282XR) || defined(_Z8F1682XR) \
 || defined(_Z8F6481XK) || defined(_Z8F6081XK) || defined(_Z8F3281XK) || defined(_Z8F1681XK) \
 || defined(_Z8F1681xK_2247)
// These F6482 variants have several omitted peripherals in common
#undef EZ8_UART1
#undef EZ8_MCT
#undef EZ8_DUAL_CMP_CMP1
#undef EZ8_OP_AMPS_AB_AMP_B
#endif

#if defined(_Z8F6482XR) || defined(_Z8F6082XR) || defined(_Z8F3282XR) || defined(_Z8F1682XR)
// These F6482 variants have no USB support
#undef EZ8_USB
#endif

#if defined(_Z8F6481XN) || defined(_Z8F6081XN) || defined(_Z8F3281XN) || defined(_Z8F1681XN) \
 || defined(_Z8F6481XK) || defined(_Z8F6081XK) || defined(_Z8F3281XK) || defined(_Z8F1681XK) \
 || defined(_Z8F1681xN_2247) || defined(_Z8F6481xN_2247) || defined(_Z8F1681xK_2247)
// These F6482 variants have no 2nd ESPI controller
#undef EZ8_DUAL_ESPI_ESPI1
#endif

#if defined(_Z8F6481XR) || defined(_Z8F6081XR) || defined(_Z8F3281XR) || defined(_Z8F1681XR)
// Have Ports F & G
#define EZ8_PORT7
#endif

#if defined(_Z8F6482XR) || defined(_Z8F6082XR) || defined(_Z8F3282XR) || defined(_Z8F1682XR)
// Have NO Port E, although they do have Ports F through J!
#define EZ8_NO_PORT5
#endif

// This setting for EZ8_NVDS must come last so that NVDS will now be
// available for all parts with 8K of flash or more
#if (defined(ENCORE_HAS_MIN_8K)) && (__ZDATE__ > 20190101) && !defined(_LEGACY_NVDS_)
#define EZ8_NVDS
#endif

/*      Interrupt vectors */
#if defined(ENCORE_VECTORS)
#define  RESET     0
#define  WDT       1
#define  TRAP      2

#if defined(EZ8_TIMER3)
#define  TIMER2    3
#endif

#define  TIMER1    4
#define  TIMER0    5

#if defined(EZ8_UART0)
#define  UART0_RX  6
#define  UART0_TX  7
#endif

#if defined(EZ8_I2C)
#define  I2C       8
#endif

#if defined(EZ8_SPI)
#define  SPI       9
#endif

#if  defined(EZ8_ADC)
#define  ADC       10
#endif

#define  P7AD      11
#define  P6AD      12
#define  P5AD      13
#define  P4AD      14
#define  P3AD      15
#define  P2AD      16
#define  P1AD      17
#define  P0AD      18

#if defined(EZ8_TIMER4)
#define  TIMER3    19
#endif

#if defined(EZ8_UART1)
#define  UART1_RX  20
#define  UART1_TX  21
#endif

#if defined(EZ8_DMA)
#define  DMA       22
#endif


#if !defined(EZ8_PORT1)
#define  C3        23
#define  C2        24
#define  C1        25
#define  C0        26
#endif

#endif


#if defined(ENCORE_XP_VECTORS)
#define  RESET     0
#define  WDT       1
#define  TRAP      2

#if defined(EZ8_TIMER3)
#define  TIMER2    3
#endif

#define  TIMER1    4
#define  TIMER0    5

#if defined(EZ8_UART0)
#define  UART0_RX  6
#define  UART0_TX  7
#endif

#if defined(EZ8_I2C)
#define  I2C       8
#endif

#if defined(EZ8_SPI)
#define  SPI       9
#endif

#if  defined(EZ8_ADC) || defined(EZ8_ADC_NEW)
#define  ADC       10
#endif

#define  P7AD      11
#define  P6AD      12
#define  P5AD      13
#define  P4AD      14
#define  P3AD      15
#define  P2AD      16
#define  P1AD      17
#define  P0AD      18

#if defined(EZ8_TIMER4)
#define  TIMER3    19
#endif

#if defined(EZ8_UART1)
#define  UART1_RX  20
#define  UART1_TX  21
#endif

#if defined(EZ8_DMA)
#define  DMA       22
#endif

#if !defined(EZ8_PORT1)
#define  C3        23
#define  C2        24
#define  C1        25
#define  C0        26
#endif

#define  POTRAP    28
#define  WOTRAP    29
#endif


#if defined(ENCORE_XP16K_VECTORS)
#define  RESET     0
#define  WDT       1
#define  TRAP      2

#if defined(EZ8_TIMER3)
#define  TIMER2    3
#endif

#define  TIMER1    4
#define  TIMER0    5

#if defined(EZ8_UART0)
#define  UART0_RX  6
#define  UART0_TX  7
#endif

#if defined(EZ8_I2C)
#define  I2C       8
#endif

#if defined(EZ8_ESPI)
#define  SPI       9
#endif

#if  defined(EZ8_ADC_NEW)
#define  ADC       10
#endif

#define  P7AD      11
#define  P6AD      12
#define  P5AD      13
#define  P4AD      14
#define  P3AD      15
#define  P2AD      16
#define  P1AD      17
#define  P0AD      18

#if defined(EZ8_MCT)
#define  MCT       20
#endif

#if defined(EZ8_UART1)
#define  UART1_RX  21
#define  UART1_TX  22
#endif

#define  C3        23
#define  C2        24
#define  C1        25
#define  C0        26
#define  POTRAP    28
#define  WOTRAP    29
#endif


#if defined(ENCORE_MC_VECTORS)
#define  RESET     0
#define  WDT       1
#define  TRAP      2
#define  PWMTIMER  3
#define  PWMFAULT  4

#if defined(EZ8_ADC_NEW)
#define  ADC       5
#endif

#define  CMP       6
#define  TIMER0    7

#if defined(EZ8_UART0)
#define  UART0_RX  8
#define  UART0_TX  9
#endif

#if defined(EZ8_SPI)
#define  SPI       10
#endif

#if defined(EZ8_I2C)
#define  I2C       11
#endif

#define  C0        13
#define  PB        14
#define  P7A       15
#define  P3A       15
#define  P6A       16
#define  P2A       16
#define  P5A       17
#define  P1A       17
#define  P4A       18
#define  P0A       18
#define  POTRAP    28
#define  WOTRAP    29
#endif 

#if defined(ENCORE_F6482_VECTORS)
#define  RESET     0
#define  WDT       1
#define  TRAP      2

#if defined(EZ8_TIMER3)
#define  TIMER2    3
#endif

#define  TIMER1    4
#define  TIMER0    5

#if defined(EZ8_UART0)
#define  UART0_RX  6
#define  UART0_TX  7
#elif defined(EZ8_UART)
#define  UART_RX  6
#define  UART_TX  7
#endif

#if defined(EZ8_USB)
#define USB		   8
#define USB_HOST   9
#endif

#if defined(EZ8_I2C)
#define  I2C       10
#endif

#if defined(EZ8_DUAL_ESPI)  && defined(EZ8_DUAL_ESPI_ESPI1)
#define  SPI1      11
#endif

#if  defined(EZ8_DAC)
#define  DAC       12
#endif

#if defined(EZ8_DMA_NEW)
#define  DMA1      13
#define  DMA0      14
#endif

#if defined(EZ8_ADC_NEWER)
#define  ADC       15
#endif

#if defined(EZ8_DUAL_ESPI)
#define  SPI0      16
#elif defined(EZ8_ESPI)
#define  SPI       16
#endif

#if defined(EZ8_LCD)
#define  LCD       17
#endif

#if defined(EZ8_RTC)
#define  RTC       18
#endif

#define  P7AD      19
#define  P6AD      20
#define  P5AD      21
#define  P4AD      22
#define  P3AD      23
#define  P2AD      24
#define  P1AD      25
#define  P0AD      26

#if defined(EZ8_AES)
#define  AES       27
#endif

#if defined(EZ8_TIMERA)
#define  TIMERA   27
#endif

#if defined(EZ8_MCT)
#define  MCT       28
#endif

#if defined(EZ8_UART1)
#define  UART1_RX  29
#define  UART1_TX  30
#endif

#if (!defined(_Z8FXX24xH))
#define  C3        31
#define  C2        32
#define  C1        33
#define  C0        34
#endif

#define  SCLKTRAP  35

#if (!defined(_Z8F3224))
#define  WOTRAP    36
#endif
#endif /* ENCORE_F6482_VECTORS */


/* For ZSL */

#ifdef EZ8_UART0
#define UART0_RX_IVECT			UART0_RX
#define UART0_TX_IVECT			UART0_TX
#endif

#ifdef EZ8_UART1						
#define UART1_RX_IVECT			UART1_RX
#define UART1_TX_IVECT			UART1_TX
#endif

#define PA7_IVECT			PAD7_IVECT
#define PA6_IVECT			PAD6_IVECT
#define PA5_IVECT			PAD5_IVECT
#define PA4_IVECT			PAD4_IVECT
#define PA3_IVECT			PAD3_IVECT
#define PA2_IVECT			PAD2_IVECT
#define PA1_IVECT			PAD1_IVECT
#define PA0_IVECT			PAD0_IVECT
							
#define PD7_IVECT			PAD7_IVECT
#define PD6_IVECT			PAD6_IVECT
#define PD5_IVECT			PAD5_IVECT
#define PD4_IVECT			PAD4_IVECT
#define PD3_IVECT			PAD3_IVECT
#define PD2_IVECT			PAD2_IVECT
#define PD1_IVECT			PAD1_IVECT
#define PD0_IVECT			PAD0_IVECT

#define PAD7_IVECT			P7AD
#define PAD6_IVECT			P6AD
#define PAD5_IVECT			P5AD
#define PAD4_IVECT			P4AD
#define PAD3_IVECT			P3AD
#define PAD2_IVECT			P2AD
#define PAD1_IVECT			P1AD
#define PAD0_IVECT			P0AD

#ifndef EZ8_PORT1
#define PC3_IVECT			C3
#define PC2_IVECT			C2
#define PC1_IVECT			C1
#define PC0_IVECT			C0
#endif

/*      Special Function Registers */
#define T0      (*(unsigned int volatile far*)0xF00)               // Reset = 0x0000 Timer 0
#define T0H     (*(unsigned char volatile far*)0xF00)              // Reset = 0x00 Timer 0 High
#define T0L     (*(unsigned char volatile far*)0xF01)              // Reset = 0x01 Timer 0 Low
#define T0CP    (*(unsigned int volatile far*)0xF02)               // Reset = 0xFFFF Timer 0 Compare
#define T0CPH   (*(unsigned char volatile far*)0xF02)              // Reset = 0xFF Timer 0 Compare High
#define T0R     (*(unsigned int volatile far*)0xF02)               // Reset = 0xFFFF Timer 0 Compare
#define T0RH    (*(unsigned char volatile far*)0xF02)              // Reset = 0xFF Timer 0 Compare High
#define T0CPL   (*(unsigned char volatile far*)0xF03)              // Reset = 0xFF Timer 0 Compare Low
#define T0RL    (*(unsigned char volatile far*)0xF03)              // Reset = 0xFF Timer 0 Compare Low
#if defined(_Z8F1680_OR_Z8F648_OR_Z8F3224)
#define T0PWM0  (*(unsigned int volatile far*)0xF04)               // Reset = 0x0000 Timer 0 PWM0
#define T0PWM0H (*(unsigned char volatile far*)0xF04)              // Reset = 0x00 Timer 0 PWM0 High
#define T0PWM0L (*(unsigned char volatile far*)0xF05)              // Reset = 0x00 Timer 0 PMW0 Low
#else
#define T0PWM   (*(unsigned int volatile far*)0xF04)               // Reset = 0x0000 Timer 0 PWM
#define T0PWMH  (*(unsigned char volatile far*)0xF04)              // Reset = 0x00 Timer 0 PWM High
#define T0PWML  (*(unsigned char volatile far*)0xF05)              // Reset = 0x00 Timer 0 PMW Low
#endif

#if defined(_Z8F642) || defined(_Z8F04A) || defined(_Z8F08) || defined(_Z8F04) || defined(_Z8FMC16) || defined(_Z8F1680_OR_Z8F648_OR_Z8F3224)
#define T0CTL0  (*(unsigned char volatile far*)0xF06)              // Reset = 0x00 Timer 0 Control 0
#define T0CTL1  (*(unsigned char volatile far*)0xF07)              // Reset = 0x00 Timer 0 Control 1
#endif
#define T0CTL   (*(unsigned char volatile far*)0xF07)              // Reset = 0x00 Timer 0 Control

#if defined(_Z8FMC16)
#define ADCTCAP   (*(unsigned int volatile far*)0xF08)             // Reset = 0xXX Timer 0 Capture Register
#define ADCTCAP_H (*(unsigned char volatile far*)0xF08)            // Reset = 0xXX Timer 0 Capture Register High Byte
#define ADCTCAP_L (*(unsigned char volatile far*)0xF09)            // Reset = 0x00 Timer 0 Capture Register Low Byte
#endif

#if defined(_Z8F1680_OR_Z8F648_OR_Z8F3224)
#define T0PWM1  (*(unsigned int volatile far*)0xF20)               // Reset = 0x0000 Timer 0 PWM1
#define T0PWM1H (*(unsigned char volatile far*)0xF20)              // Reset = 0x00 Timer 0 PWM1 High
#define T0PWM1L (*(unsigned char volatile far*)0xF21)              // Reset = 0x00 Timer 0 PMW1 Low
#define T0CTL2  (*(unsigned char volatile far*)0xF22)              // Reset = 0x00 Timer 0 Control 2
#define T0STA   (*(unsigned char volatile far*)0xF23)              // Reset = 0x00 Timer 0 Status
#define T0NFC  (*(unsigned char volatile far*)0xF2C)               // Reset = 0x00 Timer 0 Noise Filter Control
#endif

#ifdef EZ8_TIMER2
#define T1      (*(unsigned int volatile far*)0xF08)               // Reset = 0x0000 Timer 1
#define T1H     (*(unsigned char volatile far*)0xF08)              // Reset = 0x00 Timer 1 High
#define T1L     (*(unsigned char volatile far*)0xF09)              // Reset = 0x01 Timer 1 Low
#define T1CP    (*(unsigned int volatile far*)0xF0A)               // Reset = 0xFFFF Timer 1 Compare
#define T1CPH   (*(unsigned char volatile far*)0xF0A)              // Reset = 0xFF Timer 1 Compare High
#define T1R     (*(unsigned int volatile far*)0xF0A)               // Reset = 0xFFFF Timer 1 Compare
#define T1RH    (*(unsigned char volatile far*)0xF0A)              // Reset = 0xFF Timer 1 Compare High
#define T1CPL   (*(unsigned char volatile far*)0xF0B)              // Reset = 0xFF Timer 1 Compare Low
#define T1RL    (*(unsigned char volatile far*)0xF0B)              // Reset = 0xFF Timer 1 Compare Low
#if defined(_Z8F1680_OR_Z8F648_OR_Z8F3224)
#define T1PWM0  (*(unsigned int volatile far*)0xF0C)               // Reset = 0x0000 Timer 1 PWM0
#define T1PWM0H (*(unsigned char volatile far*)0xF0C)              // Reset = 0x00 Timer 1 PWM0 High
#define T1PWM0L (*(unsigned char volatile far*)0xF0D)              // Reset = 0x00 Timer 1 PWM0 Low
#else
#define T1PWM   (*(unsigned int volatile far*)0xF0C)               // Reset = 0x0000 Timer 1 PWM
#define T1PWMH  (*(unsigned char volatile far*)0xF0C)              // Reset = 0x00 Timer 1 PWM High
#define T1PWML  (*(unsigned char volatile far*)0xF0D)              // Reset = 0x00 Timer 1 PWM Low
#endif
#if defined(_Z8F642) || defined(_Z8F04A) || defined(_Z8F08) || defined(_Z8F04) || defined(_Z8F1680_OR_Z8F648_OR_Z8F3224)
#define T1CTL0  (*(unsigned char volatile far*)0xF0E)              // Reset = 0x00 Timer 1 Control 0
#define T1CTL1  (*(unsigned char volatile far*)0xF0F)              // Reset = 0x00 Timer 1 Control 1
#endif
#define T1CTL   (*(unsigned char volatile far*)0xF0F)              // Reset = 0x00 Timer 1 Control
#if defined(_Z8F1680_OR_Z8F648_OR_Z8F3224)
#define T1PWM1  (*(unsigned int volatile far*)0xF24)               // Reset = 0x0000 Timer 1 PWM1
#define T1PWM1H (*(unsigned char volatile far*)0xF24)              // Reset = 0x00 Timer 1 PWM1 High
#define T1PWM1L (*(unsigned char volatile far*)0xF25)              // Reset = 0x00 Timer 1 PMW1 Low
#define T1CTL2  (*(unsigned char volatile far*)0xF26)              // Reset = 0x00 Timer 1 Control 2
#define T1STA   (*(unsigned char volatile far*)0xF27)              // Reset = 0x00 Timer 1 Status
#define T1NFC  (*(unsigned char volatile far*)0xF2D)               // Reset = 0x00 Timer 1 Noise Filter Control
#endif
#endif

#ifdef EZ8_TIMER3
#define T2      (*(unsigned int volatile far*)0xF10)               // Reset = 0x0000 Timer 2
#define T2H     (*(unsigned char volatile far*)0xF10)              // Reset = 0x00 Timer 2 High
#define T2L     (*(unsigned char volatile far*)0xF11)              // Reset = 0x01 Timer 2 Low
#define T2CP    (*(unsigned int volatile far*)0xF12)               // Reset = 0xFFFF Timer 2 Compare
#define T2CPH   (*(unsigned char volatile far*)0xF12)              // Reset = 0xFF Timer 2 Compare High
#define T2R     (*(unsigned int volatile far*)0xF12)               // Reset = 0xFFFF Timer 2 Compare
#define T2RH    (*(unsigned char volatile far*)0xF12)              // Reset = 0xFF Timer 2 Compare High
#define T2CPL   (*(unsigned char volatile far*)0xF13)              // Reset = 0xFF Timer 2 Compare Low
#define T2RL    (*(unsigned char volatile far*)0xF13)              // Reset = 0xFF Timer 2 Compare Low
#if defined(_Z8F1680_OR_Z8F648_OR_Z8F3224)
#define T2PWM0  (*(unsigned int volatile far*)0xF14)               // Reset = 0x0000 Timer 2 PWM0
#define T2PWM0H (*(unsigned char volatile far*)0xF14)              // Reset = 0x00 Timer 2 PWM0 High
#define T2PWM0L (*(unsigned char volatile far*)0xF15)              // Reset = 0x00 Timer 2 PWM0 Low
#else
#define T2PWM   (*(unsigned int volatile far*)0xF14)               // Reset = 0x0000 Timer 2 PWM
#define T2PWMH  (*(unsigned char volatile far*)0xF14)              // Reset = 0x00 Timer 2 PWM High
#define T2PWML  (*(unsigned char volatile far*)0xF15)              // Reset = 0x00 Timer 2 PWM Low
#endif
#if defined(_Z8F642) || defined(_Z8F1680_OR_Z8F648_OR_Z8F3224)
#define T2CTL0  (*(unsigned char volatile far*)0xF16)              // Reset = 0x00 Timer 2 Control 0
#define T2CTL1  (*(unsigned char volatile far*)0xF17)              // Reset = 0x00 Timer 2 Control 1
#endif
#define T2CTL   (*(unsigned char volatile far*)0xF17)              // Reset = 0x00 Timer 2 Control
#if defined(_Z8F1680_OR_Z8F648_OR_Z8F3224)
#define T2PWM1  (*(unsigned int volatile far*)0xF28)               // Reset = 0x0000 Timer 2 PWM1
#define T2PWM1H (*(unsigned char volatile far*)0xF28)              // Reset = 0x00 Timer 2 PWM1 High
#define T2PWM1L (*(unsigned char volatile far*)0xF29)              // Reset = 0x00 Timer 2 PMW1 Low
#define T2CTL2  (*(unsigned char volatile far*)0xF2A)              // Reset = 0x00 Timer 2 Control 2
#define T2STA   (*(unsigned char volatile far*)0xF2B)              // Reset = 0x00 Timer 2 Status
#define T2NFC  (*(unsigned char volatile far*)0xF2E)               // Reset = 0x00 Timer 2 Noise Filter Control
#endif
#endif

#ifdef EZ8_TIMER4
#define T3      (*(unsigned int volatile far*)0xF18)               // Reset = 0x0000 Timer 3
#define T3H     (*(unsigned char volatile far*)0xF18)              // Reset = 0x00 Timer 3 High
#define T3L     (*(unsigned char volatile far*)0xF19)              // Reset = 0x01 Timer 3 Low
#define T3CP    (*(unsigned int volatile far*)0xF1A)               // Reset = 0xFFFF Timer 3 Compare
#define T3CPH   (*(unsigned char volatile far*)0xF1A)              // Reset = 0xFF Timer 3 Compare High
#define T3R     (*(unsigned int volatile far*)0xF1A)               // Reset = 0xFFFF Timer 3 Compare
#define T3RH    (*(unsigned char volatile far*)0xF1A)              // Reset = 0xFF Timer 3 Compare High
#define T3CPL   (*(unsigned char volatile far*)0xF1B)              // Reset = 0xFF Timer 3 Compare Low
#define T3RL    (*(unsigned char volatile far*)0xF1B)              // Reset = 0xFF Timer 3 Compare Low
#define T3PWM   (*(unsigned int volatile far*)0xF1C)               // Reset = 0x0000 Timer 3 PWM
#define T3PWMH  (*(unsigned char volatile far*)0xF1C)              // Reset = 0x00 Timer 3 PWM High
#define T3PWML  (*(unsigned char volatile far*)0xF1D)              // Reset = 0x00 Timer 3 PWM Low
#ifdef _Z8F642
#define T3CTL0  (*(unsigned char volatile far*)0xF1E)              // Reset = 0x00 Timer 3 Control 0
#define T3CTL1  (*(unsigned char volatile far*)0xF1F)              // Reset = 0x00 Timer 3 Control 1
#endif
#define T3CTL   (*(unsigned char volatile far*)0xF1F)              // Reset = 0x00 Timer 3 Control
#endif  /* EZ8_TIMER4 */

#ifdef EZ8_PWM
#define PWMCTL0  (*(unsigned char volatile far*)0xF20)              // Reset = 0x00 PWM Control 0
#define PWMCTL1  (*(unsigned char volatile far*)0xF21)              // Reset = 0x00 PWM Control 1
#define PWMDB    (*(unsigned char volatile far*)0xF22)              // Reset = 0x00 PWM Dead Band
#define PWMMPF   (*(unsigned char volatile far*)0xF23)              // Reset = 0x00 PWM Min Pulse Width Filter
#define PWMFM    (*(unsigned char volatile far*)0xF24)              // Reset = 0x00 PWM Fault Mask
#define PWMFSTAT (*(unsigned char volatile far*)0xF25)              // Reset = 0x00 PWM Fault Status
#define PWMIN    (*(unsigned char volatile far*)0xF26)              // Reset = 0x00 PWM Input Sample
#define PWMOUT   (*(unsigned char volatile far*)0xF27)              // Reset = 0x00 PWM Output Control
#define PWMFCTL  (*(unsigned char volatile far*)0xF28)              // Reset = 0x00 PWM Fault Control
#define CSSHR    (*(unsigned char volatile far*)0xF29)              // Reset = 0x00 PWM Current-Sense Sample & Hold
#define PWMSHC   (*(unsigned char volatile far*)0xF29)              // Reset = 0x00 PWM Current-Sense ADC Trigger Control
#define PWM      (*(unsigned int volatile far*)0xF2C)               // Reset = 0xXXXX PWM
#define PWMH     (*(unsigned char volatile far*)0xF2C)              // Reset = 0xXX PWM High Byte 
#define PWML     (*(unsigned char volatile far*)0xF2D)              // Reset = 0xXX PWM Low Byte
#define PWMR     (*(unsigned int volatile far*)0xF2E)               // Reset = 0xFFFF PWM Reload
#define PWMRH    (*(unsigned char volatile far*)0xF2E)              // Reset = 0xFF PWM Reload High
#define PWMRL    (*(unsigned char volatile far*)0xF2F)              // Reset = 0xFF PWM Reload Low
#define PWMH0D   (*(unsigned int volatile far*)0xF30)               // Reset = 0x0000 PWM0 High Side Duty Cycle
#define PWMH0DH  (*(unsigned char volatile far*)0xF30)              // Reset = 0x00 PWM0 High Side Duty Cycle Hi Byte
#define PWMH0DL  (*(unsigned char volatile far*)0xF31)              // Reset = 0x00 PWM0 High Side Duty Cycle Lo Byte
#define PWML0D   (*(unsigned int volatile far*)0xF32)               // Reset = 0x0000 PWM0 Low Side Duty Cycle
#define PWML0DH  (*(unsigned char volatile far*)0xF32)              // Reset = 0x00 PWM0 Low Side Duty Cycle Hi Byte
#define PWML0DL  (*(unsigned char volatile far*)0xF33)              // Reset = 0x00 PWM0 Low Side Duty Cycle Lo Byte
#define PWMH1D   (*(unsigned int volatile far*)0xF34)               // Reset = 0x0000 PWM1 High Side Duty Cycle
#define PWMH1DH  (*(unsigned char volatile far*)0xF34)              // Reset = 0x00 PWM1 High Side Duty Cycle Hi Byte
#define PWMH1DL  (*(unsigned char volatile far*)0xF35)              // Reset = 0x00 PWM1 High Side Duty Cycle Lo Byte
#define PWML1D   (*(unsigned int volatile far*)0xF36)               // Reset = 0x0000 PWM1 Low Side Duty Cycle
#define PWML1DH  (*(unsigned char volatile far*)0xF36)              // Reset = 0x00 PWM1 Low Side Duty Cycle Hi Byte
#define PWML1DL  (*(unsigned char volatile far*)0xF37)              // Reset = 0x00 PWM1 Low Side Duty Cycle Lo Byte
#define PWMH2D   (*(unsigned int volatile far*)0xF38)               // Reset = 0x0000 PWM2 High Side Duty Cycle
#define PWMH2DH  (*(unsigned char volatile far*)0xF38)              // Reset = 0x00 PWM2 High Side Duty Cycle Hi Byte
#define PWMH2DL  (*(unsigned char volatile far*)0xF39)              // Reset = 0x00 PWM2 High Side Duty Cycle Lo Byte
#define PWML2D   (*(unsigned int volatile far*)0xF3A)               // Reset = 0x0000 PWM2 Low Side Duty Cycle
#define PWML2DH  (*(unsigned char volatile far*)0xF3A)              // Reset = 0x00 PWM2 Low Side Duty Cycle Hi Byte
#define PWML2DL  (*(unsigned char volatile far*)0xF3B)              // Reset = 0x00 PWM2 Low Side Duty Cycle Lo Byte
#endif

#ifdef EZ8_TIMERA
#define TA      (*(unsigned int volatile far*)0xF30)               // Reset = 0x0000 Timer A
#define TAH     (*(unsigned char volatile far*)0xF30)              // Reset = 0x00 Timer A High
#define TAL     (*(unsigned char volatile far*)0xF31)              // Reset = 0x00 Timer A Low
#define TAR     (*(unsigned int volatile far*)0xF32)               // Reset = 0xFFFF Timer A Reload
#define TARH    (*(unsigned char volatile far*)0xF32)              // Reset = 0xFF Timer A Reload High
#define TARL    (*(unsigned char volatile far*)0xF33)              // Reset = 0xFF Timer A Reload Low
#define TACTL   (*(unsigned char volatile far*)0xF34)              // Reset = 0x00 Timer A Control
#define TAPS    (*(unsigned char volatile far*)0xF35)              // Reset = 0x00 Timer A Prescale
#endif

#ifdef EZ8_UART0
#define U0D     (*(unsigned char volatile far*)0xF40)              // Reset = 0xXX UART0 Data
#define U0TXD   (*(unsigned char volatile far*)0xF40)              // Reset = 0xXX UART0 Data
#define U0RXD   (*(unsigned char volatile far*)0xF40)              // Reset = 0xXX UART0 Data
#define U0STAT0 (*(unsigned char volatile far*)0xF41)              // Reset = 0x0X UART0 Status 0
#define U0CTL0  (*(unsigned char volatile far*)0xF42)              // Reset = 0x00 UART0 Control 0
#define U0CTL1  (*(unsigned char volatile far*)0xF43)              // Reset = 0x00 UART0 Control 1
#if defined(_Z8FMC16) || defined(_Z8F1680_OR_Z8F648)
#define U0MDSTAT (*(unsigned char volatile far*)0xF44)             // Reset = 0x00 UART0 Mode Select and Status
#else
#define U0STAT1 (*(unsigned char volatile far*)0xF44)              // Reset = 0x00 UART0 Status 1
#endif
#if  defined(_Z8F642) || defined(_Z8F04A) || defined(_Z8F08) || defined(_Z8F04) || defined(_Z8FMC16) || defined(_Z8F1680_OR_Z8F648)
#define U0ADDR  (*(unsigned char volatile far*)0xF45)              // Reset = 0x00 UART0 Address Compare Register
#endif
#define U0BR    (*(unsigned int volatile far*)0xF46)               // Reset = 0xFFFF UARTO Baud Rate
#define U0BRH   (*(unsigned char volatile far*)0xF46)              // Reset = 0xFF UARTO Baud Rate High
#define U0BRL   (*(unsigned char volatile far*)0xF47)              // Reset = 0xFF UARTO Baud Rate Low
#endif

#ifdef EZ8_UART
#define UD     (*(unsigned char volatile far*)0xF40)              // Reset = 0xXX UART Data
#define UTXD   (*(unsigned char volatile far*)0xF40)              // Reset = 0xXX UART Data
#define URXD   (*(unsigned char volatile far*)0xF40)              // Reset = 0xXX UART Data
#define USTAT0 (*(unsigned char volatile far*)0xF41)              // Reset = 0x0X UART Status 0
#define UCTL0  (*(unsigned char volatile far*)0xF42)              // Reset = 0x00 UART Control 0
#define UCTL1  (*(unsigned char volatile far*)0xF43)              // Reset = 0x00 UART Control 1
#define UMDSTAT (*(unsigned char volatile far*)0xF44)             // Reset = 0x00 UART Mode Select and Status
#define UADDR  (*(unsigned char volatile far*)0xF45)              // Reset = 0x00 UART Address Compare Register
#define UBR    (*(unsigned int volatile far*)0xF46)               // Reset = 0xFFFF UART Baud Rate
#define UBRH   (*(unsigned char volatile far*)0xF46)              // Reset = 0xFF UART Baud Rate High
#define UBRL   (*(unsigned char volatile far*)0xF47)              // Reset = 0xFF UART Baud Rate Low
#endif

#ifdef EZ8_UART1
#define U1D     (*(unsigned char volatile far*)0xF48)              // Reset = 0xXX UART 1 Data
#define U1TXD   (*(unsigned char volatile far*)0xF48)              // Reset = 0xXX UART 1 Data
#define U1RXD   (*(unsigned char volatile far*)0xF48)              // Reset = 0xXX UART 1 Data
#define U1STAT0 (*(unsigned char volatile far*)0xF49)              // Reset = 0x0X UART1 Status 0  		(depends on family)
#define U1CTL0  (*(unsigned char volatile far*)0xF4A)              // Reset = 0x00 UART1 Control 0
#define U1CTL1  (*(unsigned char volatile far*)0xF4B)              // Reset = 0x00 UART1 Control 1
#if defined(_Z8F1680_OR_Z8F648)
#define U1MDSTAT (*(unsigned char volatile far*)0xF4C)             // Reset = 0x00 UART1 Mode Select and Status
#else
#define U1STAT1 (*(unsigned char volatile far*)0xF4C)              // Reset = 0x00 UARR1 Status 1
#endif
#if defined(_Z8F642) || defined(_Z8F1680_OR_Z8F648)
#define U1ADDR  (*(unsigned char volatile far*)0xF4D)              // Reset = 0x00 UART1 Address Compare Register
#endif
#define U1BR    (*(unsigned int volatile far*)0xF4E)               // Reset = 0xFFFF UART1 Baud Rate
#define U1BRH   (*(unsigned char volatile far*)0xF4E)              // Reset = 0xFF UART1 Baud Rate High
#define U1BRL   (*(unsigned char volatile far*)0xF4F)              // Reset = 0xFF UART1 Baud Rate Low
#endif

#ifdef EZ8_I2C
#define I2CD    (*(unsigned char volatile far*)0xF50)              // Reset = 0x00 I2C Data
#define I2CDATA (*(unsigned char volatile far*)0xF50)              // Reset = 0x00 I2C Data
#if defined(_Z8FMC16) || defined(_Z8F1680_OR_Z8F648_OR_Z8F3224)
#define I2CISTAT (*(unsigned char volatile far*)0xF51)             // Reset = 0x80 I2C Interrupt Status
#else
#define I2CSTAT (*(unsigned char volatile far*)0xF51)              // Reset = 0x80 I2C Status
#endif
#define I2CCTL  (*(unsigned char volatile far*)0xF52)              // Reset = 0x00 I2C Control
#define I2CBR   (*(unsigned int volatile far*)0xF53)               // Reset = 0xFFFF I2C Baud Reload
#define I2CBRH  (*(unsigned char volatile far*)0xF53)              // Reset = 0xFF I2C Baud Reload High
#define I2CBRL  (*(unsigned char volatile far*)0xF54)              // Reset = 0xFF I2C Baud Reload Low

#if  defined(_Z8F642) || defined(_Z8F08)
#define I2CDST  (*(unsigned char volatile far*)0xF55)              // Reset = 0xC0 I2C Diagnostic State
#define I2CDIAG (*(unsigned char volatile far*)0xF56)              // Reset = 0x00 I2C Diagnostic
#endif

#if defined(_Z8FMC16) || defined(_Z8F1680_OR_Z8F648_OR_Z8F3224)
#define I2CSTATE (*(unsigned char volatile far*)0xF55)             // Reset = 0x00 I2C State Register
#define I2CMODE  (*(unsigned char volatile far*)0xF56)             // Reset = 0x00 I2C Mode Register
#define I2CSLVAD (*(unsigned char volatile far*)0xF57)             // Reset = 0x00 I2C Slave Address Register
#endif
#endif

#ifdef EZ8_SPI
#define SPID    (*(unsigned char volatile far*)0xF60)              // Reset = 0xXX SPI Data
#define SPIDATA (*(unsigned char volatile far*)0xF60)              // Reset = 0xXX SPI Data
#define SPICTL  (*(unsigned char volatile far*)0xF61)              // Reset = 0x00 SPI Control
#define SPISTAT (*(unsigned char volatile far*)0xF62)              // Reset = 0x00 SPI Status
#define SPSTAT  (*(unsigned char volatile far*)0xF62)              // Reset = 0x00 SPI Status
#define SPIMODE (*(unsigned char volatile far*)0xF63)              // Reset = 0x00 SPI Mode

#if defined(_Z8F642) || defined(_Z8F08) || defined(_Z8FMC16)
#define SPIDST  (*(unsigned char volatile far*)0xF64)              // Reset = 0x00 SPI Diagnostic State
#endif

#define SPIBR   (*(unsigned int volatile far*)0xF66)               // Reset = 0xFFFF SPI Baud Rate
#define SPIBRH  (*(unsigned char volatile far*)0xF66)              // Reset = 0xFF SPI Baud Rate High
#define SPIBRL  (*(unsigned char volatile far*)0xF67)              // Reset = 0xFF SPI Baud Rate Low
#endif

#ifdef EZ8_ESPI
#define ESPIDATA  (*(unsigned char volatile far*)0xF60)              // Reset = 0xXX ESPI Data
#define ESPITDCR  (*(unsigned char volatile far*)0xF61)              // Reset = 0x00 ESPI Transmit Data Command
#define ESPICTL   (*(unsigned char volatile far*)0xF62)              // Reset = 0x00 ESPI Control
#define ESPIMODE  (*(unsigned char volatile far*)0xF63)              // Reset = 0x00 ESPI Mode
#define ESPISTAT  (*(unsigned char volatile far*)0xF64)              // Reset = 0x81 ESPI Status
#define ESPISTATE (*(unsigned char volatile far*)0xF65)              // Reset = 0x00 ESPI State
#define ESPIBR    (*(unsigned int volatile far*)0xF66)               // Reset = 0xFFFF ESPI Baud Rate
#define ESPIBRH   (*(unsigned char volatile far*)0xF66)              // Reset = 0xFF ESPI Baud Rate High
#define ESPIBRL   (*(unsigned char volatile far*)0xF67)              // Reset = 0xFF ESPI Baud Rate Low
#endif

#ifdef EZ8_DUAL_ESPI
#define ESPI0DATA  (*(unsigned char volatile far*)0xF60)              // Reset = 0xXX ESPI 0 Data
#define ESPI0TDCR  (*(unsigned char volatile far*)0xF61)              // Reset = 0x00 ESPI 0 Transmit Data Command
#define ESPI0CTL   (*(unsigned char volatile far*)0xF62)              // Reset = 0x00 ESPI 0 Control
#define ESPI0MODE  (*(unsigned char volatile far*)0xF63)              // Reset = 0x00 ESPI 0 Mode
#define ESPI0STAT  (*(unsigned char volatile far*)0xF64)              // Reset = 0x81 ESPI 0 Status
#define ESPI0STATE (*(unsigned char volatile far*)0xF65)              // Reset = 0x00 ESPI 0 State
#define ESPI0BR    (*(unsigned int volatile far*)0xF66)               // Reset = 0xFFFF ESPI 0 Baud Rate
#define ESPI0BRH   (*(unsigned char volatile far*)0xF66)              // Reset = 0xFF ESPI 0 Baud Rate High
#define ESPI0BRL   (*(unsigned char volatile far*)0xF67)              // Reset = 0xFF ESPI 0 Baud Rate Low
#ifdef EZ8_DUAL_ESPI_ESPI1
#define ESPI1DATA  (*(unsigned char volatile far*)0xF68)              // Reset = 0xXX ESPI 1 Data
#define ESPI1TDCR  (*(unsigned char volatile far*)0xF69)              // Reset = 0x00 ESPI 1 Transmit Data Command
#define ESPI1CTL   (*(unsigned char volatile far*)0xF6A)              // Reset = 0x00 ESPI 1 Control
#define ESPI1MODE  (*(unsigned char volatile far*)0xF6B)              // Reset = 0x00 ESPI 1 Mode
#define ESPI1STAT  (*(unsigned char volatile far*)0xF6C)              // Reset = 0x81 ESPI 1 Status
#define ESPI1STATE (*(unsigned char volatile far*)0xF6D)              // Reset = 0x00 ESPI 1 State
#define ESPI1BR    (*(unsigned int volatile far*)0xF6E)               // Reset = 0xFFFF ESPI 1 Baud Rate
#define ESPI1BRH   (*(unsigned char volatile far*)0xF6E)              // Reset = 0xFF ESPI 1 Baud Rate High
#define ESPI1BRL   (*(unsigned char volatile far*)0xF6F)              // Reset = 0xFF ESPI 1 Baud Rate Low
#endif
#endif


#ifdef EZ8_ADC
#if defined(_Z8F04A) || defined(_Z8F04)
#define ADCCTL0 (*(unsigned char volatile far*)0xF70)              // Reset = 0x00 ADC Control 0
#define ADCCTL1 (*(unsigned char volatile far*)0xF71)              // Reset = 0x80 ADC Control 1
#else
#define ACTL    (*(unsigned char volatile far*)0xF70)              // Reset = 0x00 ADC Control
#define ADCCTL  (*(unsigned char volatile far*)0xF70)              // Reset = 0x00 ADC Control
#endif
#define ADHR    (*(unsigned char volatile far*)0xF72)              // Reset = 0xXX ADC Data High
#define ADCD    (*(unsigned int volatile far*)0xF72)               // Reset = 0xXXXX ADC Data
#define ADCD_H  (*(unsigned char volatile far*)0xF72)              // Reset = 0xXX ADC Data High
#define ADLR    (*(unsigned char volatile far*)0xF73)              // Reset = 0xXX ADC Data Low
#define ADCDL   (*(unsigned char volatile far*)0xF73)              // Reset = 0xXX ADC Data Low
#define ADCD_L  (*(unsigned char volatile far*)0xF73)              // Reset = 0xXX ADC Data Low

#if defined(_Z8F04A)
#define ADCTHH  (*(unsigned char volatile far*)0xF74)              // Reset = 0xFF ADC High Threshold High Byte
#define ADCTLH  (*(unsigned char volatile far*)0xF76)              // Reset = 0x00 ADC Low Threshold High Byte
#endif

#endif

#ifdef EZ8_ADC_NEW 
#define ADCCTL0 (*(unsigned char volatile far*)0xF70)              // Reset = 0x00 ADC Control 0
#if !defined(_Z8F0830A)
#define ADCRD_H (*(unsigned char volatile far*)0xF71)              // Reset = 0xXX ADC Raw Data High Byte
#endif
#define ADCD    (*(unsigned int volatile far*)0xF72)               // Reset = 0xXXXX ADC Data
#define ADCD_H  (*(unsigned char volatile far*)0xF72)              // Reset = 0xXX ADC Data High
#define ADCD_L  (*(unsigned char volatile far*)0xF73)              // Reset = 0xXX ADC Data Low
#define ADCSST  (*(unsigned char volatile far*)0xF74)              // Reset = 0x0A ADC Sample Settling Time
#define ADCST   (*(unsigned char volatile far*)0xF75)              // Reset = 0x14 ADC Sample Time
#if !defined(_Z8F0830S)
#define ADCCP   (*(unsigned char volatile far*)0xF76)              // Reset = 0x00 ADC Clock Prescale
#endif
#endif

#ifdef EZ8_ADC_NEWER
#define ADCCTL0		(*(unsigned char volatile far*)0xF70)			// Reset = 0x00 ADC Control 0
#define ADCCTL1		(*(unsigned char volatile far*)0xF71)			// Reset = 0x00 ADC Control 1
#define ADCCTL2		(*(unsigned char volatile far*)0xF72)			// Reset = 0x00 ADC Control 2
#define ADCINS		(*(unsigned int volatile far*)0xF73)			// Reset = 0x00 ADC Input Select
#define ADCINSH		(*(unsigned char volatile far*)0xF73)			// Reset = 0x00 ADC Input Select High
#define ADCINSL		(*(unsigned char volatile far*)0xF74)			// Reset = 0x00 ADC Input Select Low
#define ADCOFF		(*(unsigned char volatile far*)0xF75)			// Reset = 0x00 ADC Offset Calibration
#define ADCD		(*(unsigned int volatile far*)0xF76)			// Reset = 0x0000 ADC Data
#define ADCD_H		(*(unsigned char volatile far*)0xF76)			// Reset = 0x00 ADC Data High
#define ADCD_L		(*(unsigned char volatile far*)0xF77)			// Reset = 0x00 ADC Data Low
#define ADCST		(*(unsigned char volatile far*)0xF78)			// Reset = 0x00 ADC Sample Time
#define ADCUWIN		(*(unsigned int volatile far*)0xF79)			// Reset = 0xFFFF ADC Upper Window Threshold
#define ADCUWINH	(*(unsigned char volatile far*)0xF79)			// Reset = 0xFF ADC Upper Window Threshold High
#define ADCUWINL	(*(unsigned char volatile far*)0xF7A)			// Reset = 0xFF ADC Upper Window Threshold Low
#define ADCLWIN		(*(unsigned int volatile far*)0xF7B)			// Reset = 0x0000 ADC Lower Window Threshold
#define ADCLWINH	(*(unsigned char volatile far*)0xF7B)			// Reset = 0x00 ADC Lower Window Threshold High
#define ADCLWINL	(*(unsigned char volatile far*)0xF7C)			// Reset = 0x00 ADC Lower Window Threshold Low
#endif

#ifdef EZ8_DAC
#define DACCTL		(*(unsigned char volatile far*)0xF7D)			// Reset = 0x00 DAC Control 
#define DACD		(*(unsigned int volatile far*)0xF7E)			// Reset = 0x0000 DAC Data
#define DACD_H		(*(unsigned char volatile far*)0xF7E)			// Reset = 0x00 DAC DAta High
#define DACD_L		(*(unsigned char volatile far*)0xF7F)			// Reset = 0x00 DAC Data Low
#endif

#ifdef EZ8_REF
#define FREFCTL		(*(unsigned char volatile far*)0xF7D)			// Reset = 0x00 Fixed Reference Control 
#define PREF0CTL	(*(unsigned char volatile far*)0xF7E)			// Reset = 0x00 Programmable Reference 0 Control
#define PREF1CTL	(*(unsigned char volatile far*)0xF7F)			// Reset = 0x00 Programmable Reference 1 Control
#endif

#if defined(_Z8F04A) || defined(_Z8F04) || defined(_Z8F1680_OR_Z8F648_OR_Z8F3224) || defined(__ZSLBUILD)
#define PWRCTL0 (*(unsigned char volatile far*)0xF80)              // Reset = 0xXX Power Control 0
																   // (Reset depends on family)
#if defined(_Z8F648) || defined (_Z8F3224)
#define PWRCTL1 (*(unsigned char volatile far*)0xF81)              // Reset = 0x00 Power Control 1
#endif
#endif

#if defined(_Z8F04A) || defined(_Z8F04) || defined(_Z8F1680_OR_Z8F648) || defined(__ZSLBUILD)
#if (defined(_Z8F04A) && !defined(_Z8F04A_8PIN)) || (defined(_Z8F04) && !defined(_Z8F04_8PIN)) || defined(_Z8F1680) || defined(__ZSLBUILD)
#define LEDEN   (*(unsigned char volatile far*)0xF82)              // Reset = 0x00 LED Drive Enable
#define LEDLVL  (*(unsigned int volatile far*)0xF83)               // Reset = 0x0000 LED Drive Level
#define LEDLVLH (*(unsigned char volatile far*)0xF83)              // Reset = 0x00 LED Drive Level High Byte
#define LEDLVLL (*(unsigned char volatile far*)0xF84)              // Reset = 0x00 LED Drive Level Low Byte
#endif

#if defined(_Z8F1680)
#define OSCCTL0 (*(unsigned char volatile far*)0xF86)              // Reset = 0xA0 Oscillator Control 0
#define OSCCTL1 (*(unsigned char volatile far*)0xF87)              // Reset = 0x00 Oscillator Control 1
#else
#define OSCCTL  (*(unsigned char volatile far*)0xF86)              // Reset = 0x20 Oscillator Control
#endif

#if defined(_Z8F04A) || defined(_Z8F04) || defined(_Z8F1680)
#define CMP0    (*(unsigned char volatile far*)0xF90)              // Reset = 0x14 Comparator 0 Control
#endif

#ifdef EZ8_CMP1
#define CMP1    (*(unsigned char volatile far*)0xF91)              // Reset = 0x14 Comparator 1 Control
#endif
#endif

#ifdef EZ8_DUAL_CMP
// Dual Comparators
#define CMPCTL		(*(unsigned char volatile far*)0xF8F)			// Reset = 0x00 Comparator Control
#define CMP0CTL0	(*(unsigned char volatile far*)0xF90)			// Reset = 0x00 Comparator 0 Control 0
#define CMP0CTL1	(*(unsigned char volatile far*)0xF91)			// Reset = 0x05 Comparator 0 Control 1
#ifdef EZ8_DUAL_CMP_CMP1
#define CMP1CTL0	(*(unsigned char volatile far*)0xF92)			// Reset = 0x00 Comparator 1 Control 0 
#define CMP1CTL1	(*(unsigned char volatile far*)0xF93)			// Reset = 0x03 Comparator 1 Control 1
#endif
#endif

#if defined(_Z8FMC16)
#define OSCCTL  (*(unsigned char volatile far*)0xF86)              // Reset = 0x20 Oscillator Control
#define OSCDIV  (*(unsigned char volatile far*)0xF87)              // Reset = 0x00 Oscillator Divide
#define CMPOPC  (*(unsigned char volatile far*)0xF90)              // Reset = 0x00 Comparator and Opamp Control
#endif

#ifdef EZ8_MCT
#define MCTHL    (*(unsigned int volatile far*)0xFA0)               // Reset = 0x0000 MCT
#define MCTH     (*(unsigned char volatile far*)0xFA0)              // Reset = 0x00 MCT High
#define MCTL     (*(unsigned char volatile far*)0xFA1)              // Reset = 0x00 MCT Low
#define MCTR     (*(unsigned int volatile far*)0xFA2)               // Reset = 0xFFFF MCT Reload
#define MCTRH    (*(unsigned char volatile far*)0xFA2)              // Reset = 0xFF MCT Reload High
#define MCTRL    (*(unsigned char volatile far*)0xFA3)              // Reset = 0xFF MCT Reload Low
#define MCTSA    (*(unsigned char volatile far*)0xFA4)              // Reset = 0xXX MCT Sub Address
#define MCTSR0   (*(unsigned char volatile far*)0xFA5)              // Reset = 0xXX MCT Sub Register 0
#define MCTSR1   (*(unsigned char volatile far*)0xFA6)              // Reset = 0xXX MCT Sub Register 1
#define MCTSR2   (*(unsigned char volatile far*)0xFA7)              // Reset = 0xXX MCT Sub Register 2

#define __MCT_CONTROL             0x00
#define __MCT_CHANNEL_STATUS      0x01
#define __MCT_CHANNEL_A           0x02
#define __MCT_CHANNEL_B           0x03
#define __MCT_CHANNEL_C           0x04
#define __MCT_CHANNEL_D           0x05

#define MCTCTL0	  (((MCTSA) =          __MCT_CONTROL),((MCTSR0)))
#define MCTCTL1	  (((MCTSA) =          __MCT_CONTROL),((MCTSR1)))
#define MCTCHS0	  (((MCTSA) =   __MCT_CHANNEL_STATUS),((MCTSR0)))
#define MCTCHS1	  (((MCTSA) =   __MCT_CHANNEL_STATUS),((MCTSR1)))
#define MCTCHACTL (((MCTSA) =        __MCT_CHANNEL_A),((MCTSR2)))
#define MCTCHBCTL (((MCTSA) =        __MCT_CHANNEL_B),((MCTSR2)))
#define MCTCHCCTL (((MCTSA) =        __MCT_CHANNEL_C),((MCTSR2)))
#define MCTCHDCTL (((MCTSA) =        __MCT_CHANNEL_D),((MCTSR2)))
#define MCTCHAH   (((MCTSA) =        __MCT_CHANNEL_A),((MCTSR0)))
#define MCTCHBH   (((MCTSA) =        __MCT_CHANNEL_B),((MCTSR0)))
#define MCTCHCH   (((MCTSA) =        __MCT_CHANNEL_C),((MCTSR0)))
#define MCTCHDH   (((MCTSA) =        __MCT_CHANNEL_D),((MCTSR0)))
#define MCTCHAL   (((MCTSA) =        __MCT_CHANNEL_A),((MCTSR1)))
#define MCTCHBL   (((MCTSA) =        __MCT_CHANNEL_B),((MCTSR1)))
#define MCTCHCL   (((MCTSA) =        __MCT_CHANNEL_C),((MCTSR1)))
#define MCTCHDL   (((MCTSA) =        __MCT_CHANNEL_D),((MCTSR1)))

#endif

#ifdef EZ8_DMA
#define D0CTL     (*(unsigned char volatile far*)0xFB0)            // Reset = 0x00 DMA0 Control
#define DMA0CTL   (*(unsigned char volatile far*)0xFB0)            // Reset = 0x00 DMA0 Control
#define D0IO      (*(unsigned char volatile far*)0xFB1)            // Reset = 0xXX DMA0 I/O Address
#define DMA0IO    (*(unsigned char volatile far*)0xFB1)            // Reset = 0xXX DMA0 I/O Address
#define D0HIGH    (*(unsigned char volatile far*)0xFB2)            // Reset = 0xXX DMA0 End/Start Address High
#define DMA0H     (*(unsigned char volatile far*)0xFB2)            // Reset = 0xXX DMA0 End/Start Address High
#define D0START   (*(unsigned char volatile far*)0xFB3)            // Reset = 0xXX DMA0 Start Address Low
#define DMA0START (*(unsigned char volatile far*)0xFB3)            // Reset = 0xXX DMA0 Start Address Low
#define D0END     (*(unsigned char volatile far*)0xFB4)            // Reset = 0xXX DMA0 End Address Low
#define DMA0END   (*(unsigned char volatile far*)0xFB4)            // Reset = 0xXX DMA0 End Address Low

#define D1CTL     (*(unsigned char volatile far*)0xFB8)            // Reset = 0x00 DMA1 Control
#define DMA1CTL   (*(unsigned char volatile far*)0xFB8)            // Reset = 0x00 DMA1 Control
#define D1IO      (*(unsigned char volatile far*)0xFB9)            // Reset = 0xXX DMA1 I/O Address
#define DMA1IO    (*(unsigned char volatile far*)0xFB9)            // Reset = 0xXX DMA1 I/O Address
#define D1HIGH    (*(unsigned char volatile far*)0xFBA)            // Reset = 0xXX DMA1 End/Start Address High
#define DMA1H     (*(unsigned char volatile far*)0xFBA)            // Reset = 0xXX DMA1 End/Start Address High
#define D1START   (*(unsigned char volatile far*)0xFBB)            // Reset = 0xXX DMA1 Start Address Low
#define DMA1START (*(unsigned char volatile far*)0xFBB)            // Reset = 0xXX DMA1 Start Address Low
#define D1END     (*(unsigned char volatile far*)0xFBC)            // Reset = 0xXX DMA1 End Address Low
#define DMA1END   (*(unsigned char volatile far*)0xFBC)            // Reset = 0xXX DMA1 End Address Low

#define DAADDR    (*(unsigned char volatile far*)0xFBD)            // Reset = 0xXX ADC DMA Address
#define DMAA_ADDR (*(unsigned char volatile far*)0xFBD)            // Reset = 0xXX ADC DMA Address
#define DACTL     (*(unsigned char volatile far*)0xFBE)            // Reset = 0x00 ADC DMA Control
#define DMAACTL   (*(unsigned char volatile far*)0xFBE)            // Reset = 0x00 ADC DMA Control
#define DSTAT     (*(unsigned char volatile far*)0xFBF)            // Reset = 0x00 DMA Status
#define DMAASTAT  (*(unsigned char volatile far*)0xFBF)            // Reset = 0x00 DMA Status
#endif

#ifdef EZ8_DMA_NEW
#define DMA0SA		(*(unsigned char volatile far*)0xFA8)			// Reset = 0x00 DMA ch 0 Subregister Address
#define DMA0SD		(*(unsigned char volatile far*)0xFA9)			// Reset = 0x00 DMA ch 0 Subregister Data
#define DMA1SA		(*(unsigned char volatile far*)0xFAA)			// Reset = 0x00 DMA ch 1 Subregister Address
#define DMA1SD		(*(unsigned char volatile far*)0xFAB)			// Reset = 0x00 DMA ch 1 Subregister Data
#define DMA2SA		(*(unsigned char volatile far*)0xFAC)			// Reset = 0x00 DMA ch 2 Subregister Address
#define DMA2SD		(*(unsigned char volatile far*)0xFAD)			// Reset = 0x00 DMA ch 2 Subregister Data
#define DMA3SA		(*(unsigned char volatile far*)0xFAE)			// Reset = 0x00 DMA ch 3 Subregister Address
#define DMA3SD		(*(unsigned char volatile far*)0xFAF)			// Reset = 0x00 DMA ch 3 Subregister Data
#define DMACTL		(*(unsigned char volatile far*)0xFB0)			// Reset = 0x00 DMA Control Register

// The following definitions may be useful if the subregisters must be manipulated directly
#define __DMA_SOURCE_HIGH	0x00
#define __DMA_SOURCE_LOW	0x01
#define __DMA_DEST_HIGH		0x02
#define __DMA_DEST_LOW		0x03
#define __DMA_COUNT_HIGH	0x04
#define __DMA_COUNT_LOW		0x05
#define __DMA_CTRL_0		0x06
#define __DMA_CTRL_1		0x07
#define __DMA_LLA_HIGH		0x08
#define __DMA_LLA_LOW		0x09

// Due to the auto-incrementing through the subregisters in direct operation, and the implied incrementing
// by address in linked list operation,  software generally should not need to define the 40 DMA subregisters
// explicitly (4 channels times 10 subregisters per channel), except for the Linked List Address subregisters.
// Note that this rather elaborate form for accessing the LLA subregisters (or any others that the user decides
// to access directly for any reason) is compelled by the requirement not to overwrite the upper nibble of the
// DMAxSA register.  Compare this to the somewhat simpler form used for accessing MCT subregisters.
#define DMA0LAH		(((DMA0SA) = (((DMA0SA) & 0xF0) | __DMA_LLA_HIGH)),((DMA0SD)))
#define DMA0LAL		(((DMA0SA) = (((DMA0SA) & 0xF0) | __DMA_LLA_LOW)), ((DMA0SD)))
#define DMA1LAH		(((DMA1SA) = (((DMA1SA) & 0xF0) | __DMA_LLA_HIGH)),((DMA1SD)))
#define DMA1LAL		(((DMA1SA) = (((DMA1SA) & 0xF0) | __DMA_LLA_LOW)), ((DMA1SD)))
#define DMA2LAH		(((DMA2SA) = (((DMA2SA) & 0xF0) | __DMA_LLA_HIGH)),((DMA2SD)))
#define DMA2LAL		(((DMA2SA) = (((DMA2SA) & 0xF0) | __DMA_LLA_LOW)), ((DMA2SD)))
#define DMA3LAH		(((DMA3SA) = (((DMA3SA) & 0xF0) | __DMA_LLA_HIGH)),((DMA3SD)))
#define DMA3LAL		(((DMA3SA) = (((DMA3SA) & 0xF0) | __DMA_LLA_LOW)), ((DMA3SD)))

#endif	// EZ8_DMA_NEW


#define IRQ0    (*(unsigned char volatile far*)0xFC0)              // Reset = 0x00 Interrupt Request 0
#define IRQ0E0  (*(unsigned char volatile far*)0xFC1)              // Reset = 0x00 IRQ0 Enable 0
#define IRQ0EN  (*(unsigned int volatile far*)0xFC1)               // Reset = 0x0000 IRQ0 Enable
#define IRQ0ENH (*(unsigned char volatile far*)0xFC1)              // Reset = 0x00 IRQ0 Enable 0
#define IRQ0E1  (*(unsigned char volatile far*)0xFC2)              // Reset = 0x00 IRQ0 Enable 1
#define IRQ0ENL (*(unsigned char volatile far*)0xFC2)              // Reset = 0x00 IRQ0 Enable 1

#define IRQ1    (*(unsigned char volatile far*)0xFC3)              // Reset = 0x00 Interrupt Request 1
#define IRQ1E0  (*(unsigned char volatile far*)0xFC4)              // Reset = 0x00 IRQ1 Enable 0
#define IRQ1EN  (*(unsigned int volatile far*)0xFC4)               // Reset = 0x0000 IRQ1 Enable
#define IRQ1ENH (*(unsigned char volatile far*)0xFC4)              // Reset = 0x00 IRQ1 Enable 0
#define IRQ1E1  (*(unsigned char volatile far*)0xFC5)              // Reset = 0x00 IRQ1 Enable 1
#define IRQ1ENL (*(unsigned char volatile far*)0xFC5)              // Reset = 0x00 IRQ1 Enable 1

#ifdef EZ8_IRQ3
#define IRQ2    (*(unsigned char volatile far*)0xFC6)              // Reset = 0x00 Interrupt Request 2
#define IRQ2E0  (*(unsigned char volatile far*)0xFC7)              // Reset = 0x00 IRQ2 Enable 0
#define IRQ2EN  (*(unsigned int volatile far*)0xFC7)               // Reset = 0x0000 IRQ2 Enable
#define IRQ2ENH (*(unsigned char volatile far*)0xFC7)              // Reset = 0x00 IRQ2 Enable 0
#define IRQ2E1  (*(unsigned char volatile far*)0xFC8)              // Reset = 0xXX IRQ2 Enable 1
#define IRQ2ENL (*(unsigned char volatile far*)0xFC8)              // Reset = 0xXX IRQ2 Enable 1
#endif

#ifdef EZ8_IRQ4
#define IRQ3    (*(unsigned char volatile far*)0xFC9)              // Reset = 0x00 Interrupt Request 3
#define IRQ3E0  (*(unsigned char volatile far*)0xFCA)              // Reset = 0x00 IRQ3 Enable 0
#define IRQ3EN  (*(unsigned int volatile far*)0xFCA)               // Reset = 0x0000 IRQ3 Enable
#define IRQ3ENH (*(unsigned char volatile far*)0xFCA)              // Reset = 0x00 IRQ3 Enable 0
#define IRQ3E1  (*(unsigned char volatile far*)0xFCB)              // Reset = 0xXX IRQ3 Enable 1
#define IRQ3ENL (*(unsigned char volatile far*)0xFCB)              // Reset = 0xXX IRQ3 Enable 1
#endif

#if (!defined (_Z8FMC16) && !defined (_Z8F648) && !defined (_Z8F3224) )
#define IRQES   (*(unsigned char volatile far*)0xFCD)              // Reset = 0x00 Interrupt Edge Select
#endif

#if defined(_Z8F648) || defined(_Z8F3224)
#define IRQES   (*(unsigned char volatile far*)0xFCC)              // Reset = 0x00 Interrupt Edge Select
#endif

#if defined(_Z8F04A) || defined(_Z8F04) || defined(_Z8F1680) || defined(__ZSLBUILD)
#define IRQSS   (*(unsigned char volatile far*)0xFCE)              // Reset = 0x00 Shared Interrupt Select
#endif

#if defined(_Z8F648) || defined(_Z8F3224)
#define IRQSS0   (*(unsigned char volatile far*)0xFCD)              // Reset = 0x00 Shared Interrupt Select 0
#endif
#if defined(_Z8F648)
#define IRQSS1   (*(unsigned char volatile far*)0xFCE)              // Reset = 0x00 Shared Interrupt Select 1
#endif

#if (!defined(_Z8F04A) && !defined(_Z8F04) && !defined(_Z8F08) && !defined(_Z8FMC16)) && !defined(_Z8F1680_OR_Z8F648) || defined(__ZSLBUILD)
#define PS      (*(unsigned char volatile far*)0xFCE)              // Reset = 0x00 Port Select
#define IRQPS   (*(unsigned char volatile far*)0xFCE)              // Reset = 0x00 Port Select
#endif

#define IRQCTL  (*(unsigned char volatile far*)0xFCF)              // Reset = 0x00 Interrupt Control


// GPIO Ports material follows (elaborate!)

#define __DATA_DIRECTION          0x01
#define __ALTERNATE_FUNCTION      0x02
#define __ALTERNATE_FUNCTION0     0x02
#define __OUTPUT_CONTROL          0x03
#define __HIGH_DRIVE_ENABLE       0x04
#define __SMR_ENABLE              0x05
#define __PULLUP_ENABLE           0x06
#define __ALTERNATE_FUNCTION1     0x07
#define __ALTERNATE_FUNCTION_SET1 0x07
#define __ALTERNATE_FUNCTION_SET2 0x08
#define __IRQ_EDGE_SELECT         0x08
#define __IRQ_PORT_SELECT         0x09

#define PAADDR  (*(unsigned char volatile far*)0xFD0)              // Reset = 0x00 Port A Address
#define PACTL   (*(unsigned char volatile far*)0xFD1)              // Reset = 0x00 Port A Control
#define PAIN    (*(unsigned char volatile far*)0xFD2)              // Reset = 0xXX Port A Input Data
#define PAOUT   (*(unsigned char volatile far*)0xFD3)              // Reset = 0x00 Pot A Output Data

#define PADD	(((PAADDR) =          __DATA_DIRECTION),((PACTL)))
#if defined(_Z8FMC16)
#define PAAF0	(((PAADDR) =     __ALTERNATE_FUNCTION0),((PACTL)))
#else
#define PAAF	(((PAADDR) =      __ALTERNATE_FUNCTION),((PACTL)))
#endif
#define PAOC	(((PAADDR) =          __OUTPUT_CONTROL),((PACTL)))
#define PAHDE	(((PAADDR) =       __HIGH_DRIVE_ENABLE),((PACTL)))
#define PASMRE	(((PAADDR) =              __SMR_ENABLE),((PACTL)))

#if defined(_Z8F08) || defined(_Z8F04A) || defined(_Z8F04) || defined(_Z8FMC16) || defined(_Z8F1680_OR_Z8F648_OR_Z8F3224) \
                    || defined (__ZSLBUILD)
#define PAPUE	(((PAADDR) =           __PULLUP_ENABLE),((PACTL)))
#endif

#if defined(_Z8F04A) || defined(_Z8F04) || defined(_Z8F1680_OR_Z8F648_OR_Z8F3224) || defined(__ZSLBUILD)
#define PAAFS1	(((PAADDR) = __ALTERNATE_FUNCTION_SET1),((PACTL)))
#if (!defined(_Z8F648))
#define PAAFS2	(((PAADDR) = __ALTERNATE_FUNCTION_SET2),((PACTL)))
#endif
#endif

#if defined(_Z8FMC16)
#define PAAF1     (((PAADDR) =   __ALTERNATE_FUNCTION1),((PACTL)))
#define PAIRQES   (((PAADDR) =       __IRQ_EDGE_SELECT),((PACTL)))
#define PAIRQPSEL (((PAADDR) =       __IRQ_PORT_SELECT),((PACTL)))
#endif

#ifndef EZ8_PORT1
#define PBADDR  (*(unsigned char volatile far*)0xFD4)              // Reset = 0x00 Port B Address
#define PBCTL   (*(unsigned char volatile far*)0xFD5)              // Reset = 0x00 Port B Control
#define PBIN    (*(unsigned char volatile far*)0xFD6)              // Reset = 0xXX Port B Input Data
#define PBOUT   (*(unsigned char volatile far*)0xFD7)              // Reset = 0x00 Port B Output Data

#define PBDD	(((PBADDR) =          __DATA_DIRECTION),((PBCTL)))
#if defined(_Z8FMC16)
#define PBAF0	(((PBADDR) =     __ALTERNATE_FUNCTION0),((PBCTL)))
#else
#define PBAF	(((PBADDR) =      __ALTERNATE_FUNCTION),((PBCTL)))
#endif
#define PBOC	(((PBADDR) =          __OUTPUT_CONTROL),((PBCTL)))
#define PBHDE	(((PBADDR) =       __HIGH_DRIVE_ENABLE),((PBCTL)))
#define PBSMRE	(((PBADDR) =              __SMR_ENABLE),((PBCTL)))

#if  defined(_Z8F08) || defined(_Z8F04A) || defined(_Z8F04) || defined(_Z8FMC16) || defined(_Z8F1680_OR_Z8F648_OR_Z8F3224) \
                     || defined(__ZSLBUILD)
#define PBPUE	(((PBADDR) =           __PULLUP_ENABLE),((PBCTL)))
#endif

#if defined(_Z8F04A) || defined(_Z8F04) || defined(_Z8F1680_OR_Z8F648_OR_Z8F3224) || defined(__ZSLBUILD)
#define PBAFS1	(((PBADDR) = __ALTERNATE_FUNCTION_SET1),((PBCTL)))
#if ( (!defined(_Z8F648)) && (!defined(_Z8F3224)) )
#define PBAFS2	(((PBADDR) = __ALTERNATE_FUNCTION_SET2),((PBCTL)))
#endif
#endif

#if defined(_Z8FMC16)
#define PBAF1	(((PBADDR) =     __ALTERNATE_FUNCTION1),((PBCTL)))
#endif

#ifndef EZ8_NO_PORT3
#define PCADDR  (*(unsigned char volatile far*)0xFD8)              // Reset = 0x00 Port C Address
#define PCCTL   (*(unsigned char volatile far*)0xFD9)              // Reset = 0x00 Port C Control
#define PCIN    (*(unsigned char volatile far*)0xFDA)              // Reset = 0xXX Port C Input Data
#define PCOUT   (*(unsigned char volatile far*)0xFDB)              // Reset = 0x00 Port C Output Data

#define PCDD	(((PCADDR) =          __DATA_DIRECTION),((PCCTL)))
#if !defined(_Z8FMC16)
#define PCAF	(((PCADDR) =      __ALTERNATE_FUNCTION),((PCCTL)))
#endif
#define PCOC	(((PCADDR) =          __OUTPUT_CONTROL),((PCCTL)))
#define PCHDE	(((PCADDR) =       __HIGH_DRIVE_ENABLE),((PCCTL)))
#define PCSMRE	(((PCADDR) =              __SMR_ENABLE),((PCCTL)))

#if defined(_Z8F08) || defined(_Z8F04A) || defined(_Z8F04) || defined(_Z8FMC16) || defined(_Z8F1680_OR_Z8F648_OR_Z8F3224) \
                    || defined(__ZSLBUILD)
#define PCPUE	(((PCADDR) =           __PULLUP_ENABLE),((PCCTL)))
#endif

#if defined(_Z8F04A) || defined(_Z8F04) || defined(_Z8F1680_OR_Z8F648_OR_Z8F3224) || defined(__ZSLBUILD)
#define PCAFS1	(((PCADDR) = __ALTERNATE_FUNCTION_SET1),((PCCTL)))
#define PCAFS2	(((PCADDR) = __ALTERNATE_FUNCTION_SET2),((PCCTL)))
#endif

#if defined(_Z8FMC16)
#define PCIRQES   (((PCADDR) =       __IRQ_EDGE_SELECT),((PCCTL)))
#endif

#endif           // Z8_NO_PORT3

#if (defined(EZ8_PORT4) && !defined(_Z8F04)) || defined(EZ8_PORT8) || defined(EZ8_PORT5) || defined(__ZSLBUILD)
#define PDADDR  (*(unsigned char volatile far*)0xFDC)              // Reset = 0x00 Port D Address
#define PDCTL   (*(unsigned char volatile far*)0xFDD)              // Reset = 0x00 Port D Control
#if !defined(_Z8F04A) || defined(__ZSLBUILD)
#define PDIN    (*(unsigned char volatile far*)0xFDE)              // Reset = 0xXX Port D Input Data
#endif
#define PDOUT   (*(unsigned char volatile far*)0xFDF)              // Reset = 0x00 Port D Output Data

#define PDDD	(((PDADDR) =          __DATA_DIRECTION),((PDCTL)))
#define PDAF	(((PDADDR) =      __ALTERNATE_FUNCTION),((PDCTL)))
#define PDOC	(((PDADDR) =          __OUTPUT_CONTROL),((PDCTL)))
#define PDHDE	(((PDADDR) =       __HIGH_DRIVE_ENABLE),((PDCTL)))
#define PDSMRE	(((PDADDR) =              __SMR_ENABLE),((PDCTL)))

#if defined(_Z8F04A) || defined(_Z8F648) || defined(__ZSLBUILD) || defined(_Z8F3224)
#define PDPUE	(((PDADDR) =           __PULLUP_ENABLE),((PDCTL)))
#define PDAFS1	(((PDADDR) = __ALTERNATE_FUNCTION_SET1),((PDCTL)))
#if ( (!defined(_Z8F648)) && (!defined(_Z8F3224)) )
#define PDAFS2	(((PDADDR) = __ALTERNATE_FUNCTION_SET2),((PDCTL)))
#endif
#endif
#if defined(_Z8F1680)
#define PDPUE	(((PDADDR) =           __PULLUP_ENABLE),((PDCTL)))
#endif
#endif

#endif  // ifndef EZ8_PORT1

#if defined(EZ8_PORT8) || defined(EZ8_PORT5) || defined(EZ8_PORT9) || defined(__ZSLBUILD)
#ifndef EZ8_NO_PORT5
#define PEADDR  (*(unsigned char volatile far*)0xFE0)              // Reset = 0x00 Port E Address
#define PECTL   (*(unsigned char volatile far*)0xFE1)              // Reset = 0x00 Port E Control
#define PEIN    (*(unsigned char volatile far*)0xFE2)              // Reset = 0xXX Port E Input Data
#define PEOUT   (*(unsigned char volatile far*)0xFE3)              // Reset = 0x00 Port E Output Data

#define PEDD	(((PEADDR) =     __DATA_DIRECTION),((PECTL)))
#define PEAF	(((PEADDR) = __ALTERNATE_FUNCTION),((PECTL)))
#define PEOC	(((PEADDR) =     __OUTPUT_CONTROL),((PECTL)))
#define PEHDE	(((PEADDR) =  __HIGH_DRIVE_ENABLE),((PECTL)))
#define PESMRE	(((PEADDR) =         __SMR_ENABLE),((PECTL)))
#if defined(_Z8F1680_OR_Z8F648_OR_Z8F3224)
#define PEPUE	(((PEADDR) =      __PULLUP_ENABLE),((PECTL)))
#endif
#if defined(_Z8F648) || defined(_Z8F3224)
#define PEAFS1	(((PEADDR) = __ALTERNATE_FUNCTION_SET1),((PECTL)))
#endif
#endif		// ifndef EZ8_NO_PORT5

#if defined(EZ8_PORT7) || defined(EZ8_PORT8) || defined(EZ8_PORT9)
#define PFADDR  (*(unsigned char volatile far*)0xFE4)              // Reset = 0x00 Port F Address
#define PFCTL   (*(unsigned char volatile far*)0xFE5)              // Reset = 0x00 Port F Control
#define PFIN    (*(unsigned char volatile far*)0xFE6)              // Reset = 0xXX Port F Input Data
#define PFOUT   (*(unsigned char volatile far*)0xFE7)              // Reset = 0x00 Port F Output Data

#define PFDD	(((PFADDR) =     __DATA_DIRECTION),((PFCTL)))
#define PFAF	(((PFADDR) = __ALTERNATE_FUNCTION),((PFCTL)))
#define PFOC	(((PFADDR) =     __OUTPUT_CONTROL),((PFCTL)))
#define PFHDE	(((PFADDR) =  __HIGH_DRIVE_ENABLE),((PFCTL)))
#define PFSMRE	(((PFADDR) =         __SMR_ENABLE),((PFCTL)))
#if defined(_Z8F648)
#define PFPUE	(((PFADDR) =           __PULLUP_ENABLE),((PFCTL)))
#define PFAFS1	(((PFADDR) = __ALTERNATE_FUNCTION_SET1),((PFCTL)))
#endif

#define PGADDR  (*(unsigned char volatile far*)0xFE8)              // Reset = 0x00 Port G Address
#define PGCTL   (*(unsigned char volatile far*)0xFE9)              // Reset = 0x00 Port G Control
#define PGIN    (*(unsigned char volatile far*)0xFEA)              // Reset = 0xXX Port G Input Data
#define PGOUT   (*(unsigned char volatile far*)0xFEB)              // Reset = 0x00 Port G Output Data
 
#define PGDD	(((PGADDR) =     __DATA_DIRECTION),((PGCTL)))
#define PGAF	(((PGADDR) = __ALTERNATE_FUNCTION),((PGCTL)))
#define PGOC	(((PGADDR) =     __OUTPUT_CONTROL),((PGCTL)))
#define PGHDE	(((PGADDR) =  __HIGH_DRIVE_ENABLE),((PGCTL)))
#define PGSMRE	(((PGADDR) =         __SMR_ENABLE),((PGCTL)))
#if defined(_Z8F648)
#define PGPUE	(((PGADDR) =           __PULLUP_ENABLE),((PGCTL)))
#define PGAFS1	(((PGADDR) = __ALTERNATE_FUNCTION_SET1),((PGCTL)))
#endif
#endif          // EZ8_PORT7 || EZ8_PORT8  || EZ8_PORT9

#if defined(EZ8_PORT8) || defined(EZ8_PORT9)
#define PHADDR  (*(unsigned char volatile far*)0xFEC)              // Reset = 0x00 Port H Address
#define PHCTL   (*(unsigned char volatile far*)0xFED)              // Reset = 0x00 Port H Control
#define PHIN    (*(unsigned char volatile far*)0xFEE)              // Reset = 0xXX Port H Input Data
#define PHOUT   (*(unsigned char volatile far*)0xFEF)              // Reset = 0x00 Port H Output Data

#define PHDD	(((PHADDR) =     __DATA_DIRECTION),((PHCTL)))
#define PHAF	(((PHADDR) = __ALTERNATE_FUNCTION),((PHCTL)))
#define PHOC	(((PHADDR) =     __OUTPUT_CONTROL),((PHCTL)))
#define PHHDE	(((PHADDR) =  __HIGH_DRIVE_ENABLE),((PHCTL)))
#define PHSMRE	(((PHADDR) =         __SMR_ENABLE),((PHCTL)))
#if defined(_Z8F648)
#define PHPUE	(((PHADDR) =           __PULLUP_ENABLE),((PHCTL)))
#define PHAFS1	(((PHADDR) = __ALTERNATE_FUNCTION_SET1),((PHCTL)))
#endif

#endif /* EZ8_PORT8 || EZ8_PORT9 */
#endif 

#if defined(EZ8_PORT9)
#define PJADDR  (*(unsigned char volatile far*)0xFBC)              // Reset = 0x00 Port J Address
#define PJCTL   (*(unsigned char volatile far*)0xFBD)              // Reset = 0x00 Port J Control
#define PJIN    (*(unsigned char volatile far*)0xFBE)              // Reset = 0xXX Port J Input Data
#define PJOUT   (*(unsigned char volatile far*)0xFBF)              // Reset = 0x00 Port JOutput Data

#define PJDD	(((PJADDR) =     	  __DATA_DIRECTION),((PJCTL)))
#define PJAF	(((PJADDR) = 	  __ALTERNATE_FUNCTION),((PJCTL)))
#define PJOC	(((PJADDR) =     	  __OUTPUT_CONTROL),((PJCTL)))
#define PJHDE	(((PJADDR) =  	   __HIGH_DRIVE_ENABLE),((PJCTL)))
#define PJSMRE	(((PJADDR) =         	  __SMR_ENABLE),((PJCTL)))
#define PJPUE	(((PJADDR) =           __PULLUP_ENABLE),((PJCTL)))
#if !defined(_Z8F648)
#define PJAFS1	(((PCADDR) = __ALTERNATE_FUNCTION_SET1),((PJCTL)))
#define PJAFS2	(((PJADDR) = __ALTERNATE_FUNCTION_SET2),((PJCTL)))
#endif
#endif /* EZ8_PORT9 */


#if defined(_Z8F04A) || defined(_Z8F04) || defined(_Z8FMC16) || defined(_Z8F1680_OR_Z8F648_OR_Z8F3224)
#define RSTSTAT (*(unsigned char volatile far*)0xFF0)              // Reset = 0xXX Watchdog Timer Status
#endif

#if defined(_Z8FS040xSB)
#define RSTSTAT (*(unsigned char volatile far*)0xFF0)              // Reset = 0xX0 Watchdog Timer Status
#endif

#if !defined(_Z8FMC16) && !defined(_Z8F1680_OR_Z8F648_OR_Z8F3224)
#define WDTCTL  (*(unsigned char volatile far*)0xFF0)              // Reset = 0xX0 Watchdog Timer Control
#define WDTU    (*(unsigned char volatile far*)0xFF1)              // Reset = 0xFF Watchdog Timer Reload Upper
#endif
#define WDTHL   (*(unsigned int volatile far*)0xFF2)               // Reset = 0xFFFF Watchdog Timer Reload
#define WDTH    (*(unsigned char volatile far*)0xFF2)              // Reset = 0xFF Watchdog Timer Reload High
#define WDTL    (*(unsigned char volatile far*)0xFF3)              // Reset = 0xFF Watchdog Timer Reload Low

#if defined(_Z8F04A) || defined(_Z8F04) || defined(_Z8FMC16) || defined(_Z8F1680_OR_Z8F648_OR_Z8F3224)
#define TRMADR  (*(unsigned char volatile far*)0xFF6)              // Reset = 0x00 Trim Bit Address Register
#define TRMDR   (*(unsigned char volatile far*)0xFF7)              // Reset = 0xXX Trim Data Register

#if defined(_Z8F04A) || defined(_Z8F1680)
#define TTEMP0  (((TRMADR) = 0x00),((TRMDR)))                      // Reset = 0xXX Trim Temperature 0
#define TTEMP1  (((TRMADR) = 0x01),((TRMDR)))                      // Reset = 0xXX Trim Temperature 1
#endif

#if defined(_Z8F648)
#define TTEMP0  (((TRMADR) = 0x01),((TRMDR)))                      // Reset = 0xXX Trim Temperature 0
#define TTEMP1  (((TRMADR) = 0x02),((TRMDR)))                      // Reset = 0xXX Trim Temperature 1
#endif

#if defined(_Z8FMC16)
#define IPO_TRIM  (((TRMADR) = 0x01),((TRMDR)))                    // Reset = 0xXX Trim Internal Precision Oscillator
#define IPO_TRIM1 (((TRMADR) = 0x02),((TRMDR)))                    // Reset = 0xXX Trim Internal Precision Oscillator
#define ADCCAL    (((TRMADR) = 0x03),((TRMDR)))
#elif ( (!defined(_Z8F648)) && (!defined(_Z8F3224)) )
#define TIPO      (((TRMADR) = 0x02),((TRMDR)))                    // Reset = 0xXX Trim Internal Precision Oscillator
#else
#define TIPO      (((TRMADR) = 0x03),((TRMDR)))                    // Reset = 0xXX Trim Internal Precision Oscillator
#endif

#if defined(_Z8F1680)
#define TLVD_VBO  (((TRMADR) = 0x03),((TRMDR)))                    // Reset = 0xXX Trim Low Voltage Detect
#define TCOMP_ADC (((TRMADR) = 0x04),((TRMDR)))                    // Reset = 0xXX Trim Comparator and ADC
#define TVREF     (((TRMADR) = 0x05),((TRMDR)))                    // Reset = 0xXX Trim Voltage Reference
#define TBG       (((TRMADR) = 0x06),((TRMDR)))                    // Reset = 0xXX Trim Band Gap
#define TFILTER0  (((TRMADR) = 0x07),((TRMDR)))                    // Reset = 0xXX Trim Filter 0
#define TFILTER1  (((TRMADR) = 0x08),((TRMDR)))                    // Reset = 0xXX Trim Filter 1
#endif

#if defined(_Z8F648)
#define TLVD_VBO  (((TRMADR) = 0x04),((TRMDR)))                    // Reset = 0xXX Trim Low Voltage Detect
#define TADC_DAC  (((TRMADR) = 0x05),((TRMDR)))                    // Reset = 0xXX Trim ADC/DAC Reference Voltage
#define TBG       (((TRMADR) = 0x06),((TRMDR)))                    // Reset = 0xXX Trim Band Gap & Voltage Regulator
#define TWDT      (((TRMADR) = 0x07),((TRMDR)))                    // Reset = 0xXX Trim WDT
#define TLCD0     (((TRMADR) = 0x08),((TRMDR)))                    // Reset = 0xXX LCD Trim 0
#define TLCD1     (((TRMADR) = 0x09),((TRMDR)))                    // Reset = 0xXX LCD Trim 1
#define TVBIAS	  (((TRMADR) = 0x0C),((TRMDR)))                    // Reset = 0xXX VBIAS Trim
#endif

#if defined(_Z8F3224)
#define TVBG      (((TRMADR) = 0x02),((TRMDR)))                    // Reset = 0xX0 Trim Bandgap Voltage Reference
#define TLVD_VBO  (((TRMADR) = 0x04),((TRMDR)))                    // Reset = 0xXX Trim Low Voltage Detect
#define TVREF     (((TRMADR) = 0x05),((TRMDR)))                    // Reset = 0xXX Trim ADC Reference Voltage
#define TVREG     (((TRMADR) = 0x06),((TRMDR)))                    // Reset = 0x05 Trim Voltage Regulator
#define TVBIAS	  (((TRMADR) = 0x0C),((TRMDR)))                    // Reset = 0xXX VBIAS Trim
#endif

#if defined(_Z8F04A)
#if !defined(_Z8F0830A)
#define TLVD    (((TRMADR) = 0x03),((TRMDR)))                      // Reset = 0xXX Trim Low Voltage Detect Trim
#endif
#define TBG     (((TRMADR) = 0x04),((TRMDR)))                      // Reset = 0xXX Trim Band Gap Trim
#define TUSER5  (((TRMADR) = 0x05),((TRMDR)))                      // Reset = 0xXX Trim User 5
#define TUSER6  (((TRMADR) = 0x06),((TRMDR)))                      // Reset = 0xXX Trim User 6
#define TUSER7  (((TRMADR) = 0x07),((TRMDR)))                      // Reset = 0xXX Trim User 7
#define TUSER8  (((TRMADR) = 0x08),((TRMDR)))                      // Reset = 0xXX Trim User 8
#define TUSER9  (((TRMADR) = 0x09),((TRMDR)))                      // Reset = 0xXX Trim User 9
#define TUSER10 (((TRMADR) = 0x0A),((TRMDR)))                      // Reset = 0xXX Trim User 10
#define TUSER11 (((TRMADR) = 0x0B),((TRMDR)))                      // Reset = 0xXX Trim User 11
#define TUSER12 (((TRMADR) = 0x0C),((TRMDR)))                      // Reset = 0xXX Trim User 12
#define TUSER13 (((TRMADR) = 0x0D),((TRMDR)))                      // Reset = 0xXX Trim User 13
#define TUSER14 (((TRMADR) = 0x0E),((TRMDR)))                      // Reset = 0xXX Trim User 14
#define TUSER15 (((TRMADR) = 0x0F),((TRMDR)))                      // Reset = 0xXX Trim User 15
#define TUSER16 (((TRMADR) = 0x10),((TRMDR)))                      // Reset = 0xXX Trim User 16
#define TUSER17 (((TRMADR) = 0x11),((TRMDR)))                      // Reset = 0xXX Trim User 17
#define TUSER18 (((TRMADR) = 0x12),((TRMDR)))                      // Reset = 0xXX Trim User 18
#define TUSER19 (((TRMADR) = 0x13),((TRMDR)))                      // Reset = 0xXX Trim User 19
#define TUSER20 (((TRMADR) = 0x14),((TRMDR)))                      // Reset = 0xXX Trim User 20
#define TUSER21 (((TRMADR) = 0x15),((TRMDR)))                      // Reset = 0xXX Trim User 21
#define TUSER22 (((TRMADR) = 0x16),((TRMDR)))                      // Reset = 0xXX Trim User 22
#define TUSER23 (((TRMADR) = 0x17),((TRMDR)))                      // Reset = 0xXX Trim User 23
#define TUSER24 (((TRMADR) = 0x18),((TRMDR)))                      // Reset = 0xXX Trim User 24
#define TUSER25 (((TRMADR) = 0x19),((TRMDR)))                      // Reset = 0xXX Trim User 25
#define TUSER26 (((TRMADR) = 0x1A),((TRMDR)))                      // Reset = 0xXX Trim User 26
#define TUSER27 (((TRMADR) = 0x1B),((TRMDR)))                      // Reset = 0xXX Trim User 27
#define TUSER28 (((TRMADR) = 0x1C),((TRMDR)))                      // Reset = 0xXX Trim User 28
#define TUSER29 (((TRMADR) = 0x1D),((TRMDR)))                      // Reset = 0xXX Trim User 29
#define TUSER30 (((TRMADR) = 0x1E),((TRMDR)))                      // Reset = 0xXX Trim User 30
#define TUSER31 (((TRMADR) = 0x1F),((TRMDR)))                      // Reset = 0xXX Trim User 31
#endif
#endif		/* TRIM BITS */

#define FCTL    (*(unsigned char volatile far*)0xFF8)              // Reset = 0x00 FLASH Control
#define FSTAT   (*(unsigned char volatile far*)0xFF8)              // Reset = 0x00 FLASH Status
#define FPS     (*(unsigned char volatile far*)0xFF9)              // Reset = 0x00 FLASH Page Select
#if defined(_Z8F642) || defined(_Z8F08)
#define RPS     (*(unsigned char volatile far*)0xFF9)              // Reset = 0x00 ROM Page Select
#endif
#if  defined(_Z8F642) || defined(_Z8F04A)  || defined(_Z8F08) || defined(_Z8F04) || defined(_Z8FMC16) \
                      || defined(_Z8F1680) || defined (_Z8F3224)
#define FPROT   (*(unsigned char volatile far*)0xFF9)              // Reset = 0x00 FLASH Sector Protect
#endif
#if defined(_Z8F648)
#define FBP     (*(unsigned char volatile far*)0xFF9)              // Reset = 0x00 FLASH Block Protect
#endif

#if ( (!defined(_Z8F648)) && (!defined(_Z8F3224)) )
#define FPF     (*(unsigned int volatile far*)0xFFA)               // Reset = 0x0000 FLASH Programming Frequency
#define FPFH    (*(unsigned char volatile far*)0xFFA)              // Reset = 0x00 FLASH Programming Frequency High
#define FFREQ   (*(unsigned int volatile far*)0xFFA)               // Reset = 0x0000 FLASH Programming Frequency
#define FFREQH  (*(unsigned char volatile far*)0xFFA)              // Reset = 0x00 FLASH Programming Frequency High
#define FPFL    (*(unsigned char volatile far*)0xFFB)              // Reset = 0x00 FLASH Programming Frequency Low
#define FFREQL  (*(unsigned char volatile far*)0xFFB)              // Reset = 0x00 FLASH Programming Frequency Low
#endif

#if defined(_Z8F648)
#define FPCONFIG	(*(unsigned char volatile far*)0xFFA)          // Reset = 0x00 FLASH Programming Configuration
#endif


#define FLAGS   (*(unsigned char volatile far*)0xFFC)              // Reset = 0xXX Flags Register
#define RP      (*(unsigned char volatile far*)0xFFD)              // Reset = 0xXX Register Pointer
#define SPH     (*(unsigned char volatile far*)0xFFE)              // Reset = 0xXX Stack Pointer High
#define SPL     (*(unsigned char volatile far*)0xFFF)              // Reset = 0xXX  Stack Pointer Low

#if defined(EZ8_RTC)
// Real-Time Clock Registers
#define RTC_SEC 	(*(unsigned char volatile far*)0xF30)			// Reset = 0xXX RTC Seconds Register
#define RTC_MIN		(*(unsigned char volatile far*)0xF31)			// Reset = 0xXX RTC Minutes Register
#define RTC_HRS		(*(unsigned char volatile far*)0xF32)			// Reset = 0xXX RTC Hours Register
#define RTC_DOM		(*(unsigned char volatile far*)0xF33)			// Reset = 0x0X RTC Day Of Week Register
#define RTC_DOW		(*(unsigned char volatile far*)0xF34)			// Reset = 0xXX RTC Day Of Month Register
#define RTC_MON		(*(unsigned char volatile far*)0xF35)			// Reset = 0xXX RTC Month Register
#define RTC_YR		(*(unsigned char volatile far*)0xF36)			// Reset = 0xXX RTC Year Register
#define RTC_ASEC	(*(unsigned char volatile far*)0xF37)			// Reset = 0xXX RTC Alarm Seconds Register
#define RTC_AMIN	(*(unsigned char volatile far*)0xF38)			// Reset = 0xXX RTC Alarm Minutes Register
#define RTC_AHRS	(*(unsigned char volatile far*)0xF39)			// Reset = 0xXX RTC Alarm hours Register
#define RTC_ADOM	(*(unsigned char volatile far*)0xF3A)			// Reset = 0x0X RTC Alarm Day Of Week Register
#define RTC_ADOW	(*(unsigned char volatile far*)0xF3B)			// Reset = 0xXX RTC Alarm Day Of Month Register
#define RTC_ACTRL	(*(unsigned char volatile far*)0xF3C)			// Reset = 0x00 RTC Alarm Control Register
#define RTC_CAL		(*(unsigned char volatile far*)0xF3D)			// Reset = 0x00 RTC Calibration Register
#define RTC_TIM		(*(unsigned char volatile far*)0xF3E)			// Reset = 0x00 RTC Timing Register
#define RTC_CTRL	(*(unsigned char volatile far*)0xF3F)			// Reset = 0x00 RTC Control Register
#endif

#if defined(EZ8_USB)
// USB support
#define USBSA			(*(unsigned char volatile far*)0xF59)		// Reset = 0x00 USB Subaddress Register
#define USBSD			(*(unsigned char volatile far*)0xF5A)		// Reset = 0x00 USB Subdata Register
#define USBCTL			(*(unsigned char volatile far*)0xF5B)		// Reset = 0x00 USB Control Register
#define USBDMA0CTL		(*(unsigned char volatile far*)0xF5C)		// Reset = 0x00 USB DMA 0 Control Register
#define USBDMA1CTL		(*(unsigned char volatile far*)0xF5D)		// Reset = 0x00 USB DMA 1 Control Register
#define USBDMADATA		(*(unsigned char volatile far*)0xF5E)		// Reset = 0x00 USB DMA Data Register
#define USBIRQCTL		(*(unsigned char volatile far*)0xF5F)		// Reset = 0x00 USB Interrupt Control Register

// Now, definitions used for the very numerous USB subregisters
#define __OUT_ENDPT1_START_ADDR		0x01
#define __OUT_ENDPT2_START_ADDR		0x02
#define __OUT_ENDPT3_START_ADDR		0x03
#define __IN_ENDPTS_START_ADDR		0x08
#define __IN_ENDPT1_START_ADDR		0x09
#define __IN_ENDPT2_START_ADDR		0x0A
#define __IN_ENDPT3_START_ADDR		0x0B
#define __CLOCK_GATE				0x10
#define __INTERPT_ID				0x28
#define __IN_INTERPT_REQ			0x29
#define __OUT_INTERPT_REQ			0x2A
#define __USB_INTERPT_REQ			0x2B
#define __IN_INTERPT_EN				0x2C
#define __OUT_INTERPT_EN			0x2D
#define __USB_INTERPT_EN			0x2E
#define __ENDPT0_CTL_STAT			0x34
#define __IN0_BYTE_CNT				0x35
#define __IN1_BYTE_CNT				0x37
#define __IN2_BYTE_CNT				0x39
#define __IN3_BYTE_CNT				0x3B
#define __IN1_CTL_STAT				0x36
#define __IN2_CTL_STAT				0x38
#define __IN3_CTL_STAT				0x3A
#define __OUT0_BYTE_CNT				0x45
#define __OUT1_BYTE_CNT				0x47
#define __OUT2_BYTE_CNT				0x49
#define __OUT3_BYTE_CNT				0x4B
#define __OUT1_CTL_STAT				0x46
#define __OUT2_CTL_STAT				0x48
#define __OUT3_CTL_STAT				0x4A
#define __CTL_STAT					0x56
#define __TOG_CTL					0x57
#define __FRAME_CNT_LO				0x58
#define __FRAME_CNT_HI				0x59
#define __FN_ADDR					0x5B
#define __PAIRING					0x5D
#define __IN_ENDPT_VALID			0x5E
#define __OUT_ENDPT_VALID			0x5F
#define __IN_ENDPTS_STOP_ADDR		0x62
#define __SETUP_BUF_BYTE0			0x68
#define __SETUP_BUF_BYTE1			0x69
#define __SETUP_BUF_BYTE2			0x6A
#define __SETUP_BUF_BYTE3			0x6B
#define __SETUP_BUF_BYTE4			0x6C
#define __SETUP_BUF_BYTE5			0x6D
#define __SETUP_BUF_BYTE6			0x6E
#define __SETUP_BUF_BYTE7			0x6F

// Subregisters
#define USBO1ADDR		(((USBSA) = __OUT_ENDPT1_START_ADDR),((USBSD)))
#define USBO2ADDR		(((USBSA) = __OUT_ENDPT2_START_ADDR),((USBSD)))
#define USBO3ADDR		(((USBSA) = __OUT_ENDPT3_START_ADDR),((USBSD)))
#define USBISTADDR		(((USBSA) =  __IN_ENDPTS_START_ADDR),((USBSD)))
#define USBI1ADDR		(((USBSA) =  __IN_ENDPT1_START_ADDR),((USBSD)))
#define USBI2ADDR		(((USBSA) =  __IN_ENDPT2_START_ADDR),((USBSD)))
#define USBI3ADDR		(((USBSA) =  __IN_ENDPT3_START_ADDR),((USBSD)))
#define USBCLKGATE		(((USBSA) =            __CLOCK_GATE),((USBSD)))
#define USBIID			(((USBSA) =            __INTERPT_ID),((USBSD)))
#define USBINIRQ		(((USBSA) =        __IN_INTERPT_REQ),((USBSD)))
#define USBOUTIRQ		(((USBSA) =       __OUT_INTERPT_REQ),((USBSD)))
#define USBIRQ			(((USBSA) =       __USB_INTERPT_REQ),((USBSD)))
#define USBINIEN		(((USBSA) =         __IN_INTERPT_EN),((USBSD)))
#define USBOUTIEN		(((USBSA) =        __OUT_INTERPT_EN),((USBSD)))
#define USBIEN			(((USBSA) =        __USB_INTERPT_EN),((USBSD)))
#define USBEP0CS		(((USBSA) =       __ENDPT0_CTL_STAT),((USBSD)))
#define USBI0BC			(((USBSA) =          __IN0_BYTE_CNT),((USBSD)))
#define USBI1BC			(((USBSA) =          __IN1_BYTE_CNT),((USBSD)))
#define USBI2BC			(((USBSA) =          __IN2_BYTE_CNT),((USBSD)))
#define USBI3BC			(((USBSA) =          __IN3_BYTE_CNT),((USBSD)))
#define USBI1CS			(((USBSA) =          __IN1_CTL_STAT),((USBSD)))
#define USBI2CS			(((USBSA) =          __IN2_CTL_STAT),((USBSD)))
#define USBI3CS			(((USBSA) =          __IN3_CTL_STAT),((USBSD)))
#define USBO0BC			(((USBSA) =         __OUT0_BYTE_CNT),((USBSD)))
#define USBO1BC			(((USBSA) =         __OUT1_BYTE_CNT),((USBSD)))
#define USBO2BC			(((USBSA) =         __OUT2_BYTE_CNT),((USBSD)))
#define USBO3BC			(((USBSA) =         __OUT3_BYTE_CNT),((USBSD)))
#define USBO1CS			(((USBSA) =         __OUT1_CTL_STAT),((USBSD)))
#define USBO2CS			(((USBSA) =         __OUT2_CTL_STAT),((USBSD)))
#define USBO3CS			(((USBSA) =         __OUT3_CTL_STAT),((USBSD)))
#define USBCS			(((USBSA) =              __CTL_STAT),((USBSD)))
#define USBTOGCTL		(((USBSA) =               __TOG_CTL),((USBSD)))
#define USBFCL			(((USBSA) =          __FRAME_CNT_LO),((USBSD)))
#define USBFCH			(((USBSA) =          __FRAME_CNT_HI),((USBSD)))
#define USBFNADDR		(((USBSA) =               __FN_ADDR),((USBSD)))
#define USBPAIR			(((USBSA) =               __PAIRING),((USBSD)))
#define USBINVAL		(((USBSA) =        __IN_ENDPT_VALID),((USBSD)))
#define USBOUTVAL		(((USBSA) =       __OUT_ENDPT_VALID),((USBSD)))
#define USBISPADDR		(((USBSA) =   __IN_ENDPTS_STOP_ADDR),((USBSD)))
#define USBSU0			(((USBSA) =       __SETUP_BUF_BYTE0),((USBSD)))
#define USBSU1			(((USBSA) =       __SETUP_BUF_BYTE1),((USBSD)))
#define USBSU2			(((USBSA) =       __SETUP_BUF_BYTE2),((USBSD)))
#define USBSU3			(((USBSA) =       __SETUP_BUF_BYTE3),((USBSD)))
#define USBSU4			(((USBSA) =       __SETUP_BUF_BYTE4),((USBSD)))
#define USBSU5			(((USBSA) =       __SETUP_BUF_BYTE5),((USBSD)))
#define USBSU6			(((USBSA) =       __SETUP_BUF_BYTE6),((USBSD)))
#define USBSU7			(((USBSA) =       __SETUP_BUF_BYTE7),((USBSD)))

#endif	// EZ8_USB

#if defined(EZ8_CLKCTL)
#define CLKCTL0			(*(unsigned char volatile far*)0xF82)		// Reset = 0x00 Clock Control 0
#define CLKCTL1			(*(unsigned char volatile far*)0xF83)		// Reset = 0x01 Clock Control 1
#define CLKCTL2			(*(unsigned char volatile far*)0xF84)		// Reset = 0x00 Clock Control 2
#define CLKCTL3			(*(unsigned char volatile far*)0xF85)		// Reset = 0x08 Clock Control 3
#define CLKCTL4			(*(unsigned char volatile far*)0xF86)		// Reset = 0x00 Clock Control 4
#define CLKCTL5			(*(unsigned char volatile far*)0xF87)		// Reset = 0x05 Clock Control 5
#define CLKCTL6			(*(unsigned char volatile far*)0xF88)		// Reset = 0x00 Clock Control 6
#define CLKCTL7			(*(unsigned char volatile far*)0xF89)		// Reset = 0x00 Clock Control 7
#define CLKCTL8			(*(unsigned char volatile far*)0xF8A)		// Reset = 0xXX Clock Control 8
#define CLKCTL9			(*(unsigned char volatile far*)0xF8B)		// Reset = 0xXX Clock Control 9
#if (!(defined(_Z8F3224)) )
#define CLKCTLA			(*(unsigned char volatile far*)0xF8C)		// Reset = 0x00 Clock Control A
#define CLKCTLB			(*(unsigned char volatile far*)0xF8D)		// Reset = 0x00 Clock Control B
#define CLKCTLC			(*(unsigned char volatile far*)0xF8E)		// Reset = 0x00 Clock Control C
#endif
#endif

#if defined(EZ8_OP_AMPS_AB)
#define AMPACTL0		(*(unsigned char volatile far*)0xF94)		// Reset = 0x00 Op Amp_A Control 0
#define AMPACTL1		(*(unsigned char volatile far*)0xF95) 		// Reset = 0x00 Op Amp_A Control 1
#ifdef EZ8_OP_AMPS_AB_AMP_B
#define AMPBCTL0		(*(unsigned char volatile far*)0xF96) 		// Reset = 0x00 Op Amp_B Control 0 
#define AMPBCTL1		(*(unsigned char volatile far*)0xF97) 		// Reset = 0x00 Op Amp_B Control 1
#endif
#endif

#if defined(EZ8_OP_AMPS_A0_A1)
#define AMPA0CTL0		(*(unsigned char volatile far*)0xF94)		// Reset = 0x00 Op Amp_A0 Control 0
#define AMPA0CTL1		(*(unsigned char volatile far*)0xF95) 		// Reset = 0x00 Op Amp_A0 Control 1
#define AMPA1CTL0		(*(unsigned char volatile far*)0xF96) 		// Reset = 0x00 Op Amp_A1 Control 0 
#define AMPA1CTL1		(*(unsigned char volatile far*)0xF97) 		// Reset = 0x00 Op Amp_A1 Control 1
#endif

#if defined (EZ8_EVENT_SYS)
#define ESSSA			(*(unsigned char volatile far*)0xF98)		// Reset = 0x00 Event System Source Address
#define ESSSD			(*(unsigned char volatile far*)0xF99)		// Reset = 0x00 Event System  Source Control
#define ESDSA			(*(unsigned char volatile far*)0xF9A)		// Reset = 0x00 Event System Destination Address
#define ESDSD			(*(unsigned char volatile far*)0xF9B)		// Reset = 0x00 Event System Destination Control

// Event system subregisters
// Source channels
#define __SRC_CH0		0x0
#define __SRC_CH1		0x1
#define __SRC_CH2		0x2
#define __SRC_CH3		0x3
#define __SRC_CH4		0x4
#define __SRC_CH5		0x5
#define __SRC_CH6		0x6
#define __SRC_CH7		0x7

#define ESCH0SRC	(((ESSSA) =          __SRC_CH0),((ESSSD)))
#define ESCH1SRC	(((ESSSA) =          __SRC_CH1),((ESSSD)))
#define ESCH2SRC	(((ESSSA) =          __SRC_CH2),((ESSSD)))
#define ESCH3SRC	(((ESSSA) =          __SRC_CH3),((ESSSD)))
#define ESCH4SRC	(((ESSSA) =          __SRC_CH4),((ESSSD)))
#define ESCH5SRC	(((ESSSA) =          __SRC_CH5),((ESSSD)))
#define ESCH6SRC	(((ESSSA) =          __SRC_CH6),((ESSSD)))
#define ESCH7SRC	(((ESSSA) =          __SRC_CH7),((ESSSD)))

//Destination channels
// Reserved channels are omitted here.
#define __DST_CH04		0x04
#define __DST_CH08		0x08
#define __DST_CH10		0x10
#define __DST_CH11		0x11
#define __DST_CH14		0x14
#define __DST_CH15		0x15
#define __DST_CH18		0x18
#define __DST_CH19		0x19
#define __DST_CH1C		0x1C
#define __DST_CH1D		0x1D
#define __DST_CH1E		0x1E
#define __DST_CH1F		0x1F
#define __DST_CH20		0x20
#define __DST_CH2C		0x2C
#define __DST_CH30		0x30
#define __DST_CH31		0x31
#define __DST_CH32		0x32
#define __DST_CH33		0x33

#define ESCDST04CH	(((ESDSA) =          __DST_CH04),((ESDSD)))
#define ESCDST08CH	(((ESDSA) =          __DST_CH08),((ESDSD)))
#define ESCDST10CH	(((ESDSA) =          __DST_CH10),((ESDSD)))
#define ESCDST11CH	(((ESDSA) =          __DST_CH11),((ESDSD)))
#define ESCDST14CH	(((ESDSA) =          __DST_CH14),((ESDSD)))
#define ESCDST15CH	(((ESDSA) =          __DST_CH15),((ESDSD)))
#define ESCDST18CH	(((ESDSA) =          __DST_CH18),((ESDSD)))
#define ESCDST19CH	(((ESDSA) =          __DST_CH19),((ESDSD)))
#define ESCDST1CCH	(((ESDSA) =          __DST_CH1C),((ESDSD)))
#define ESCDST1DCH	(((ESDSA) =          __DST_CH1D),((ESDSD)))
#define ESCDST1ECH	(((ESDSA) =          __DST_CH1E),((ESDSD)))
#define ESCDST1FCH	(((ESDSA) =          __DST_CH1F),((ESDSD)))
#define ESCDST20CH	(((ESDSA) =          __DST_CH20),((ESDSD)))
#define ESCDST2CCH	(((ESDSA) =          __DST_CH2C),((ESDSD)))
#define ESCDST30CH	(((ESDSA) =          __DST_CH30),((ESDSD)))
#define ESCDST31CH	(((ESDSA) =          __DST_CH31),((ESDSD)))
#define ESCDST32CH	(((ESDSA) =          __DST_CH32),((ESDSD)))
#define ESCDST33CH	(((ESDSA) =          __DST_CH33),((ESDSD)))

#endif		// EZ8_EVENT_SYS

#if defined (EZ8_LCD)
#define LCDSA			(*(unsigned char volatile far*)0xFB1)		// Reset = 0x00 LCD Subaddress
#define LCDSD			(*(unsigned char volatile far*)0xFB2)		// Reset = 0xXX LCD Subdata
#define LCDCLK			(*(unsigned char volatile far*)0xFB3)		// Reset = 0x00 LCD Clock
#define LCDCTL0		    (*(unsigned char volatile far*)0xFB4)		// Reset = 0x00 LCD Control 0
#define LCDCTL1		    (*(unsigned char volatile far*)0xFB5)		// Reset = 0x00 LCD Control 1
#define LCDCTL2		    (*(unsigned char volatile far*)0xFB6)		// Reset = 0x00 LCD Control 2
#define LCDCTL3		    (*(unsigned char volatile far*)0xFB7)		// Reset = 0x00 LCD Control 3

// LCD Subregisters

#define __LCD_MEMA_0	0x00
#define __LCD_MEMA_1	0x01
#define __LCD_MEMA_2	0x02
#define __LCD_MEMA_3	0x03
#define __LCD_MEMA_4	0x04
#define __LCD_MEMA_5	0x05
#define __LCD_MEMA_6	0x06
#define __LCD_MEMA_7	0x07
#define __LCD_MEMA_8	0x08
#define __LCD_MEMA_9	0x09
#define __LCD_MEMA_A	0x0A
#define __LCD_MEMA_B	0x0B
#define __LCD_MEMB_0	0x10
#define __LCD_MEMB_1	0x11
#define __LCD_MEMB_2	0x12
#define __LCD_MEMB_3	0x13
#define __LCD_MEMB_4	0x14
#define __LCD_MEMB_5	0x15
#define __LCD_MEMB_6	0x16
#define __LCD_MEMB_7	0x17
#define __LCD_MEMB_8	0x18
#define __LCD_MEMB_9	0x19
#define __LCD_MEMB_A	0x1A
#define __LCD_MEMB_B	0x1B

#define LCDMEMA0	(((LCDSA) =          __LCD_MEMA_0),((LCDSD)))
#define LCDMEMA1	(((LCDSA) =          __LCD_MEMA_1),((LCDSD)))
#define LCDMEMA2	(((LCDSA) =          __LCD_MEMA_2),((LCDSD)))
#define LCDMEMA3	(((LCDSA) =          __LCD_MEMA_3),((LCDSD)))
#define LCDMEMA4	(((LCDSA) =          __LCD_MEMA_4),((LCDSD)))
#define LCDMEMA5	(((LCDSA) =          __LCD_MEMA_5),((LCDSD)))
#define LCDMEMA6	(((LCDSA) =          __LCD_MEMA_6),((LCDSD)))
#define LCDMEMA7	(((LCDSA) =          __LCD_MEMA_7),((LCDSD)))
#define LCDMEMA8	(((LCDSA) =          __LCD_MEMA_8),((LCDSD)))
#define LCDMEMA9	(((LCDSA) =          __LCD_MEMA_9),((LCDSD)))
#define LCDMEMAA	(((LCDSA) =          __LCD_MEMA_A),((LCDSD)))
#define LCDMEMAB	(((LCDSA) =          __LCD_MEMA_B),((LCDSD)))
#define LCDMEMB0	(((LCDSA) =          __LCD_MEMB_0),((LCDSD)))
#define LCDMEMB1	(((LCDSA) =          __LCD_MEMB_1),((LCDSD)))
#define LCDMEMB2	(((LCDSA) =          __LCD_MEMB_2),((LCDSD)))
#define LCDMEMB3	(((LCDSA) =          __LCD_MEMB_3),((LCDSD)))
#define LCDMEMB4	(((LCDSA) =          __LCD_MEMB_4),((LCDSD)))
#define LCDMEMB5	(((LCDSA) =          __LCD_MEMB_5),((LCDSD)))
#define LCDMEMB6	(((LCDSA) =          __LCD_MEMB_6),((LCDSD)))
#define LCDMEMB7	(((LCDSA) =          __LCD_MEMB_7),((LCDSD)))
#define LCDMEMB8	(((LCDSA) =          __LCD_MEMB_8),((LCDSD)))
#define LCDMEMB9	(((LCDSA) =          __LCD_MEMB_9),((LCDSD)))
#define LCDMEMBA	(((LCDSA) =          __LCD_MEMB_A),((LCDSD)))
#define LCDMEMBB	(((LCDSA) =          __LCD_MEMB_B),((LCDSD)))

#endif // EZ8_LCD

#if defined (EZ8_AES)
#define AESDATA			(*(unsigned char volatile far*)0xFB8)		// Reset = 0xXX AES Data
#define AESIV			(*(unsigned char volatile far*)0xFB8)		// Reset = 0xXX AES Initialization Vector
#define AESKEY			(*(unsigned char volatile far*)0xFB9)		// Reset = 0xXX AES Key
#define AESCTL			(*(unsigned char volatile far*)0xFBA)		// Reset = 0x00 AES Control
#define AESSTAT			(*(unsigned char volatile far*)0xFBB)		// Reset = 0x00 AES Status
#endif

#if defined(_Z8F1680)
// Flash Information Memory Registers 
// The following registers can be accessed after selecting flash information area in FPS 
#define TEMPCALH  (*(unsigned char volatile rom*)0xFE60)           // Reset = 0xXX Temp Sensor Calibration High 
#define TEMPCALL  (*(unsigned char volatile rom*)0xFE61)           // Reset = 0xXX Temp Sensor Calibration Low 
#define TEMPCAL   (*(unsigned int volatile rom*)0xFE60)            // Reset = 0xXXXX Temp Sensor Calibration
#endif



#define FLASH_OPTION1  rom char flash_option1 _At 0x0

#define FLASH_OPTION2  rom char flash_option2 _At 0x1                                        

/*      Macros to enable and disable interrupts */

intrinsic void EI(void);
intrinsic void DI(void);
intrinsic void SET_VECTOR(int vect,void (*hndlr)(void));
intrinsic unsigned char TDI(void);
intrinsic void RI(unsigned char istat);

// Compatibility

#define _ei EI
#define _di DI
#define _setvector SET_VECTOR
#define FREQ20000	(20000000/1000)
#define FREQ18432	(18432000/1000)
#define FREQ16000	(16000000/1000)
#define FREQ14000	(14000000/1000)
#define FREQ12000	(12000000/1000)
#define FREQ08000	( 8000000/1000)
#define FREQ04000	( 4000000/1000)

extern unsigned long get_freq(void);

#define _DEFFREQ get_freq()     // the clock frequency as set in the IDE Configure Target dialog box  


void reentrant INIT_FLASH(unsigned short freq);
void reentrant WRITE_FLASH(rom const void *addr,char val);
char reentrant READ_FLASH(rom const void *addr); 

#if defined(EZ8_NVDS)
unsigned char cdecl reentrant READ_NVDS(unsigned char addr);
unsigned int  cdecl reentrant READ_NVDS_GET_STATUS(unsigned char addr);

unsigned char cdecl reentrant WRITE_NVDS(unsigned char value, unsigned char addr);

// Please note, the following alternative function names are
// DEPRECATED.  They are retained for backward
// compatibility with pre-5.4.0 ZDS II releases:
#define nvds_read             READ_NVDS
#define nvds_read_get_status  READ_NVDS
#define WRITE_NVDS_GET_STATUS WRITE_NVDS
#define nvds_write            WRITE_NVDS
#define nvds_write_get_status WRITE_NVDS

#endif

#if defined(_ZSL_PORT_USED) || defined(__ZSLBUILD)
#include <gpio.h>
#endif

#if defined(_ZSL_UART_USED) || defined(__ZSLBUILD)
#include <uart.h>
#include <dmadefs.h>
#endif

#endif


