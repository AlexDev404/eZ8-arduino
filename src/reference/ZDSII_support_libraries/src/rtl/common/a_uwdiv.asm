;--------------------------------------------------------------
; Code Generation Helper
; For the Opti-C Compiler
; 
; Copyright (C) 1999-2008 by Zilog, Inc.
; All Rights Reserved
;--------------------------------------------------------------

;--------------------------------------------------------------
;
;	  	Unsigned word division
;
; INPUTS:	R0:R1		16 Bit Dividend.
;		R2:R3		16 Bit Divisor.
;
; OUTPUTS:	R0:R1		16 Bit Quotient.
;		R2:R3		16 Bit Remainder.
;
;--------------------------------------------------------------


	segment	PRAMSEG

	xdef	__a_uwdiv
	xdef	__b_uwdiv
	xdef	__uwdiv

__a_uwdiv:
__b_uwdiv:
__uwdiv:	
	push	r9		;Save the working regs.
	push	r10
	push	r11
	ld	r9, #16		;Init a bit counter.
	clr	r11
	clr	r10
loop:
	add	r1, r1
	rlc	r0		;Rotate the num.
	rlc	r11		;Rotate the remainder.
	rlc	r10
	jr	c, over

	cp	r11, r3
	cpc	r10, r2
	jr	c, under
over:
	sub	r11, r3
	sbc	r10, r2
	inc	r1
under:
	djnz	r9, loop

	ld	r3, r11
	ld	r2, r10
	pop	r11
	pop	r10
	pop	r9
	ret

