;*************************************************
;*  Copyright (C) 1999-2018 by  Zilog, Inc.
;*  All Rights Reserved
;*************************************************

	.list off
	.include "ez8dev.inc"

EZ8_SPI     SET  0
EZ8_ADC     SET  0
EZ8_TIMER3  SET  0
EZ8_TIMER4  SET  0
EZ8_UART1   SET  0
EZ8_DMA     SET  0
EZ8_PORT4   SET  0
EZ8_PORT8   SET  0
EZ8_I2C     SET  0
EZ8_PORT1   SET  0
EZ8_ADC_NEW SET  0
EZ8_PWM     SET  0
EZ8_NVDS    SET  0
EZ8_ESPI    SET  0
EZ8_MCT     SET  0
EZ8_PORT5   SET  0

; New items added for F6482
EZ8_DUAL_ESPI 			SET  0
EZ8_DUAL_ESPI_ESPI1		SET  0
EZ8_DUAL_CMP			SET  0
EZ8_DUAL_CMP_CMP1		SET  0
EZ8_ADC_NEWER 			SET  0
EZ8_DAC  				SET  0
EZ8_RTC     			SET  0
EZ8_USB     			SET  0
EZ8_CLKCTL				SET  0
EZ8_OP_AMPS_AB			SET  0
EZ8_OP_AMPS_AB_AMP_B	SET  0
EZ8_EVENT_SYS			SET  0
EZ8_DMA_NEW				SET  0
EZ8_LCD					SET  0
EZ8_AES					SET  0
EZ8_PORT9				SET  0
EZ8_IRQ4				SET  0
EZ8_PORT7				SET  0
EZ8_NO_PORT5   			SET  0

; New items added for FXX24
EZ8_TIMERA				SET 0
EZ8_REF					SET 0
EZ8_OP_AMPS_A0_A1		SET 0
EZ8_UART                SET 0
EZ8_NO_PORT3	        SET 0


EZ8_IRQ3    SET  1
EZ8_TIMER2  SET  1
EZ8_UART0   SET  1

if  (__Z8F642=1) || (__Z8F640=1)
EZ8_SPI    SET  1
EZ8_ADC    SET  1
EZ8_TIMER3 SET  1
EZ8_UART1  SET  1
EZ8_DMA    SET  1
EZ8_PORT4  SET  1
EZ8_I2C    SET  1
endif

 
if  (__Z8F08=1)  
EZ8_I2C    SET  1
endif

if  (__Z8F04A=1) 
EZ8_NVDS  SET  1
endif

if  (__Z8F04A=1) || (__Z8F04=1) 
EZ8_PORT4  SET  1
endif

if (__Z8F04A_8PIN=1) || (__Z8F0823_8PIN=1) || (__Z8F04_8PIN=1)
EZ8_PORT1  SET  1 
EZ8_IRQ3   SET  0
endif

if (__Z8F0830A=1)
EZ8_UART0  SET  0
endif

if (__Z8FMC16=1)
EZ8_ADC_NEW SET  1
EZ8_PWM     SET  1
EZ8_TIMER2  SET  0
EZ8_IRQ3    SET  0
endif

if (__Z8F1680=1) || (__Z8F648)
EZ8_TIMER3  SET  1
EZ8_I2C     SET  1
EZ8_PORT4   SET  1
EZ8_NVDS    SET  1
endif

if (__Z8F2480XH=1) || (__Z8F2480XJ=1) || (__Z8F2480XM=1) || (__Z8F2480XN=1)
EZ8_NVDS    SET  0
endif

if (__Z8F2481XH=1) || (__Z8F2481XJ=1) || (__Z8F2481XM=1) || (__Z8F2481XN=1)
EZ8_NVDS    SET  0
endif

if (__Z8F2480XH=1) || (__Z8F1680XH=1) || (__Z8F0880XH=1) || (__Z8F0480XH=1)
EZ8_ADC_NEW SET  1
endif

if (__Z8F2480XJ=1) || (__Z8F1680XJ=1) || (__Z8F0880XJ=1) || (__Z8F0480XJ=1)
EZ8_ESPI    SET  1
EZ8_ADC_NEW SET  1
endif

if (__Z8F2480XM=1) || (__Z8F1680XM=1) || (__Z8F0880XM=1) || (__Z8F0480XM=1)
EZ8_ESPI    SET  1
EZ8_UART1   SET  1
EZ8_CMP1    SET  1
EZ8_ADC_NEW SET  1
EZ8_PORT5   SET  1
endif

if (__Z8F2480XN=1) || (__Z8F1680XN=1) || (__Z8F0880XN=1) || (__Z8F0480XN=1)
EZ8_ESPI    SET  1
EZ8_UART1   SET  1
EZ8_CMP1    SET  1
EZ8_ADC_NEW SET  1
EZ8_PORT5   SET  1
EZ8_MCT     SET  1
endif

if (__Z8F2481XJ=1) || (__Z8F1681XJ=1) || (__Z8F0881XJ=1) || (__Z8F0481XJ=1)
EZ8_ESPI    SET  1
endif

if (__Z8F2481XM=1) || (__Z8F1681XM=1) || (__Z8F0881XM=1) || (__Z8F0481XM=1)
EZ8_ESPI    SET  1
EZ8_UART1   SET  1
EZ8_CMP1    SET  1
EZ8_PORT5   SET  1
endif

if (__Z8F2481XN=1) || (__Z8F1681XN=1) || (__Z8F0881XN=1) || (__Z8F0481XN=1)
EZ8_ESPI    SET  1
EZ8_UART1   SET  1
EZ8_CMP1    SET  1
EZ8_PORT5   SET  1
EZ8_MCT     SET  1
endif

if (__Z8FMC16100=1) || (__Z8FMC08100=1) || (__Z8FMC04100=1)
EZ8_I2C     SET  1
EZ8_SPI     SET  1
endif

if (__Z8F648)
EZ8_DUAL_ESPI 			SET  1
EZ8_DUAL_ESPI_ESPI1		SET  1
EZ8_UART1   			SET  1
EZ8_DUAL_CMP			SET  1
EZ8_DUAL_CMP_CMP1		SET  1
EZ8_ADC_NEWER 			SET  1
EZ8_DAC  				SET  1
EZ8_MCT					SET  1
EZ8_RTC     			SET  1
EZ8_USB     			SET  1
EZ8_CLKCTL				SET  1
EZ8_OP_AMPS_AB			SET  1
EZ8_OP_AMPS_AB_AMP_B	SET  1
EZ8_EVENT_SYS			SET  1
EZ8_DMA_NEW				SET  1
EZ8_LCD					SET  1
EZ8_AES					SET  1
EZ8_PORT5				SET  1
EZ8_IRQ4				SET  1
endif

if (__Z8FXX24)
EZ8_TIMER3				SET 1
EZ8_UART				SET 1
EZ8_DUAL_CMP			SET 1
EZ8_DUAL_CMP_CMP1		SET 1
EZ8_I2C					SET 1
EZ8_ADC_NEWER			SET 1
EZ8_ESPI				SET 1
EZ8_TIMERA				SET 1
EZ8_MCT					SET 1
EZ8_REF					SET 1
EZ8_CLKCTL				SET 1
EZ8_OP_AMPS_A0_A1		SET 1
EZ8_EVENT_SYS			SET 1
EZ8_IRQ4				SET 1
EZ8_PORT4				SET 1
EZ8_PORT5				SET 1
endif



