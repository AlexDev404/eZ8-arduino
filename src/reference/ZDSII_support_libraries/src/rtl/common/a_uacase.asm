;--------------------------------------------------------------
; EZ8 Runtime Assembly Routine
; 
; Copyright (C) 1999-2008 by Zilog, Inc.
; All Rights Reserved
;--------------------------------------------------------------


        XDEF    __b_uacase
        XDEF    __a_uacase
        XDEF    __uacase
	XREF	__a_ucasec

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
;     |    case 1 handler          |
;     +----------------------------+
;     |                            |
;     /                            /
;     /                            /
;     |                            |
;     +----------------------------+
;     |     case n handler         |
;     +----------------------------+
;     |    default handler         |
;     +----------------------------+
;
__a_uacase:
__b_uacase:
__uacase:
        ; Preserve temp registers
        PUSH    R8
 
	LD	R8,#2
	CALL	__a_ucasec
 
        POP     R8
        RET                             ; return to jp @RR0
        END

