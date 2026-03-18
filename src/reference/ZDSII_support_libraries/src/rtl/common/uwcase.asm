;--------------------------------------------------------------
; EZ8 Runtime Assembly Routine
; 
; Copyright (C) 1999-2008 by Zilog, Inc.
; All Rights Reserved
;--------------------------------------------------------------


        XDEF    __b_uwcase
        XDEF    __uwcase
	XREF	__b_ucasec

	SEGMENT CODE
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
__b_uwcase:
__uwcase:
        ; Preserve temp registers
        PUSH    R8
 
	CLR	R8
	CALL	__b_ucasec

        POP     R8

        RET                             ; return to jp @RR0
        END

