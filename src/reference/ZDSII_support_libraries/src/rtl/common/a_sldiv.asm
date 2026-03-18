;--------------------------------------------------------------
; Code Generation Helper
; For the Opti-C Compiler
; 
; Copyright (C) 1999-2008 by Zilog, Inc.
; All Rights Reserved
;--------------------------------------------------------------

;--------------------------------------------------------------
;
;	  	Signed long word division
;
; INPUTS:	RR0:RR2		32 Bit Dividend.
;		RR4:RR6		32 Bit Divisor.
;
; OUTPUTS:	RR0:RR2		32 Bit Quotient.
;		RR4:RR6		32 Bit Remainder.
;
;--------------------------------------------------------------

    	segment	PRAMSEG

	xref	__a_uldiv
	xdef	__a_sldiv
	xdef	__b_sldiv
	xdef	__sldiv

__a_sldiv:
__b_sldiv:
__sldiv:	
	push	r8
		
	ld	r8, r0
	xor	r8, r4
	and	r8, #%80		;Bit 7 = div sign flag.

	or	r0, r0			;Is the sign of num ok?
	jr	pl, numok		;If so branch.
		
	or	r8, #%8			;Bit 3 = mod sign flag.
	com	r0			;Complement the num.
	com	r1
	com	r2
	com	r3

	incw	rr2
	jr	nz, numok
	incw	rr0
numok:		
	or	r4,r4			;Is the sign of den ok?
	jr	pl, denok		;If so branch.

	com	r4
	com	r5
	com	r6
	com	r7

	incw	rr6
	jr	nz, denok
	incw	rr4
denok:
	call	__a_uldiv			;Perform unsigned div.

	or	r8,r8			;Sign of result need ch?
	jr	pl, ckden		;If not branch.

	com	r0			;Complement the num.
	com	r1
	com	r2
	com	r3

	incw	rr2
	jr	nz, ckden
	incw	rr0
ckden:
	swap	r8
	jr	pl, cleanup				

	com	r4
	com	r5
	com	r6
	com	r7

	incw	rr6
	jr	nz, cleanup
	incw	rr4
cleanup:
	pop	r8
	ret		

