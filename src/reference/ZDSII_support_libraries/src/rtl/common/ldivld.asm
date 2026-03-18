;--------------------------------------------------------------
; Z8 Encore! Runtime Assembly Routine				
; 
; Copyright (C) 1999-2008 by Zilog, Inc.
; All Rights Reserved
;--------------------------------------------------------------
 
		XREF	__sldiv
		.include "ez8.inc"

;--------------------------------------------------------------
;
;               ldiv - Large model dynamic frames
;
;
;  Prototype:	ldiv_t ldiv(long numer,long denom);
;
;
;--------------------------------------------------------------

		segment CODE
		xdef	_ldiv
_ldiv:
		push	r14
		push	r15
ifdef __REVAA
		ldx	r14,sph
		ldx	r15,spl                 
else
		ldwx	rr14, SP
endif

		ldx	r0, 6(rr14)	;Load the numerator		 
		ldx	r1, 7(rr14)	
		ldx	r2, 8(rr14)
		ldx	r3, 9(rr14)

		ldx	r4, 10(rr14)	;Load the denominator
		ldx	r5, 11(rr14)	
		ldx	r6, 12(rr14)
		ldx	r7, 13(rr14)

		call	__sldiv		;Call signed long div helper.

		ldx	r8, 4(rr14)	;Load the address
		ldx	r9, 5(rr14)

		ldx	@rr8, r0	;Store the results.
		ldx	1(rr8), r1
		ldx	2(rr8), r2
		ldx	3(rr8), r3
		ldx	4(rr8), r4
		ldx	5(rr8), r5
		ldx	6(rr8), r6
		ldx	7(rr8), r7	

ifdef __REVAA
                ld      r0, r8		;Point to the results.
		ld	r1, r9

                ldx     spl,r15
                ldx     sph,r14
else
		ldwx	rr0, rr8
		ldwx	SP, rr14
endif

                pop     r15
                pop     r14
		ret				;Exit.

;**************************** _ldiv ***************************
		end



