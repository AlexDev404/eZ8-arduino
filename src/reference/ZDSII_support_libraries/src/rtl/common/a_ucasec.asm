;--------------------------------------------------------------
; EZ8 Runtime Assembly Routine
; 
; Copyright (C) 1999-2008 by Zilog, Inc.
; All Rights Reserved
;--------------------------------------------------------------


        XDEF    __b_ucasec
        XDEF    __a_ucasec
        XDEF    __ucasec

	SEGMENT PRAMSEG
;
;       Performs a case statement
;
;       RR0 = case value
;	RR2 = address in ROM of table
;       R8 = type of case: 0 = normal
;                          1 = byte
;                          2 = array
;
;       Case Table format:
;
;     15                           0 
;     +----------------------------+
;     |  number of cases in table  |
;     +----------------------------+
;     |       case value 1         |  
;     +----------------------------+
;     |    case 1 handler          |
;     +----------------------------+
;     |                            |
;     /                            /
;     /                            /
;     |                            |
;     +----------------------------+
;     |       case value n         |
;     +----------------------------+
;     |     case n handler         |
;     +----------------------------+
;     |    default handler         |
;     +----------------------------+
;
__a_ucasec:
__b_ucasec:
__ucasec:
        ; Preserve temp registers
        PUSH    R4
        PUSH    R5
        PUSH    R6
        PUSH    R7

	CLR	R6
	CLR	R7

        ; Get number of case entries
        LDC     R4,@RR2
        INCW    RR2
        LDC     R5,@RR2
        INCW    RR2

LOOPTOP:
        ; See if done looping
        CP      R4,#0
        CPC     R5,#0
        JR      Z,DONE           ; No more cases to check, use default

        ; RR2 points to case value
TOP:
	CP	R8, #2
        JR	Z, ACASE
	CP	R8, #1
	JR	Z, BCASE

        LDC     R6,@RR2
        INCW    RR2
BCASE:
        LDC     R7,@RR2
        INCW    RR2
	JR	ALLCASE

ACASE:	INCW	RR6

ALLCASE:
        CP      R7,R1
        CPC     R6,R0
        JR      Z,DONE            ; Found a matching case value
NEXT:
        ; Skip case handler
        LEA     RR2,2(RR2)
        DECW    RR4             ; Decrement counter
        JR      LOOPTOP

        ; At this point RR2 points to the
        ; location in memory holding the
        ; destination.  Load the address into RR0
DONE:
        LDC     R0,@RR2
        INCW    RR2
        LDC     R1,@RR2

        ; Restore registers
        POP     R7
        POP     R6
        POP     R5
        POP     R4

        RET                             ; return to jp @RR0
        END

