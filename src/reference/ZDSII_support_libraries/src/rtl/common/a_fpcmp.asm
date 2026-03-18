;--------------------------------------------------------------
; Code Generation Helper
; For the Opti-C Compiler
	
; Copyright (C) 1999-2008 by Zilog, Inc.
; All Rights Reserved
;--------------------------------------------------------------

;--------------------------------------------------------------
;
;	  	IEEE Single precision compare.
;
; INPUTS:	RR0:RR2		OP1.
;		RR4:RR6		OP2.
;
; OUTPUTS:	FLAGS
;
;--------------------------------------------------------------

	segment	PRAMSEG

	xdef	__a_fpcmp
	xdef	__b_fpcmp
	xdef	__fpcmp

__a_fpcmp:
__b_fpcmp:
__fpcmp:
	cp	r3, r7
	cpc	r2, r6
	cpc	r1, r5
	cpc	r0, r4
	jr	eq, exit1

	push	r12
	push	r13
	ldx	r13, flags		;save the flags.
	tm	r0, r4			;sign set only if both negative
	jr	pl, skip2		;skip if both not negative

	ld	r12, r13
	and	r13, #%CF  		;reset S, V
	tcm	r12, #%30
	jr	z, skip1		;skip if both one

	tm	r12, #%30
	jr	nz, skip2		;skip if not both zero
skip1:
	or	r13, #%20		;set minus if S=V
skip2:
	ldx	flags, r13
	pop	r13
	pop	r12
exit1:
	ret
