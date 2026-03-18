;--------------------------------------------------------------
; Generic Startup Routine for
; For the eZ8 Compiler
; 
; Copyright (C) 1999-2009 by Zilog, Inc.
; All Rights Reserved
;--------------------------------------------------------------
;
;
;
;       03-22-02        DCF             Initial version
;
        INCLUDE "ez8.inc"
        INCLUDE "CONFIGL.INC"


;*****************************************
;
;		Start of code
;
;*****************************************

	XDEF	_c_startup

;
;   vector table space allocation
;
	INCLUDE "vect.inc"
	


;
;	Reset vector
;
	VECTOR	reset=_c_startup
	 
	DEFINE startup, space=rom

	SEGMENT startup

_c_startup:

	SRP     #%E0            ; Set register pointer, working registers E0-EF 
	
IF (__Z8F648==1)

; We don't want to test for FLLDONE and FLLRDY in the simulator, which will hang here
IFDEF _SIMULATE

ELSE 
;
;Enable FLL ; then check FLL done and ready
;
FLLRDY              EQU  (1<<4) ; BIT 4 of CLKCTL5, FLL is ready
FLADONE             EQU  (1<<3) ; BIT 3 of CLKCTL5, Fast Locking Algorithm Done
FLLEN               EQU  (1<<0) ; BIT 3 of CLKCTL5, FLL enable/disable
CSTAT               EQU  (1<<7) ; BIT 7 of CLKCTL0, Lock Status

   ANDX  CLKCTL0, #~CSTAT  ;POR default state, clock control registers locked
   LDX   CLKCTL0, #%E7     ;Unlock sequence
   LDX   CLKCTL0, #%18
   ORX   CLKCTL5, #FLLEN   ;Enable FLL

$$:
   ;Wait for fast locking algorithm done and FLL locked
   TCMX  CLKCTL5, #(FLADONE|FLLRDY)   
   JR    NZ, $B
   ANDX  CLKCTL0, #~CSTAT  ;Lock the clock control registers.
ENDIF

ENDIF

;
;	Initialize hardware stack
;
 IF	INITSP
	LDX     SPL,#low(_far_stack+1)
	LDX     SPH,#high(_far_stack+1)
 ENDIF
;
;	Clear internal ram area (c_nearbss)
;
 IF CLRRRAM
	LD	R0,#_low_nearbss
	LD	R2,#_len_nearbss+1
	JR	lab4
lab3:
	CLR	@R0
	INC	R0
lab4:	DJNZ	R2,lab3
 ENDIF

;
;       Clear extended ram area (c_farbss)
;
 IF CLRERAM
	LD	R2,#high(_low_farbss)
	LD	R3,#low(_low_farbss)
	LD	R0,#high(_len_farbss+1)
	LD	R1,#low(_len_farbss+1)
	CLR	R4
	JR	lab6
lab5:
	LDX     @RR2,R4
	INCW	RR2
lab6:	DECW	RR0
	JR	NZ,lab5
 ENDIF
;
;       Clear page_E bss area
;
 IF CLRPAGEE
	LD	R2,#high(_low_pageEbss)
	LD	R3,#low(_low_pageEbss)
	LD	R0,#high(_len_pageEbss+1)
	LD	R1,#low(_len_pageEbss+1)
	CLR	R4
	JR	lab6p
lab5p:
	LDX     @RR2,R4
	INCW	RR2
lab6p:	DECW	RR0
	JR	NZ,lab5p
 ENDIF

;
;	Copy ROM data into internal RAM
;
 IF COPYRRAM
	LD	R0,#high(_low_near_romdata)
	LD	R1,#low(_low_near_romdata)
	LD	R3,#_len_neardata+1
	LD	R4,#_low_neardata
	JR	lab10
lab9:
	LDCI	@R4,@RR0
lab10:	DJNZ    R3,lab9
 ENDIF

;
;       Copy ROM data into extended RAM
;
 IF COPYERAM
	LD	R0,#high(_low_fardata)
	LD	R1,#low(_low_fardata)
	LD	R2,#high(_low_far_romdata)
	LD	R3,#low(_low_far_romdata)
	LD	R4,#high(_len_fardata+1)
	LD	R5,#low(_len_fardata+1)
	JR	lab12

lab11:
	LDC	R6,@RR2
	LDX     @RR0,R6
	INCW	RR0
	INCW	RR2
lab12:	DECW	RR4
	JR	NZ,lab11

 ENDIF

;
;       Copy ROM data into pageE RAM
;
 IF COPYPAGEE
	LD	R0,#high(_low_pageEdata)
	LD	R1,#low(_low_pageEdata)
	LD	R2,#high(_low_pageE_romdata)
	LD	R3,#low(_low_pageE_romdata)
	LD	R4,#high(_len_pageEdata+1)
	LD	R5,#low(_len_pageEdata+1)
	JR	lab12p

lab11p:
	LDC	R6,@RR2
	LDX     @RR0,R6
	INCW	RR0
	INCW	RR2
lab12p:	DECW	RR4
	JR	NZ,lab11p

 ENDIF

;
;       Copy ROM copy of code into Program RAM
;
 IF COPYPRAM
	LD	R0,#high(_low_pramseg)
	LD	R1,#low(_low_pramseg)
	LD	R2,#high(_low_pram_romdata)
	LD	R3,#low(_low_pram_romdata)
	LD	R4,#high(_len_pramseg+1)
	LD	R5,#low(_len_pramseg+1)
	JR	lab14

lab13:
	LDC	R6,@RR2
        LDC     @RR0,R6
	INCW	RR0
	INCW	RR2
lab14:	DECW	RR4
	JR	NZ,lab13
 ENDIF


;****************************************************
; Initialize the peripheral devices supported by ZSL
;****************************************************
	XREF __open_periphdevice


IF  ! __Z8F648
	CALL	__open_periphdevice
ENDIF

;	Call main
;
	XOR     R15,R15
	XOR     R14,R14
	CALL	_main

;****************************************************
; Close the peripheral devices supported by ZSL
;****************************************************
	XREF __close_periphdevice

IF  ! __Z8F648
	call    __close_periphdevice
ENDIF


        .FRAME _n_exit,$_n_exit,RDATA
        .FRAME _f_exit,$_f_exit,EDATA
_0_exit EQU     0
	XDEF _0_exit

	SEGMENT startup
	XDEF _exit
_exit:
	JR	_exit

;*****************************************
;
;		Data area
;
;*****************************************

	XREF	_main:ROM
 IF CLRRRAM
	XREF	_low_nearbss
	XREF	_len_nearbss
 ENDIF
 IF CLRERAM
	XREF	_low_farbss
	XREF	_len_farbss
 ENDIF
 IF CLRPAGEE
	XREF	_low_pageEbss
	XREF	_low_pageEbss
	XREF	_len_pageEbss
 ENDIF
 IF COPYRRAM
	XREF	_low_neardata
	XREF	_len_neardata
	XREF	_low_near_romdata
 ENDIF
 IF COPYERAM
	XREF	_low_fardata
	XREF	_len_fardata
	XREF	_low_far_romdata
 ENDIF
 IF COPYPAGEE
	XREF	_low_pageEdata
	XREF	_low_pageE_romdata
	XREF	_len_pageEdata
 ENDIF
 IF COPYPRAM
	XREF	_low_pramseg
	XREF	_len_pramseg
	XREF	_low_pram_romdata
 ENDIF
	XREF	_far_stack
	XREF	_near_stack
 
	END	_c_startup
