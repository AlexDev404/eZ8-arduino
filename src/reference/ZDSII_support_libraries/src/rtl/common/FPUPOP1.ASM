;--------------------------------------------------------------
; Code Generation Helper
; For the Opti-C Compiler
; 
; Copyright (C) 1999-2008 by Zilog, Inc.
; All Rights Reserved
;--------------------------------------------------------------

;--------------------------------------------------------------
;
;	  	Unpack IEEE op1 of dyadic operations.
;
; INPUTS:	RR0:RR2		OP1.
;
; OUTPUTS:	RR0:RR2		Mantisa.
;		R8		Exponent.
;		R9		Sign.		
;		ZERO FLAG	Set if op was zero.
;		
;
; MODIFIES:	None
;
;--------------------------------------------------------------

	segment	CODE

	xdef	__b_fpupop1
	xdef	__fpupop1

__b_fpupop1:
__fpupop1:
	add	r1, #%80	;set carry if high-order bit
	or	r1, #%80	;set the implied bit of the mantissa.
	ld	r8, r0		;get sign & upper exponent bits
	rlc	r8		;rotate carry in, sign out
	sbc	r9, r9		;set -1 if carry, else zero
	or	r8, r8
	jr	nz, nzero	;skip if non-zero exponent

	clr	r3		;zero mantissa & carry
	clr	r2
	clr	r1
nzero:
	clr	r0
	ret

