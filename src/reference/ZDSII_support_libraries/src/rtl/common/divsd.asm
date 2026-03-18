;--------------------------------------------------------------
; Z8 Encore! Runtime Assembly Routine				
; 
; Copyright (C) 1999-2008 by Zilog, Inc.
; All Rights Reserved
;--------------------------------------------------------------
 
		XREF	__swdiv

;--------------------------------------------------------------
;
;               div - Small model dynamic frames
;
;
;  Prototype:	div_t div(int numer,int denom);
;
;
;--------------------------------------------------------------

		segment CODE
		xdef	_div
_div:
		push	r15
		ldx	r15,spl                 

		ld	r0, 4(r15)	;Load the numerator		 
		ld	r1, 5(r15)	
		ld	r2, 6(r15)	;Load the denominator
		ld	r3, 7(r15)

		call	__swdiv		;Call signed word div helper.

		ld	r4, 3(r15)	;Load the address

		ld	@r4, r0		;Store the results.
		ld	1(r4), r1
		ld	2(r4), r2
		ld	3(r4), r3	

                ld      r0, r4		;Point to the results.

                pop     r15
		ret				;Exit.

;**************************** _div ***************************
		end



