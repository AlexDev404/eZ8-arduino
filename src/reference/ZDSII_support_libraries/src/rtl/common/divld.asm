;--------------------------------------------------------------
; Z8 Encore! Runtime Assembly Routine				
; 
; Copyright (C) 1999-2008 by Zilog, Inc.
; All Rights Reserved
;--------------------------------------------------------------
 
		XREF	__swdiv
		.include "ez8.inc"

;--------------------------------------------------------------
;
;               div - Large model dynamic frames
;
;
;  Prototype:	div_t div(int numer,int denom);
;
;
;--------------------------------------------------------------

		segment CODE
		xdef	_div
_div:
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
		ldx	r2, 8(rr14)	;Load the denominator
		ldx	r3, 9(rr14)

		call	__swdiv		;Call signed word div helper.

		ldx	r4, 4(rr14)	;Load the address
		ldx	r5, 5(rr14)

		ldx	@rr4, r0	;Store the results.
		ldx	1(rr4), r1
		ldx	2(rr4), r2
		ldx	3(rr4), r3	

ifdef __REVAA
                ld      r0, r4		;Point to the results.
		ld	r1, r5
else
		ldwx	rr0, rr4
endif
                pop     r15
                pop     r14
		ret				;Exit.

;**************************** _div ***************************
		end



