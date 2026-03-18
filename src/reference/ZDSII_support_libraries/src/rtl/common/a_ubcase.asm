;--------------------------------------------------------------
; EZ8 Runtime Assembly Routine
; 
; Copyright (C) 1999-2008 by Zilog, Inc.
; All Rights Reserved
;--------------------------------------------------------------


        XDEF    __b_ubcase
        XDEF    __a_ubcase
        XDEF    __ubcase
	XREF 	__a_ucasec

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
__a_ubcase:
__b_ubcase:
__ubcase:
        ; Preserve temp registers
        PUSH    R8
 
	LD	R8, #1
	CALL	__a_ucasec

        POP     R8

        RET                             ; return to jp @RR0
        END