if  (__Z8F6423=1) || (__Z8F6422=1) || (__Z8F4823=1) || \
    (__Z8F4822=1) || (__Z8F3222=1) || (__Z8F2422=1) || \
    (__Z8F1622=1) || \
    (__Z8F6403=1) || (__Z8F6402=1) || (__Z8F4803=1) || \
    (__Z8F4802=1) || (__Z8F3202=1) || (__Z8F2402=1) || \
    (__Z8F1602=1)

EZ8_TIMER4  SET  1

endif

if  (__Z8F6423=1) || (__Z8F6422=1) || (__Z8F4823=1) || \
    (__Z8F4822=1) || (__Z8F3222=1) || (__Z8F2422=1) || \
    (__Z8F1622=1) || \
    (__Z8F6403=1) || (__Z8F6402=1) || (__Z8F4803=1) || \
    (__Z8F4802=1) || (__Z8F3202=1) || (__Z8F2402=1) || \
    (__Z8F1602=1)

EZ8_PORT8   SET  1

endif


if  (__Z8F0822=1) || (__Z8F0812=1) || (__Z8F0422=1) || \
    (__Z8F0412=1)

EZ8_SPI     SET  1
 
endif

if  (__Z8F0822=1) || (__Z8F0821=1) || (__Z8F0422=1) || \
    (__Z8F0421=1)

EZ8_ADC     SET  1
 
endif


if  (__Z8F042A=1) || (__Z8F022A=1) || (__Z8F012A=1) || (__Z8F082A=1) 

EZ8_ADC     SET  1
 
endif

if  (__Z8F042AXB=1) || (__Z8F022AXB=1) || (__Z8F012AXB=1) || (__Z8F082AXB=1)

EZ8_ADC     SET  1
 
endif


if  (__Z8F0423XH=1) || (__Z8F0223XH=1) || (__Z8F0123XH=1) 

EZ8_ADC     SET  1
 
endif

if  (__Z8F0423XJ=1) || (__Z8F0223XJ=1) || (__Z8F0123XJ=1) 

EZ8_ADC     SET  1
 
endif

if  (__Z8F0423=1) || (__Z8F0223=1) || (__Z8F0123=1)

EZ8_ADC     SET  1
 
endif

if  (__Z8F0423XB=1) || (__Z8F0223XB=1) || (__Z8F0123XB=1) 

EZ8_ADC     SET  1
 
endif

if  (__Z8F0823=1) || (__Z8F0823XB=1)

EZ8_ADC     SET  1

endif


if  (__Z8F1232=1) || (__Z8F0832=1) || (__Z8F0830=1) || (__Z8F0430=1) || (__Z8F0432=1) || \
    (__Z8F0232=1) || (__Z8F0230=1) || (__Z8F0132=1) || (__Z8F0130=1)

EZ8_ADC_NEW SET  1

endif

if  (__Z8F1232=1) || (__Z8F1233=1) || (__Z8F0832=1) || (__Z8F0833=1) || (__Z8F0432=1) || \
    (__Z8F0433=1) || (__Z8F0232=1) || (__Z8F0233=1) || (__Z8F0132=1) || (__Z8F0133=1)

EZ8_NVDS    SET  0

endif

if    (__Z8F083A=1) || (__Z8F043A=1)  

EZ8_ADC_NEW SET  1

endif

if (__Z8F081A=1) || (__Z8F082A=1) || (__Z8F081AXB=1) || (__Z8F082AXB=1)

EZ8_NVDS    SET  0

endif

if (__Z8F648_64K=1)
EZ8_NVDS    SET  0
endif

if (__Z8F648_X81=1)
EZ8_LCD		SET  0
endif 

if(__Z8F648_82XR=1)
EZ8_USB		SET  0
endif

if (__Z8F648_82XR=1) || (__Z8F648_81XK=1)
EZ8_MCT					SET  0
EZ8_UART1				SET  0
EZ8_DUAL_CMP_CMP1		SET  0
EZ8_OP_AMPS_AB_AMP_B	SET  0
endif

if (__Z8F648_81XN=1) || (__Z8F648_81XK=1)
EZ8_DUAL_ESPI_ESPI1		SET  0
endif

if (__Z8F648_X82=1)
EZ8_PORT9	SET  1
endif

if(__Z8F648_81XR=1)
EZ8_PORT7	SET  1
endif

if(__Z8F648_82XR=1)
; These parts have no Port E, though they have Ports F - J!
EZ8_NO_PORT5	SET  1
endif

if (__Z8FXX24xK=1) || (__Z8FXX24xH=1)
EZ8_MCT			SET 0
EZ8_PORT5		SET 0
endif

if (__Z8FXX24xH)
EZ8_NO_PORT3	SET 1
endif




;      Special Function Registers 

T0H     EQU    %F00                ; Reset = 0x00 Timer 0 High
T0L     EQU    %F01                ; Reset = 0x01 Timer 0 Low
T0CPH   EQU    %F02                ; Reset = 0xFF Timer 0 Compare High
T0RH    EQU    %F02                ; Reset = 0xFF Timer 0 Compare High
T0CPL   EQU    %F03                ; Reset = 0xFF Timer 0 Compare Low
T0RL    EQU    %F03                ; Reset = 0xFF Timer 0 Compare Low
if (__Z8F1680=1)  || (__Z8F648=1)  || (__Z8FXX24=1)
T0PWM0H EQU    %F04                ; Reset = 0x00 Timer 0 PWM0 High
T0PWM0L EQU    %F05                ; Reset = 0x00 Timer 0 PWM0 Low
else
T0PWMH  EQU    %F04                ; Reset = 0x00 Timer 0 PWM High
T0PWML  EQU    %F05                ; Reset = 0x00 Timer 0 PWM Low
endif
if (__Z8F642=1) || (__Z8F04A=1) || (__Z8F08=1) || (__Z8F04=1) || (__Z8FMC16=1) || (__Z8F1680=1)  \
                || (__Z8F648=1) || (__Z8FXX24=1)
T0CTL0  EQU    %F06                ; Reset = 0x00 Timer 0 Control 0
T0CTL1  EQU    %F07                ; Reset = 0x00 Timer 0 Control 1
endif
T0CTL   EQU    %F07                ; Reset = 0x00 Timer 0 Control
if (__Z8FMC16=1)
ADCTCAP_H EQU  %F08                ; Reset = 0xXX Timer 0 Capture Register High Byte
ADCTCAP_L EQU  %F09                ; Reset = 0xXX Timer 0 Capture Register Low Byte
endif
if (__Z8F1680=1)  || (__Z8F648=1) || (__Z8FXX24=1)
T0PWM1H EQU    %F20                ; Reset = 0x00 Timer 0 PWM1 High
T0PWM1L EQU    %F21                ; Reset = 0x00 Timer 0 PWM1 Low
T0CTL2  EQU    %F22                ; Reset = 0x00 Timer 0 Control 2
T0STA   EQU    %F23                ; Reset = 0x00 Timer 0 Status
T0NFC   EQU    %F2C                ; Reset = 0x00 Timer 0 Noise Filter Control
endif

