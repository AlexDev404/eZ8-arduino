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
;               div - Large model fastcall
;
;
;  Prototype:	div_t div(int numer,int denom);
;
;
;--------------------------------------------------------------

		segment CODE
		xdef	_div
_div:
 		ldwx	rr0, rr10	;Load the numerator		 	
		ldwx	rr2, rr12	;Load the denominator
		 
		call	__swdiv		;Call signed word div helper.
 		 
		ldx	@rr8, r0	;Store the results.
		ldx	1(rr8), r1
		ldx	2(rr8), r2
		ldx	3(rr8), r3	
 
		ldwx	rr0, rr8
		ret				;Exit.

;**************************** _div ***************************
		end



