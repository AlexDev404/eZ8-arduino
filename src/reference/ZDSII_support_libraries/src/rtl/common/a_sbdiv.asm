;--------------------------------------------------------------
; Code Generation Helper
; For the Opti-C Compiler
	
; Copyright (C) 1999-2008 by Zilog, Inc.
; All Rights Reserved
;--------------------------------------------------------------

;--------------------------------------------------------------
;
;	  	Signed byte division
;
; INPUTS:	R0		8 Bit Dividend.
;		R1		8 Bit Divisor.
;
; OUTPUTS:	R0		8 Bit Quotient.
;		R1		8 Bit Remaindor
;
;--------------------------------------------------------------

	    	segment	PRAMSEG

		xref	__a_ubdiv
   		xdef	__a_sbdiv
   		xdef	__b_sbdiv
		xdef	__sbdiv

num		equ	r0	;Numerator.
den		equ	r1	;Denom.
sign_flag	equ	r2	;Sign reversal flag.

	
__a_sbdiv:
__b_sbdiv:
__sbdiv:	push	sign_flag
		
		ld	sign_flag, num
		xor	sign_flag, den
		and	sign_flag, #%80		;Bit 7 = div sign flag.

 		or	num, num		;Is the sign of num ok?
		jr	pl, numok		;If so branch.
		
		com	num			;Else complement the num.
		inc	num
		or	sign_flag, #%8		;Bit 3 = mod sign flag.
numok:		
		or	den, den		;Is the sign of den ok?
		jr	pl, denok		;If so branch.

		com	den			;Else complement the den.
		inc	den

denok:		call	__a_ubdiv			;Perform unsigned div.

		or	sign_flag,sign_flag	;Sign of result need ch?
		jr	pl, ckden		;If not branch.

		com	num
		inc	num
ckden:
		swap	sign_flag
		jr	pl, cleanup				

		com	den
		inc	den
cleanup:
		pop	sign_flag
		ret		

		end