if EZ8_TIMER2=1
T1H     EQU    %F08                ; Reset = 0x00 Timer 1 High
T1L     EQU    %F09                ; Reset = 0x01 Timer 1 Low
T1CPH   EQU    %F0A                ; Reset = 0xFF Timer 1 Compare High
T1RH    EQU    %F0A                ; Reset = 0xFF Timer 1 Compare High
T1CPL   EQU    %F0B                ; Reset = 0xFF Timer 1 Compare Low
T1RL    EQU    %F0B                ; Reset = 0xFF Timer 1 Compare Low
if (__Z8F1680=1)  || (__Z8F648=1) || (__Z8FXX24=1)
T1PWM0H EQU    %F0C                ; Reset = 0x00 Timer 1 PWM0 High
T1PWM0L EQU    %F0D                ; Reset = 0x00 Timer 1 PWM0 Low
else
T1PWMH  EQU    %F0C                ; Reset = 0x00 Timer 1 PWM High
T1PWML  EQU    %F0D                ; Reset = 0x00 Timer 1 PWM Low
endif
if (__Z8F642=1) || (__Z8F04A=1) || (__Z8F08=1) || (__Z8F04=1) || (__Z8F1680=1)  \
                || (__Z8F648=1) || (__Z8FXX24=1)
T1CTL0  EQU    %F0E                ; Reset = 0x00 Timer 1 Control 0
T1CTL1  EQU    %F0F                ; Reset = 0x00 Timer 1 Control 1
endif
T1CTL   EQU    %F0F                ; Reset = 0x00 Timer 1 Control
if (__Z8F1680=1)  || (__Z8F648=1) || (__Z8FXX24=1)
T1PWM1H EQU    %F24                ; Reset = 0x00 Timer 1 PWM1 High
T1PWM1L EQU    %F25                ; Reset = 0x00 Timer 1 PWM1 Low
T1CTL2  EQU    %F26                ; Reset = 0x00 Timer 1 Control 2
T1STA   EQU    %F27                ; Reset = 0x00 Timer 1 Status
T1NFC   EQU    %F2D                ; Reset = 0x00 Timer 1 Noise Filter Control
endif
endif

if EZ8_TIMER3=1
T2H     EQU    %F10                ; Reset = 0x00 Timer 2 High
T2L     EQU    %F11                ; Reset = 0x01 Timer 2 Low
T2CPH   EQU    %F12                ; Reset = 0xFF Timer 2 Compare High
T2RH    EQU    %F12                ; Reset = 0xFF Timer 2 Compare High
T2CPL   EQU    %F13                ; Reset = 0xFF Timer 2 Compare Low
T2RL    EQU    %F13                ; Reset = 0xFF Timer 2 Compare Low
if (__Z8F1680=1)  || (__Z8F648=1) || (__Z8FXX24=1)
T2PWM0H EQU    %F14                ; Reset = 0x00 Timer 2 PWM0 High
T2PWM0L EQU    %F15                ; Reset = 0x00 Timer 2 PWM0 Low
else
T2PWMH  EQU    %F14                ; Reset = 0x00 Timer 2 PWM High
T2PWML  EQU    %F15                ; Reset = 0x00 Timer 2 PWM Low
endif
if (__Z8F642=1) || (__Z8F1680=1)  || (__Z8F648=1) || (__Z8FXX24=1)
T2CTL0  EQU    %F16                ; Reset = 0x00 Timer 2 Control 0
T2CTL1  EQU    %F17                ; Reset = 0x00 Timer 2 Control 1
endif
T2CTL   EQU    %F17                ; Reset = 0x00 Timer 2 Control
if (__Z8F1680=1)  || (__Z8F648=1) || (__Z8FXX24=1)
T2PWM1H EQU    %F28                ; Reset = 0x00 Timer 2 PWM1 High
T2PWM1L EQU    %F29                ; Reset = 0x00 Timer 2 PWM1 Low
T2CTL2  EQU    %F2A                ; Reset = 0x00 Timer 2 Control 2
T2STA   EQU    %F2B                ; Reset = 0x00 Timer 2 Status
T2NFC   EQU    %F2E                ; Reset = 0x00 Timer 2 Noise Filter Control
endif
endif

if EZ8_TIMER4=1
T3H     EQU    %F18                ; Reset = 0x00 Timer 3 High
T3L     EQU    %F19                ; Reset = 0x01 Timer 3 Low
T3CPH   EQU    %F1A                ; Reset = 0xFF Timer 3 Compare High
T3RH    EQU    %F1A                ; Reset = 0xFF Timer 3 Compare High
T3CPL   EQU    %F1B                ; Reset = 0xFF Timer 3 Compare Low
T3RL    EQU    %F1B                ; Reset = 0xFF Timer 3 Compare Low
T3PWMH  EQU    %F1C                ; Reset = 0x00 Timer 3 PWM High
T3PWML  EQU    %F1D                ; Reset = 0x00 Timer 3 PWM Low
if __Z8F642=1
T3CTL0  EQU    %F1E                ; Reset = 0x00 Timer 3 Control 0
T3CTL1  EQU    %F1F                ; Reset = 0x00 Timer 3 Control 1
endif
T3CTL   EQU    %F1F                ; Reset = 0x00 Timer 3 Control
endif 

if EZ8_PWM=1
PWMCTL0  EQU    %F20               ; Reset = 0x00 PWM Control 0
PWMCTL1  EQU    %F21               ; Reset = 0x00 PWM Control 1
PWMDB    EQU    %F22               ; Reset = 0x00 PWM Dead Band
PWMMPF   EQU    %F23               ; Reset = 0x00 PWM Min Pulse Width Filter
PWMFM    EQU    %F24               ; Reset = 0x00 PWM FAult Mask
PWMFSTAT EQU    %F25               ; Reset = 0x00 PWM Fault Status
PWMIN    EQU    %F26               ; Reset = 0x00 PWM Input Sample
PWMOUT   EQU    %F27               ; Reset = 0x00 PWM Output Control
PWMFCTL  EQU    %F28               ; Reset = 0x00 PWM Fault Control
CSSHR    EQU    %F29               ; Reset = 0x00 PWM Current Sense Sample & Hold
PWMSHC   EQU    %F29               ; Reset = 0x00 PWM Current Sense Sample & Hold
PWMH     EQU    %F2C               ; Reset = 0xXX PWM High Byte
PWML     EQU    %F2D               ; Reset = 0xXX PWM Low Byte
PWMRH    EQU    %F2E               ; Reset = 0xFF PWM Reload High
PWMRL    EQU    %F2F               ; Reset = 0xFF PWM Reload Low
PWMH0DH  EQU    %F30               ; Reset = 0x00 PWM0 High Side Duty Cycle Hi Byte
PWMH0DL  EQU    %F31               ; Reset = 0x00 PWM0 High Side Duty Cycle Lo Byte
PWML0DH  EQU    %F32               ; Reset = 0x00 PWM0 Low Side Duty Cycle Hi Byte
PWML0DL  EQU    %F33               ; Reset = 0x00 PWM0 Low Side Duty Cycle Lo Byte
PWMH1DH  EQU    %F34               ; Reset = 0x00 PWM1 High Side Duty Cycle Hi Byte
PWMH1DL  EQU    %F35               ; Reset = 0x00 PWM1 High Side Duty Cycle Lo Byte
PWML1DH  EQU    %F36               ; Reset = 0x00 PWM1 Low Side Duty Cycle Hi Byte
PWML1DL  EQU    %F37               ; Reset = 0x00 PWM1 Low Side Duty Cycle Lo Byte
PWMH2DH  EQU    %F38               ; Reset = 0x00 PWM2 High Side Duty Cycle Hi Byte
PWMH2DL  EQU    %F39               ; Reset = 0x00 PWM2 High Side Duty Cycle Lo Byte
PWML2DH  EQU    %F3A               ; Reset = 0x00 PWM2 Low Side Duty Cycle Hi Byte
PWML2DL  EQU    %F3B               ; Reset = 0x00 PWM2 Low Side Duty Cycle Lo Byte
endif

