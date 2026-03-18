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
; INPUTS:	RR0:RR2		Mantisa.
;		R8		Exponent.
;		R9		Sign.
;
; OUTPUTS:	RR0:RR2		IEEE float.
;
; MODIFIES:	R12		Temp.
;
;--------------------------------------------------------------

	segment	PRAMSEG

	xdef	__a_fppack
	xdef	__b_fppack
	xdef	__fppack

__a_fppack:
__b_fppack:
__fppack:
	or	r0, r0
	jr	pl, signok

	com	r0
	com	r1
	com	r2
	com	r3
	incw	rr2
	jr	ne, changesign

	incw	rr0		
changesign:
	xor	r9, #%80
signok:
	or	r0, r0
	jr	eq, ckshl

	rcf
	rrc	r0		;Perform the bit shifts.
	rrc	r1
	rrc	r2
	rrc	r3
	inc	r8		;Bump the exponent.
	jr	z, overflow	;If the exponent overflows branch.

	jr	signok
ckshl:
	ld	r12, r1
	or	r12, r2
	or	r12, r3
	jr	z, retz		
ckshl1:
	or	r1, r1
	jr	mi, finish		

	rcf	
	rlc	r3
	rlc	r2
	rlc	r1
	dec	r8
	jr	z, underflow

	jr	ckshl1
finish:
	rlc	r1
	rcf
	rrc	r8
	rrc	r1
	and	r9, #%80	;mask to just sign bit	
	or	r8, r9
	ld	r0, r8
	ret			;Exit.
retz:
	ld	r8, #0
	ret	
underflow:
overflow:
	ld	r8, #%7f
	ld	r0, #%80
	ret

