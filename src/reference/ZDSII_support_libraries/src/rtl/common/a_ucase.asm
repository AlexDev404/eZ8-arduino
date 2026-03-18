;--------------------------------------------------------------
; EZ8 Runtime Assembly Routine
; 
; Copyright (C) 1999-2008 by Zilog, Inc.
; All Rights Reserved
;--------------------------------------------------------------


        XDEF    __a_ucase
        XDEF    __b_ucase
        XDEF    __ucase

	SEGMENT PRAMSEG

;
;       Performs a case statement
;
;       RR0 = case value
;	RR2 = address in ROM of table
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
__a_ucase:
__b_ucase:
__ucase:
        ; Preserve temp registers
        PUSH    R4
        PUSH    R5
        PUSH    R6
        PUSH    R7

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
        LDC     R6,@RR2
        INCW    RR2
        LDC     R7,@RR2
        INCW    RR2
        CP      R6,R0
        CPC     R7,R1
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