if EZ8_RTC=1
RTC_SEC  EQU 	%F30			; Reset = 0xXX RTC Seconds Register
RTC_MIN  EQU	%F31			; Reset = 0xXX RTC Minutes Register
RTC_HRS  EQU	%F32			; Reset = 0xXX RTC Hours Register
RTC_DOM  EQU	%F33			; Reset = 0x0X RTC Day Of Week Register
RTC_DOW  EQU	%F34			; Reset = 0xXX RTC Day Of Month Register
RTC_MON  EQU	%F35			; Reset = 0xXX RTC Month Register
RTC_YR  EQU		%F36			; Reset = 0xXX RTC Year Register
RTC_ASEC  EQU	%F37			; Reset = 0xXX RTC Alarm Seconds Register
RTC_AMIN  EQU	%F38			; Reset = 0xXX RTC Alarm Minutes Register
RTC_AHRS  EQU	%F39			; Reset = 0xXX RTC Alarm hours Register
RTC_ADOM  EQU	%F3A			; Reset = 0x0X RTC Alarm Day Of Week Register
RTC_ADOW  EQU	%F3B			; Reset = 0xXX RTC Alarm Day Of Month Register
RTC_ACTRL  EQU	%F3C			; Reset = 0x00 RTC Alarm Control Register
RTC_CAL  EQU	%F3D			; Reset = 0x00 RTC Calibration Register
RTC_TIM  EQU	%F3E			; Reset = 0x00 RTC Timing Register
RTC_CTRL  EQU	%F3F			; Reset = 0x00 RTC Control Register
endif


if EZ8_TIMERA=1
TAH     EQU     %F30              ; Reset = 0x00 Timer A High
TAL     EQU     %F31              ; Reset = 0x00 Timer A Low
TARH    EQU     %F32              ; Reset = 0xFF Timer A Reload High
TARL    EQU     %F33              ; Reset = 0xFF Timer A Reload Low
TACTL   EQU     %F34              ; Reset = 0x00 Timer A Control
TAPS    EQU     %F35              ; Reset = 0x00 Timer A Prescale
endif


if EZ8_UART0=1
U0D     EQU    %F40                ; Reset = 0xXX UART0 Data
U0TXD   EQU    %F40                ; Reset = 0xXX UART0 Data
U0RXD   EQU    %F40                ; Reset = 0xXX UART0 Data
U0STAT0 EQU    %F41                ; Reset = 0x06 UART0 Status 0
U0CTL0  EQU    %F42                ; Reset = 0x00 UART0 Control 0
U0CTL1  EQU    %F43                ; Reset = 0x00 UART0 Control 1
if (__Z8FMC16=1) || (__Z8F1680=1)  || (__Z8F648=1)
U0MDSTAT EQU   %F44                ; Reset = 0x00 UART0 Mode Select and Status
else
U0STAT1 EQU    %F44                ; Reset = 0x00 UART0 Status 1
endif
if (__Z8F642=1) || (__Z8F04A=1) || (__Z8F08=1) || (__Z8F04=1) || (__Z8FMC16=1) || (__Z8F1680=1)  || (__Z8F648=1)
U0ADDR  EQU    %F45                ; Reset = 00 UART0 Address Compare
endif
U0BRH   EQU    %F46                ; Reset = 0xFF UARTO Baud Rate High
U0BRL   EQU    %F47                ; Reset = 0xFF UARTO Baud Rate Low
endif

if EZ8_UART1=1
U1D     EQU    %F48                ; Reset = 0xXX UART 1 Data
U1TXD   EQU    %F48                ; Reset = 0xXX UART 1 Data
U1RXD   EQU    %F48                ; Reset = 0xXX UART 1 Data
U1STAT0 EQU    %F49                ; Reset = 0x0X UART1 Status 0
U1CTL0  EQU    %F4A                ; Reset = 0x00 UART1 Control 0
U1CTL1  EQU    %F4B                ; Reset = 0x00 UART1 Control 1
if (__Z8F1680=1) || (__Z8F648=1)
U1MDSTAT EQU   %F4C                ; Reset = 0x00 UART1 Mode Select and Status
else
U1STAT1 EQU    %F4C                ; Reset = 0x00 UARR1 Status 1
endif
if (__Z8F642=1) || (__Z8F1680=1) || (__Z8F648=1)
U1ADDR  EQU    %F4D                ; Reset = 00 UART1 Address Compare
endif
U1BRH   EQU    %F4E                ; Reset = 0xFF UART1 Baud Rate High
U1BRL   EQU    %F4F                ; Reset = 0xFF UART1 Baud Rate Low
endif

if EZ8_UART=1
UD     	EQU	 %F40              		; Reset = 0xXX UART Data
UTXD   	EQU	 %F40              		; Reset = 0xXX UART Data
URXD   	EQU	 %F40              		; Reset = 0xXX UART Data
USTAT0 	EQU	 %F41              		; Reset = 0x0X UART Status 0
UCTL0  	EQU	 %F42              		; Reset = 0x00 UART Control 0
UCTL1  	EQU	 %F43              		; Reset = 0x00 UART Control 1
UMDSTAT EQU	 %F44             		; Reset = 0x00 UART Mode Select and Status
UADDR  	EQU	 %F45              		; Reset = 0x00 UART Address Compare Register
UBRH   	EQU	 %F46              		; Reset = 0xFF UART Baud Rate High
UBRL   	EQU	 %F47              		; Reset = 0xFF UART Baud Rate Low
endif


if EZ8_I2C=1
I2CD    EQU    %F50                ; Reset = 0x00 I2C Data
I2CDATA EQU    %F50                ; Reset = 0x00 I2C Data
if (__Z8FMC16=1) || (__Z8F1680=1) || (__Z8F648=1) || (__Z8FXX24=1)
I2CISTAT EQU   %F51                ; Reset = 0x80 I2C Interrupt Status
else
I2CSTAT EQU    %F51                ; Reset = 0x80 I2C Status
endif
I2CCTL  EQU    %F52                ; Reset = 0x00 I2C Control
I2CBRH  EQU    %F53                ; Reset = 0xFF I2C Baud Reload High
I2CBRL  EQU    %F54                ; Reset = 0xFF I2C Baud Reload Low
if  (__Z8F642=1) || (__Z8F08=1)
I2CDST  EQU    %F55                ; Reset = 0xC0 I2C Diagnostic State
I2CDIAG EQU    %F56                ; Reset = 0x00 I2C Diagnostic
endif
if (__Z8FMC16=1) || (__Z8F1680=1) || (__Z8F648=1) || (__Z8FXX24=1)
I2CSTATE EQU   %F55                ; Reset = 0x00 I2C State
I2CMODE  EQU   %F56                ; Reset = 0x00 I2C Mode
I2CSLVAD EQU   %F57                ; Reset = 0x00 I2C Slave Address
endif
endif

