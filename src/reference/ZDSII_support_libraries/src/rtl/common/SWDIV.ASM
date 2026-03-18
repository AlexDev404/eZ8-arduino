;--------------------------------------------------------------
; Code Generation Helper
; For the Opti-C Compiler
; 
; Copyright (C) 1999-2008 by Zilog, Inc.
; All Rights Reserved
;--------------------------------------------------------------

;--------------------------------------------------------------
;
;	  	Signed word division
;
; INPUTS:	R0:R1		16 Bit Dividend.
;		R2:R3		16 Bit Divisor.
;
; OUTPUTS:	R0:R1		16 Bit Quotient.
;		R2:R3		16 Bit Remainder.
;
;--------------------------------------------------------------

	segment	CODE

	xref	__b_uwdiv
	xdef	__b_swdiv
	xdef	__swdiv

sign_flag	equ	r4	;Sign reversal flag.

num		equ	rr0	;Numerator.
num_hi		equ	r0	;High byte of the numerator.
num_low		equ	r1	;Low byte of the numerator.

den		equ	rr2	;Denom.
den_hi		equ	r2	;High byte of the denom.
den_low		equ	r3	;Low byte of the denom.

__b_swdiv:	
__swdiv:
	push	sign_flag
		
	ld	sign_flag, num_hi
	xor	sign_flag, den_hi
	and	sign_flag, #%80		;Bit 7 = div sign flag.

	or	num_hi, num_hi		;Is the sign of num ok?
	jr	pl, numok		;If so branch.
		
	com	num_hi			;Else complement the num.
	com	num_low
	incw	num
	or	sign_flag, #%8		;Bit 3 = mod sign flag.
numok:		
	or	den_hi, den_hi		;Is the sign of den ok?
	jr	pl, denok		;If so branch.

	com	den_hi			;Else complement the den.
	com	den_low
	incw	den
denok:
	call	__b_uwdiv			;Perform unsigned div.

	or	sign_flag,sign_flag	;Sign of result need ch?
	jr	pl, ckden		;If not branch.

	com	num_low
	com	num_hi
	incw	num
ckden:
	swap	sign_flag
	jr	pl, cleanup				

	com	den_low
	com	den_hi
	incw	den
cleanup:
	pop	sign_flag
	ret		

