;--------------------------------------------------------------
; Z8 Encore! Runtime Assembly Routine				
; 
; Copyright (C) 1999-2008 by Zilog, Inc.
; All Rights Reserved
;--------------------------------------------------------------
 
		XREF	__swdiv

;--------------------------------------------------------------
;
;               div - Small model fastcall
;
;
;  Prototype:	div_t div(int numer,int denom);
;
;
;--------------------------------------------------------------

		segment CODE
		xdef	_div
_div: 
		ld	r0, r9	        ;Load the numerator		 
		ld	r1, r10	
		ld	r2, r11		;Load the denominator
		ld	r3, r12

		call	__swdiv		;Call signed word div helper.
 
		ld	@r8, r0		;Store the results.
		ld	1(r8), r1
		ld	2(r8), r2
		ld	3(r8), r3	

                ld      r0, r8		;Point to the results.

		ret				;Exit.

;**************************** _div ***************************
		end



