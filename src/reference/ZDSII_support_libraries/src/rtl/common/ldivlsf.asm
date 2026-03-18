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
;               ldiv - Large model static frames fastcall
;
;
;  Prototype:	ldiv_t ldiv(int numer,int denom);
;
;
;--------------------------------------------------------------

		segment CODE
		xdef	_ldiv
_ldiv:
 
		ldwx	rr0, rr10		;Load the numerator		 
		ldwx	rr2, rr12	
		 
		ldx	r4, _0_ldiv		;Load the denominator
		ldx	r5, _0_ldiv+1	
		ldx	r6, _0_ldiv+2
		ldx	r7, _0_ldiv+3

		call	__sldiv			;Call signed long div helper.

		ldx	@rr8, r0		;Store the results.
		ldx	1(rr8), r1
		ldx	2(rr8), r2
		ldx	3(rr8), r3
		ldx	4(rr8), r4
		ldx	5(rr8), r5
		ldx	6(rr8), r6
		ldx	7(rr8), r7	

		ldwx	rr0, rr8
 
		ret				;Exit.

;**************************** _ldiv ***************************
		

	.FRAME _n_func,?_n_func,RDATA
	.FRAME _f_func,?_f_func,EDATA
_0_ldiv:
	DS	4

	xdef	_0_ldiv

		end


