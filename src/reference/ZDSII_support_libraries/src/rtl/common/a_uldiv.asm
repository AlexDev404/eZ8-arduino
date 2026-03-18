;--------------------------------------------------------------
; Code Generation Helper
; For the Opti-C Compiler
; 
; Copyright (C) 1999-2008 by Zilog, Inc.
; All Rights Reserved
;--------------------------------------------------------------

;--------------------------------------------------------------
;
;	  	Unsigned long word division
;
; INPUTS:	RR0:RR2		32 Bit Dividend.
;		RR4:RR6		32 Bit Divisor.
;
; OUTPUTS:	RR0:RR2		32 Bit Quotient.
;		RR4:RR6		32 Bit Remainder.
;
;--------------------------------------------------------------

	segment	PRAMSEG

	xdef	__a_uldiv
	xdef	__b_uldiv
	xdef	__uldiv

__a_uldiv:
__b_uldiv:
__uldiv:	
	push	r9		;Save the working regs.
	push	r10
	push	r11
	push	r12
	push	r13
	ld	r9, #32		;Init a bit counter.
	clr	r13
	clr	r12
	clr	r11
	clr	r10
loop:
	add	r3, r3
	rlc	r2
	rlc	r1		;Rotate the num.
	rlc	r0
	rlc	r13
	rlc	r12
	rlc	r11		;Rotate the remainder.
	rlc	r10
	jr	c, over

	cp	r13, r7
	cpc	r12, r6
	cpc	r11, r5
	cpc	r10, r4
	jr	c, under
over:
	sub	r13, r7
	sbc	r12, r6
	sbc	r11, r5
	sbc	r10, r4
	inc	r3
under:
	djnz	r9, loop

	ld	r7, r13
	ld	r6, r12
	ld	r5, r11
	ld	r4, r10
	pop	r13
	pop	r12
	pop	r11
	pop	r10
	pop	r9
	ret

