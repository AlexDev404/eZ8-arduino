;--------------------------------------------------------------
; Code Generation Helper
; For the Opti-C Compiler
; 
; Copyright (C) 1999-2008 by Zilog, Inc.
; All Rights Reserved
;--------------------------------------------------------------

;--------------------------------------------------------------
;
;	  	Signed long to IEEE Single precision.
;
; INPUTS:	RR0:RR2		unsigned long.
;
; OUTPUTS:	RR0:RR2		IEEE Single precision.
;
;--------------------------------------------------------------

		segment	CODE

		xref	__b_fppack
                xdef    __b_fpltof
                xdef    __fpltof

op1hi		equ	rr0
op1lo		equ	rr2
op1byte1	equ	r0
op1byte2	equ	r1
op1byte3	equ	r2
op1byte4	equ	r3

op1exp		equ	r8
op1sign		equ	r9
temp1		equ	r12

__b_fpltof:
__fpltof:
		push	op1exp		;Preserve working regs.
		push	op1sign
		push	temp1

		ld	op1exp, #(%7f+23)	;Init the exponent.
		ld	op1sign, #0		;Init the sign.

		call	__b_fppack

		pop	temp1
		pop	op1sign
		pop	op1exp

		ret

		end