if EZ8_USB=1
USBSA  EQU			%F59		; Reset = 0x00 USB Subaddress Register
USBSD  EQU			%F5A		; Reset = 0x00 USB Subdata Register
USBCTL  EQU			%F5B		; Reset = 0x00 USB Control Register
USBDMA0CTL  EQU		%F5C		; Reset = 0x00 USB DMA 0 Control Register
USBDMA1CTL  EQU		%F5D		; Reset = 0x00 USB DMA 1 Control Register
USBDMADATA  EQU		%F5E		; Reset = 0x00 USB DMA Data Register
USBIRQCTL  EQU		%F5F		; Reset = 0x00 USB Interrupt Control Register
endif

if EZ8_SPI=1
SPID    EQU    %F60                ; Reset = 0xXX SPI Data
SPIDATA EQU    %F60                ; Reset = 0xXX SPI Data
SPICTL  EQU    %F61                ; Reset = 0x00 SPI Control
SPISTAT EQU    %F62                ; Reset = 0x00 SPI Status
SPSTAT  EQU    %F62                ; Reset = 0x00 SPI Status
SPIMODE EQU    %F63                ; Reset = 0x00 SPI Mode
if (__Z8F642=1) || (__Z8F08=1) || (__Z8FMC16=1)
SPIDST  EQU    %F64                ; Reset = 0x00 SPI Diagnostic State
endif
SPIBRH  EQU    %F66                ; Reset = 0xFF SPI Baud Rate High
SPIBRL  EQU    %F67                ; Reset = 0xFF SPI Baud Rate Low
endif

if EZ8_ESPI=1
ESPIDATA  EQU  %F60                ; Reset = 0xXX ESPI Data
ESPITDCR  EQU  %F61                ; Reset = 0x00 ESPI Transmit Data Command
ESPICTL   EQU  %F62                ; Reset = 0x00 ESPI Control
ESPIMODE  EQU  %F63                ; Reset = 0x00 ESPI Mode
ESPISTAT  EQU  %F64                ; Reset = 0x81 ESPI Status
ESPISTATE EQU  %F65                ; Reset = 0x00 ESPI State
ESPIBRH   EQU  %F66                ; Reset = 0xFF ESPI Baud Rate High
ESPIBRL   EQU  %F67                ; Reset = 0xFF ESPI Baud Rate Low
endif

if EZ8_DUAL_ESPI=1
ESPI0DATA  EQU %F60              ; Reset = 0xXX ESPI 0 Data
ESPI0TDCR  EQU %F61              ; Reset = 0x00 ESPI 0 Transmit Data Command
ESPI0CTL   EQU %F62              ; Reset = 0x00 ESPI 0 Control
ESPI0MODE  EQU %F63              ; Reset = 0x00 ESPI 0 Mode
ESPI0STAT  EQU %F64              ; Reset = 0x81 ESPI 0 Status
ESPI0STATE EQU %F65              ; Reset = 0x00 ESPI 0 State
ESPI0BRH   EQU %F66              ; Reset = 0xFF ESPI 0 Baud Rate High
ESPI0BRL   EQU %F67              ; Reset = 0xFF ESPI 0 Baud Rate Low
if EZ8_DUAL_ESPI_ESPI1=1
ESPI1DATA  EQU %F68              ; Reset = 0xXX ESPI 1 Data
ESPI1TDCR  EQU %F69              ; Reset = 0x00 ESPI 1 Transmit Data Command
ESPI1CTL   EQU %F6A              ; Reset = 0x00 ESPI 1 Control
ESPI1MODE  EQU %F6B              ; Reset = 0x00 ESPI 1 Mode
ESPI1STAT  EQU %F6C              ; Reset = 0x81 ESPI 1 Status
ESPI1STATE EQU %F6D              ; Reset = 0x00 ESPI 1 State
ESPI1BRH   EQU %F6E              ; Reset = 0xFF ESPI 1 Baud Rate High
ESPI1BRL   EQU %F6F              ; Reset = 0xFF ESPI 1 Baud Rate Low
endif
endif

if EZ8_ADC=1
if (__Z8F04A=1) || (__Z8F04=1)
ADCCTL0 EQU    %F70                ; Reset = 0x00 ADC Control 0
ADCCTL1 EQU    %F71                ; Reset = 0x00 ADC Control 1
else
ACTL    EQU    %F70                ; Reset = 0x00 ADC Control
ADCCTL  EQU    %F70                ; Reset = 0x00 ADC Control
endif
ADHR    EQU    %F72                ; Reset = 0xXX ADC Data High
ADCD_H  EQU    %F72                ; Reset = 0xXX ADC Data High
ADLR    EQU    %F73                ; Reset = 0xXX ADC Data Low
ADCDL   EQU    %F73                ; Reset = 0xXX ADC Data Low
ADCD_L  EQU    %F73                ; Reset = 0xXX ADC Data Low
if (__Z8F04A=1)
ADCTHH  EQU    %F74                ; Reset = 0xFF ADC High Threshold High Byte
ADCTLH  EQU    %F76                ; Reset = 0x00 ADC Low Threshold High Byte
endif
endif

if EZ8_ADC_NEW=1
ADCCTL0 EQU    %F70                ; Reset = 0x00 ADC Control 0
if (__Z8F0830A=0)
ADCRD_H EQU    %F71                ; Reset = 0xXX ADC Raw Data High Byte
endif
ADCD_H  EQU    %F72                ; Reset = 0xXX ADC Data High
ADCD_L  EQU    %F73                ; Reset = 0xXX ADC Data Low
ADCSST  EQU    %F74                ; Reset = 0x0A ADC Sample Settling Time
ADCST   EQU    %F75                ; Reset = 0x14 ADC Sample Time
if (__Z8F0830S=0)
ADCCP   EQU    %F76                ; Reset = 0x00 ADC Clock Prescale
endif
endif

if EZ8_ADC_NEWER=1
ADCCTL0		EQU  %F70			; Reset = 0x00 ADC Control 0
ADCCTL1		EQU  %F71			; Reset = 0x00 ADC Control 1
ADCCTL2		EQU  %F72			; Reset = 0x00 ADC Control 2
ADCINSH		EQU  %F73			; Reset = 0x00 ADC Input Select High
ADCINSL		EQU  %F74			; Reset = 0x00 ADC Input Select Low
ADCOFF		EQU  %F75			; Reset = 0x00 ADC Offset Calibration
ADCD_H		EQU  %F76			; Reset = 0x00 ADC Data High
ADCD_L		EQU  %F77			; Reset = 0x00 ADC Data Low
ADCST		EQU  %F78			; Reset = 0x00 ADC Sample Time
ADCUWINH	EQU  %F79			; Reset = 0xFF ADC Upper Window Threshold High
ADCUWINL	EQU  %F7A			; Reset = 0xFF ADC Upper Window Threshold Low
ADCLWINH	EQU  %F7B			; Reset = 0x00 ADC Lower Window Threshold High
ADCLWINL	EQU  %F7C			; Reset = 0x00 ADC Lower Window Threshold Low
endif

