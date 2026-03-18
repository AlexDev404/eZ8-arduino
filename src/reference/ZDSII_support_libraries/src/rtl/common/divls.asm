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
;               div - Large model static frames
;
;
;  Prototype:	div_t div(int numer,int denom);
;
;
;--------------------------------------------------------------

		segment CODE
		xdef	_div
_div:
		ldx	r0, _1_div		;Load the numerator	 
		ldx	r1, _1_div+1	
		ldx	r2, _2_div		;Load the denominator
		ldx	r3, _2_div+1

		call	__swdiv			;Call signed word div helper.

		ldx	r4, _0_div		;Load the address
		ldx	r5, _0_div+1

		ldx	@rr4, r0		;Store the results.
		ldx	1(rr4), r1
		ldx	2(rr4), r2
		ldx	3(rr4), r3	

ifdef __REVAA
                ld      r0, r4		 	;Point to the results.
		ld	r1, r5
else
		ldwx	rr0, rr4
endif
		ret				;Exit.

;**************************** _div ***************************
		

	.FRAME _n_func,?_n_func,RDATA
	.FRAME _f_func,?_f_func,EDATA
_0_div:
	DS	2
_1_div:
	DS	2
_2_div:
	DS	2
	xdef	_0_div
	xdef	_1_div
	xdef	_2_div

		end

