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
;               ldiv - Large model dynamic frames fastcall
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
 
		ldwx	rr14, SP

		ldwx	rr0, rr10	;Load the numerator		 
 		ldwx	rr2, rr12
 
		ldx	r4, 4(rr14)	;Load the denominator
		ldx	r5, 5(rr14)	
		ldx	r6, 6(rr14)
		ldx	r7, 7(rr14)

		call	__sldiv		;Call signed long div helper.

		ldx	@rr8, r0	;Store the results.
		ldx	1(rr8), r1
		ldx	2(rr8), r2
		ldx	3(rr8), r3
		ldx	4(rr8), r4
		ldx	5(rr8), r5
		ldx	6(rr8), r6
		ldx	7(rr8), r7	
 
		ldwx	rr0, rr8
		ldwx	SP, rr14

                pop     r15
                pop     r14
		ret				;Exit.

;**************************** _ldiv ***************************
		end



