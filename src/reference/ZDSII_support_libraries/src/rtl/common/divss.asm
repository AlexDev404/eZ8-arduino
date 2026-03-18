;--------------------------------------------------------------
; Z8 Encore! Runtime Assembly Routine				
; 
; Copyright (C) 1999-2008 by Zilog, Inc.
; All Rights Reserved
;--------------------------------------------------------------
 
		XREF	__swdiv

;--------------------------------------------------------------
;
;               div - Small model static frames
;
;
;  Prototype:	div_t div(int numer,int denom);
;
;
;--------------------------------------------------------------

		segment CODE
		xdef	_div
_div:
		ld	r0, _1_div		;Load the numerator		 
		ld	r1, _1_div+1	
		ld	r2, _2_div		;Load the denominator
		ld	r3, _2_div+1

		call	__swdiv			;Call signed word div helper.

		ld	r4, _0_div		;Load the address

		ld	@r4, r0			;Store the results.
		ld	1(r4), r1
		ld	2(r4), r2
		ld	3(r4), r3	

                ld      r0, r4		 	;Point to the result

		ret				;Exit.

;**************************** _div ***************************
		
	.FRAME _n_func,?_n_func,RDATA
_0_div:
	DS	1
_1_div:
	DS	2
_2_div:
	DS	2

        xdef	_0_div
	xdef	_1_div
	xdef	_2_div

		end
