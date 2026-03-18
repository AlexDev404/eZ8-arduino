;--------------------------------------------------------------
; Code Generation Helper
; For the Opti-C Compiler
; 
; Copyright (C) 1999-2008 by Zilog, Inc.
; All Rights Reserved
;--------------------------------------------------------------

;--------------------------------------------------------------
;
;	  	Unsigned long to IEEE Single precision.
;
; INPUTS:	RR0:RR2		unsigned long.
;
; OUTPUTS:	RR0:RR2		IEEE Single precision.
;
;--------------------------------------------------------------

		segment	PRAMSEG

		xref	__a_fppack
                xdef    __a_fpultof
                xdef    __b_fpultof
                xdef    __fpultof
                xdef    __b_fpustof
                xdef    __a_fpustof
                xdef    __fpustof

op1hi           equ     "rr0"
op1lo           equ     "rr2"
op1byte1        equ     "r0"
op1byte2        equ     "r1"
op1byte3        equ     "r2"
op1byte4        equ     "r3"

op1exp          equ     "r8"
op1sign         equ     "r9"
temp1           equ     "r12"


__a_fpustof:
__b_fpustof:
__fpustof:
		clr r0
		clr r1
__a_fpultof:
__b_fpultof:
__fpultof:
		push	op1exp		;Preserve working regs.
		push	op1sign
		push	temp1

		ld	op1exp, #(%7f+23)	;Init the exponent.
		ld	op1sign, #0		;Init the sign.

		or	op1byte1, op1byte1
		jr	pl, signok

		rcf
		rrc	op1byte1
		rrc	op1byte2
		rrc	op1byte3
		rrc	op1byte4

		inc	op1exp
signok:
		call	__a_fppack

		pop	temp1
		pop	op1sign
		pop	op1exp

		ret

		end