if EZ8_DAC=1
DACCTL		EQU  %F7D			; Reset = 0x00 DAC Control 
DACD_H		EQU  %F7E			; Reset = 0x00 DAC DAta High
DACD_L		EQU  %F7F			; Reset = 0x00 DAC Data Low
endif

if EZ8_REF=1
FREFCTL		EQU   %F7D			; Reset = 0x00 Fixed Reference Control 
PREF0CTL	EQU   %F7E			; Reset = 0x00 Programmable Reference 0 Control
PREF1CTL	EQU   %F7F			; Reset = 0x00 Programmable Reference 1 Control
endif

if (__Z8F04A=1) || (__Z8F04=1) || (__Z8F1680=1) || (__Z8F648=1) || (__Z8FXX24=1)
PWRCTL0 EQU    %F80                ; Reset = 0x80 Power Control 0
if (__Z8F648=1)|| (__Z8FXX24=1)
PWRCTL1 EQU    %F81                ; Reset = 0x00 Power Control 1
endif
endif

if (__Z8F04A=1) || (__Z8F04=1) || (__Z8F1680=1) || (__Z8F648=1)
if ((__Z8F04A=1) && (__Z8F04A_8PIN=0)) || ((__Z8F04=1) && (__Z8F04_8PIN=0) && (__Z8F0823_8PIN=0)) || \
   (__Z8F1680=1)
LEDEN   EQU    %F82                ; Reset = 0x00 LED Drive Enable
LEDLVLH EQU    %F83                ; Reset = 0x00 LED Drive Level High Byte
LEDLVLL EQU    %F84                ; Reset = 0x00 LED Drive Level Low Byte
endif
if (__Z8F1680=1)
OSCCTL0 EQU    %F86                ; Reset = 0xA0 Oscillator Control 0
OSCCTL1 EQU    %F87                ; Reset = 0x00 Oscillator Control 1
else 
OSCCTL  EQU    %F86                ; Reset = 0x20 Oscillator Control
endif
if (__Z8F04A=1) || (__Z8F04=1) || (__Z8F1680=1)
CMP0    EQU    %F90                ; Reset = 0x14 Comparator 0 Control
endif
if (__Z8F1680=1)
CMP1    EQU    %F91                ; Reset = 0x14 Comparator 1 Control
endif
endif

if (__Z8FMC16=1)
OSCCTL  EQU    %F86                ; Reset = 0x20 Oscillator Control
OSCDIV  EQU    %F87                ; Reset = 0x00 Oscillator Divide
CMPOPC  EQU    %F90                ; Reset = 0x00 Comparator and Opamp control
endif

if (EZ8_CLKCTL=1)
CLKCTL0			EQU  %F82		; Reset = 0x00 Clock Control 0
CLKCTL1			EQU  %F83		; Reset = 0x01 Clock Control 1
CLKCTL2			EQU  %F84		; Reset = 0x00 Clock Control 2
CLKCTL3			EQU  %F85		; Reset = 0x08 Clock Control 3
CLKCTL4			EQU  %F86		; Reset = 0x00 Clock Control 4
CLKCTL5			EQU  %F87		; Reset = 0x05 Clock Control 5
CLKCTL6			EQU  %F88		; Reset = 0x00 Clock Control 6
CLKCTL7			EQU  %F89		; Reset = 0x00 Clock Control 7
CLKCTL8			EQU  %F8A		; Reset = 0xXX Clock Control 8
CLKCTL9			EQU  %F8B		; Reset = 0xXX Clock Control 9
if (__Z8FXX24=0)
CLKCTLA			EQU  %F8C		; Reset = 0x00 Clock Control A
CLKCTLB			EQU  %F8D		; Reset = 0x00 Clock Control B
CLKCTLC			EQU  %F8E		; Reset = 0x00 Clock Control C
endif
endif

if EZ8_DUAL_CMP=1
CMPCTL	 EQU  %F8F				; Reset = 0x00 Comparator Control
CMP0CTL0	 EQU  %F90			; Reset = 0x00 Comparator 0 Control 0
CMP0CTL1	 EQU  %F91		    ; Reset = 0x05 Comparator 0 Control 1
if EZ8_DUAL_CMP_CMP1=1
CMP1CTL0	 EQU  %F92			; Reset = 0x00 Comparator 1 Control 0 
CMP1CTL1	 EQU  %F93			; Reset = 0x03 Comparator 1 Control 1
endif
endif

if EZ8_OP_AMPS_AB=1
AMPACTL0		EQU  %F94		; Reset = 0x00 Op Amp_A Control 0
AMPACTL1		EQU  %F95 		; Reset = 0x00 Op Amp_A Control 1
if EZ8_OP_AMPS_AB_AMP_B=1
AMPBCTL0		EQU  %F96 		; Reset = 0x00 Op Amp_B Control 0 
AMPBCTL1		EQU  %F97 		; Reset = 0x00 Op Amp_B Control 1
endif
endif

if EZ8_OP_AMPS_A0_A1=1
AMPA0CTL0		EQU   %F94		; Reset = 0x00 Op Amp_A0 Control 0
AMPA0CTL1		EQU   %F95 		; Reset = 0x00 Op Amp_A0 Control 1
AMPA1CTL0		EQU   %F96 		; Reset = 0x00 Op Amp_A1 Control 0 
AMPA1CTL1		EQU   %F97 		; Reset = 0x00 Op Amp_A1 Control 1
endif


if EZ8_EVENT_SYS=1
ESSSA			EQU  %F98		; Reset = 0x00 Event System Source Subaddress
ESSSD			EQU  %F99		; Reset = 0x00 Event System Source Subdata
ESDSA			EQU  %F9A		; Reset = 0x00 Event System Destination Subaddress
ESDSD			EQU  %F9B		; Reset = 0x00 Event System Destination Subdata
endif

if EZ8_MCT=1
MCTH    EQU    %FA0                ; Reset = 0x00 MCT High
MCTL    EQU    %FA1                ; Reset = 0x00 MCT Low
MCTRH   EQU    %FA2                ; Reset = 0xFF MCT Reload High
MCTRL   EQU    %FA3                ; Reset = 0xFF MCT Reload High
MCTSA   EQU    %FA4                ; Reset = 0xXX MCT Sub Address
MCTSR0  EQU    %FA5                ; Reset = 0xXX MCT Sub Register 0
MCTSR1  EQU    %FA6                ; Reset = 0xXX MCT Sub Register 1
MCTSR2  EQU    %FA7                ; Reset = 0xXX MCT Sub Register 2
endif

