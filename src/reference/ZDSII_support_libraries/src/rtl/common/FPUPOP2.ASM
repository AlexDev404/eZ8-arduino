;--------------------------------------------------------------
; Code Generation Helper
; For the Opti-C Compiler
; 
; Copyright (C) 1999-2008 by Zilog, Inc.
; All Rights Reserved
;--------------------------------------------------------------

;--------------------------------------------------------------
;
;	  	Unpack IEEE op2 of dyadic operations.
;
; INPUTS:	RR4:RR6		OP2.
;
; OUTPUTS:	RR4:RR6		Mantisa.
;		R10		Exponent.
;		R11		Sign.		
;		ZERO FLAG	Set if operand was zero.
;
; MODIFIES:	None
;
;--------------------------------------------------------------

	segment	CODE

	xdef	__b_fpupop2
	xdef	__fpupop2

__b_fpupop2:
__fpupop2:
	add	r5, #%80	;set carry if high-order bit
	or	r5, #%80	;set the implied bit of the mantissa.
	ld	r10, r4		;get sign & upper exponent bits
	rlc	r10		;rotate carry in, sign out
	sbc	r11, r11	;set -1 if carry, else zero
	or	r10, r10
	jr	nz, nzero	;skip if non-zero exponent

	clr	r7		;zero mantissa & carry
	clr	r6
	clr	r5
nzero:
	clr	r4
	ret

