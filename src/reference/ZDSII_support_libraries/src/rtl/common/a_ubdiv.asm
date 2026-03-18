;--------------------------------------------------------------
; Code Generation Helper
; For the Opti-C Compiler
; 
; Copyright (C) 1999-2008 by Zilog, Inc.
; All Rights Reserved
;--------------------------------------------------------------

;--------------------------------------------------------------
;
;	  	Unsigned byte division
;
; INPUTS:	R0		8 Bit Dividend.
;		R1		8 Bit Divisor.
;
; OUTPUTS:	R0		8 Bit Quotient.
;		R1		8 Bit Remainder.
;
;--------------------------------------------------------------
		
	segment	PRAMSEG
	xdef	__a_ubdiv
	xdef	__b_ubdiv
	xdef	__ubdiv

__a_ubdiv:
__b_ubdiv:
__ubdiv:	
	push	r9		;Save the working regs.
	push	r10
	ld	r9, #8		;Init a bit counter.
	clr	r10
loop:
	add	r0, r0		;Rotate the num.
	rlc	r10		;Rotate the remainder.
	jr	c, over

	cp	r10, r1
	jr	c, under
over:
	sub	r10, r1
	inc	r0
under:
	djnz	r9, loop

	ld	r1, r10
	pop	r10
	pop	r9
	ret