if EZ8_DMA=1
D0CTL     EQU    %FB0             ; Reset = 0x00 DMA0 Control
DMA0CTL   EQU    %FB0             ; Reset = 0x00 DMA0 Control
D0IO      EQU    %FB1             ; Reset = 0xXX DMA0 I/O Address
DMA0IO    EQU    %FB1             ; Reset = 0xXX DMA0 I/O Address
D0HIGH    EQU    %FB2             ; Reset = 0xXX DMA0 End/Start Address High
DMA0H     EQU    %FB2             ; Reset = 0xXX DMA0 End/Start Address High
D0START   EQU    %FB3             ; Reset = 0xXX DMA0 Start Address Low
DMA0START EQU    %FB3             ; Reset = 0xXX DMA0 Start Address Low
D0END     EQU    %FB4             ; Reset = 0xXX DMA0 End Address Low
DMA0END   EQU    %FB4             ; Reset = 0xXX DMA0 End Address Low

D1CTL     EQU    %FB8             ; Reset = 0x00 DMA1 Control
DMA1CTL   EQU    %FB8             ; Reset = 0x00 DMA1 Control
D1IO      EQU    %FB9             ; Reset = 0xXX DMA1 I/O Address
DMA1IO    EQU    %FB9             ; Reset = 0xXX DMA1 I/O Address
D1HIGH    EQU    %FBA             ; Reset = 0xXX DMA1 End/Start Address High
DMA1H     EQU    %FBA             ; Reset = 0xXX DMA1 End/Start Address High
D1START   EQU    %FBB             ; Reset = 0xXX DMA1 Start Address Low
DMA1START EQU    %FBB             ; Reset = 0xXX DMA1 Start Address Low
D1END     EQU    %FBC             ; Reset = 0xXX DMA1 End Address Low
DMA1END   EQU    %FBC             ; Reset = 0xXX DMA1 End Address Low

DAADDR    EQU    %FBD             ; Reset = 0xXX ADC DMA Address
DMAA_ADDR EQU    %FBD             ; Reset = 0xXX ADC DMA Address
DACTL     EQU    %FBE             ; Reset = 0x00 ADC DMA Control
DMAACTL   EQU    %FBE             ; Reset = 0x00 ADC DMA Control
DSTAT     EQU    %FBF             ; Reset = 0x00 DMA Status
DMAASTAT  EQU    %FBF             ; Reset = 0x00 DMA Status
endif

if EZ8_DMA_NEW=1
DMA0SA		EQU  %FA8			; Reset = 0x00 DMA ch 0 Subregister Address
DMA0SD		EQU  %FA9			; Reset = 0x00 DMA ch 0 Subregister Data
DMA1SA		EQU  %FAA			; Reset = 0x00 DMA ch 1 Subregister Address
DMA1SD		EQU  %FAB			; Reset = 0x00 DMA ch 1 Subregister Data
DMA2SA		EQU  %FAC			; Reset = 0x00 DMA ch 2 Subregister Address
DMA2SD		EQU  %FAD			; Reset = 0x00 DMA ch 2 Subregister Data
DMA3SA		EQU  %FAE			; Reset = 0x00 DMA ch 3 Subregister Address
DMA3SD		EQU  %FAF			; Reset = 0x00 DMA ch 3 Subregister Data
DMACTL		EQU  %FB0			; Reset = 0x00 DMA Control Register
endif

if EZ8_LCD=1
LCDSA			EQU  %FB1		; Reset = 0x00 LCD Subaddress
LCDSD			EQU  %FB2		; Reset = 0xXX LCD Subdata
LCDCLK			EQU  %FB3		; Reset = 0x00 LCD Clock
LCDCTL0		    EQU  %FB4		; Reset = 0x00 LCD Control 0
LCDCTL1		    EQU  %FB5		; Reset = 0x00 LCD Control 1
LCDCTL2		    EQU  %FB6		; Reset = 0x00 LCD Control 2
LCDCTL3		    EQU  %FB7		; Reset = 0x00 LCD Control 3
endif

if EZ8_AES=1
AESDATA			EQU  %FB8		; Reset = 0xXX AES Data
AESIV			EQU  %FB8		; Reset = 0xXX AES Initialization Vector
AESKEY			EQU  %FB9		; Reset = 0xXX AES Key
AESCTL			EQU  %FBA		; Reset = 0x00 AES Control
AESSTAT			EQU  %FBB		; Reset = 0x00 AES Status
endif


IRQ0    EQU    %FC0                ; Reset = 0x00 Interrupt Request 0
IRQ0E0  EQU    %FC1                ; Reset = 0x00 IRQ0 Enable 0
IRQ0ENH EQU    %FC1                ; Reset = 0x00 IRQ0 Enable 0
IRQ0E1  EQU    %FC2                ; Reset = 0x00 IRQ0 Enable 1
IRQ0ENL EQU    %FC2                ; Reset = 0x00 IRQ0 Enable 1

IRQ1    EQU    %FC3                ; Reset = 0x00 Interrupt Request 1
IRQ1E0  EQU    %FC4                ; Reset = 0x00 IRQ1 Enable 0
IRQ1ENH EQU    %FC4                ; Reset = 0x00 IRQ1 Enable 0
IRQ1E1  EQU    %FC5                ; Reset = 0x00 IRQ1 Enable 1
IRQ1ENL EQU    %FC5                ; Reset = 0x00 IRQ1 Enable 1

if EZ8_IRQ3=1
IRQ2    EQU    %FC6                ; Reset = 0x00 Interrupt Request 2
IRQ2E0  EQU    %FC7                ; Reset = 0x00 IRQ2 Enable 0
IRQ2ENH EQU    %FC7                ; Reset = 0x00 IRQ2 Enable 0
IRQ2E1  EQU    %FC8                ; Reset = 0xXX IRQ2 Enable 1
IRQ2ENL EQU    %FC8                ; Reset = 0xXX IRQ2 Enable 1
endif

if EZ8_IRQ4=1
IRQ3    EQU    %FC9                ; Reset = 0x00 Interrupt Request 3
IRQ3E0  EQU    %FCA                ; Reset = 0x00 IRQ3 Enable 0
IRQ3ENH EQU    %FCA                ; Reset = 0x00 IRQ3 Enable 0
IRQ3E1  EQU    %FCB                ; Reset = 0xXX IRQ3 Enable 1
IRQ3ENL EQU    %FCB                ; Reset = 0xXX IRQ3 Enable 1
endif

if (__Z8FMC16=0) && (__Z8F648=0) && (__Z8FXX24=0)
IRQES   EQU    %FCD                ; Reset = 0x00 Interrupt Edge Select
endif

if (__Z8F648=1) || (__Z8FXX24=1)
IRQES   EQU  %FCC              ; Reset = 0x00 Interrupt Edge Select
IRQSS0 	EQU  %FCD              ; Reset = 0x00 Shared Interrupt Select 0
endif
if (__Z8F648=1)
IRQSS1 	EQU  %FCE              ; Reset = 0x00 Shared Interrupt Select 1
endif

if (__Z8F04A=1) || (__Z8F04=1) || (__Z8F1680=1)
IRQSS   EQU    %FCE                ; Reset = 0x00 Shared Interrupt Select
endif

