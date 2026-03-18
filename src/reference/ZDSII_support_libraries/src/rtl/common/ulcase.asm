;--------------------------------------------------------------
; Z8 Encore! Runtime Assembly Routine
; 
; Copyright (C) 1999-2008 by Zilog, Inc.
; All Rights Reserved
;--------------------------------------------------------------

        XDEF    __b_ulcase
        XDEF    __ulcase

	SEGMENT CODE

;
;       Performs a case statement
;
;       R0, R1, R2, R3 = case value
;	RR4 = address in ROM of table
;
;       Case Table format:
;
;     15                           0 
;     +----------------------------+
;     |  number of cases in table  |
;     +----------------------------+
;     |  case value 1-high word    |
;     +----------------------------+
;     |  case value 1-high low     |
;     +----------------------------+
;     |    case 1 handler          |
;     +----------------------------+
;     |                            |
;     /                            /
;     /                            /
;     |                            |
;     +----------------------------+
;     |  case value n-high word    |
;     +----------------------------+
;     |  case value n-high low     |
;     +----------------------------+
;     |    case n handler          |
;     +----------------------------+
;     |    default handler         |
;     +----------------------------+
;
__b_ulcase:
__ulcase:
        ; Preserve temp registers
        PUSH    R6
        PUSH    R7
        PUSH    R8
        PUSH    R9
	    PUSH    R10
	    PUSH    R11

        ; Get number of case entries
        LDC     R6,@RR4
        INCW    RR4
        LDC     R7,@RR4
        INCW    RR4

LOOPTOP:
        ; See if done looping
        CP      R6,#0
        CPC     R7,#0
        JR      Z,DONE            ; No more cases to check, use default

        ; RR4 points to case value
TOP:
        LDC     R8,@RR4
        INCW    RR4
        LDC     R9,@RR4
        INCW    RR4
	LDC	R10,@RR4
	INCW	RR4
	LDC	R11,@RR4
	INCW	RR4
        CP      R8,R0
        CPC     R9,R1
	CPC     R10,R2
	CPC     R11,R3
        JR      Z,DONE            ; Found a matching case value
NEXT:
        ; Skip case handler
        LEA     RR4,2(RR4)
        DECW    RR6             ; Decrement counter
        JR      LOOPTOP

        ; At this point RR4 points to the
        ; location in memory holding the
        ; destination
DONE:
        LDC     R0,@RR4
	INCW	RR4
        LDC     R1,@RR4

        ; Restore registers
	    POP	    R11
	    POP	    R10
        POP     R9
        POP     R8
        POP     R7
        POP     R6

        RET                             ; return to jp @RR0
        END