if (__Z8F08=0) && (__Z8F04=0) && (__Z8F04A=0) && (__Z8F1680=0) && (__Z8FMC16=0) && (__Z8F648=0)
PS      EQU    %FCE                ; Reset = 0x00 Port Select
IRQPS   EQU    %FCE                ; Reset = 0x00 Port Select
endif

IRQCTL  EQU    %FCF                ; Reset = 0x00 Interrupt Control

PAADDR  EQU    %FD0                ; Reset = 0x00 Port A Address
PACTL   EQU    %FD1                ; Reset = 0x00 Port A Control
PAIN    EQU    %FD2                ; Reset = 0xXX Port A Input Data
PAOUT   EQU    %FD3                ; Reset = 0x00 Pot A Output Data

if EZ8_PORT1=0
PBADDR  EQU    %FD4                ; Reset = 0x00 Port B Address
PBCTL   EQU    %FD5                ; Reset = 0x00 Port B Control
PBIN    EQU    %FD6                ; Reset = 0xXX Port B Input Data
PBOUT   EQU    %FD7                ; Reset = 0x00 Port B Output Data

if EZ8_NO_PORT3=0
PCADDR  EQU    %FD8                ; Reset = 0x00 Port C Address
PCCTL   EQU    %FD9                ; Reset = 0x00 Port C Control
PCIN    EQU    %FDA                ; Reset = 0xXX Port C Input Data
PCOUT   EQU    %FDB                ; Reset = 0x00 Port C Output Data
endif


if ((EZ8_PORT4=1) && (__Z8F04=0)) || (EZ8_PORT8=1) || (EZ8_PORT5=1)
PDADDR  EQU    %FDC                ; Reset = 0x00 Port D Address
PDCTL   EQU    %FDD                ; Reset = 0x00 Port D Control
if  (__Z8F04A=0)
PDIN    EQU    %FDE                ; Reset = 0xXX Port D Input Data
endif
PDOUT   EQU    %FDF                ; Reset = 0x00 Port D Output Data
endif    ; if ((EZ8_PORT4=1) && (__Z8F04=0)) || (EZ8_PORT8=1) || (EZ8_PORT5=1)
endif    ; if EZ8_PORT1=0

if (EZ8_PORT8=1) || (EZ8_PORT5=1) || (EZ8_PORT9=1)
if (EZ8_NO_PORT5=0)
PEADDR  EQU    %FE0                ; Reset = 0x00 Port E Address
PECTL   EQU    %FE1                ; Reset = 0x00 Port E Control
PEIN    EQU    %FE2                ; Reset = 0xXX Port E Input Data
PEOUT   EQU    %FE3                ; Reset = 0x00 Port E Output Data
endif
endif

if (EZ8_PORT7=1)  || (EZ8_PORT8=1)  || (EZ8_PORT9=1)
PFADDR  EQU    %FE4                ; Reset = 0x00 Port F Address
PFCTL   EQU    %FE5                ; Reset = 0x00 Port F Control
PFIN    EQU    %FE6                ; Reset = 0xXX Port F Input Data
PFOUT   EQU    %FE7                ; Reset = 0x00 Port F Output Data

PGADDR  EQU    %FE8                ; Reset = 0x00 Port G Address
PGCTL   EQU    %FE9                ; Reset = 0x00 Port G Control
PGIN    EQU    %FEA                ; Reset = 0xXX Port G Input Data
PGOUT   EQU    %FEB                ; Reset = 0x00 Port G Output Data

endif ; if (EZ8_PORT7=1)  || (EZ8_PORT8=1)  || (EZ8_PORT9=1)

if (EZ8_PORT8=1)  || (EZ8_PORT9=1)
PHADDR  EQU    %FEC                ; Reset = 0x00 Port H Address
PHCTL   EQU    %FED                ; Reset = 0x00 Port H Control
PHIN    EQU    %FEE                ; Reset = 0xXX Port H Input Data
PHOUT   EQU    %FEF                ; Reset = 0x00 Port H Output Data
endif

if EZ8_PORT9=1
PJADDR  	EQU  %FBC              ; Reset = 0x00 Port J Address
PJCTL   	EQU  %FBD              ; Reset = 0x00 Port J Control
PJIN    	EQU  %FBE              ; Reset = 0xXX Port J Input Data
PJOUT   	EQU  %FBF              ; Reset = 0x00 Port JOutput Data
endif


if  (__Z8F04A=1) || (__Z8F04=1) || (__Z8FMC16=1) || (__Z8F1680=1) || (__Z8F648=1) \
                 || (__ZMOTION_ORIG=1) || (__Z8FXX24=1)
RSTSTAT EQU    %FF0                ; Reset = 0xX0 Watchdog Timer Status
endif

if (__Z8FMC16=0) && (__Z8F1680=0) && (__Z8F648=0) && (__Z8FXX24=0)
WDTCTL  EQU    %FF0                ; Reset = 0xX0 Watchdog Timer Control
WDTU    EQU    %FF1                ; Reset = 0xFF Watchdog Timer Reload Upper
endif

WDTH    EQU    %FF2                ; Reset = 0xFF Watchdog Timer Reload High
WDTL    EQU    %FF3                ; Reset = 0xFF Watchdog Timer Reload Low

if  (__Z8F04A=1) || (__Z8F04=1) || (__Z8FMC16=1) || (__Z8F1680=1) || (__Z8F648=1) \
                 || (__Z8FXX24=1)
TRMADR  EQU    %FF6                ; Reset = 0x00 Trim Bit Address Register
TRMDR   EQU    %FF7                ; Reset = 0x00 Trim Bit Data Register
endif

FCTL    EQU    %FF8                ; Reset = 0x00 FLASH Control
FSTAT   EQU    %FF8                ; Reset = 0x00 FLASH Status
FPS     EQU    %FF9                ; Reset = 0x00 FLASH Page Select
if (__Z8F642=1) || (__Z8F08=1)
RPS     EQU    %FF9                ; Reset = 0x00 ROM Page Select
endif
if (__Z8F642=1) || (__Z8F04A=1)  || (__Z8F08=1) || (__Z8F04=1) || (__Z8FMC16=1) \
                || (__Z8F1680=1) || (__Z8FXX24=1)
FPROT   EQU   %FF9                 ; Reset = 00 FLASH Sector Protect
endif
if (__Z8F648=1)
FBP   EQU   %FF9                 ; Reset = 00 FLASH Block Protect
endif

if (__Z8F648=0) && (__Z8FXX24=0)
FPFH    EQU    %FFA                ; Reset = 0x00 FLASH Programming Frequency High
FFREQH  EQU    %FFA                ; Reset = 0x00 FLASH Programming Frequency High
FPFL    EQU    %FFB                ; Reset = 0x00 FLASH Programming Frequency Low
FFREQL  EQU    %FFB                ; Reset = 0x00 FLASH Programming Frequency Low
endif
if (__Z8F648=1)
FPCONFIG	 EQU  %FFA          		  ; Reset = 0x00 FLASH Programming Configuration
endif

SP      EQU    %FFE                ; Stack Pointer Word

if EZ8_NVDS=1
_nvds_write  EQU  _WRITE_NVDS
_nvds_read   EQU  _READ_NVDS
	XREF _WRITE_NVDS
	XREF _READ_NVDS
endif
	.list on


