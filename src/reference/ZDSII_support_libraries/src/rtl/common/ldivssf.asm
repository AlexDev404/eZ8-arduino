;--------------------------------------------------------------
; Z8 Encore! Runtime Assembly Routine				
; 
; Copyright (C) 1999-2008 by Zilog, Inc.
; All Rights Reserved
;--------------------------------------------------------------
 
		XREF	__sldiv

;--------------------------------------------------------------
;
;               ldiv - Small model static frames
;
;
;  Prototype:	ldiv_t ldiv(int numer,int denom);
;
;
;--------------------------------------------------------------

		segment CODE
		xdef	_ldiv
_ldiv:
 
		ld	r0, r9			;Load the numerator		 
		ld	r1, r10	
		ld	r2, r11
		ld	r3, r12

		ld	r4, _0_ldiv		;Load the denominator		 
		ld	r5, _0_ldiv+1	
		ld	r6, _0_ldiv+2
		ld	r7, _0_ldiv+3

		call	__sldiv			;Call signed long div helper.

 
		ld	@r8, r0			;Store the results.
		ld	1(r8), r1
		ld	2(r8), r2
		ld	3(r8), r3
		ld	4(r8), r4
		ld	5(r8), r5
		ld	6(r8), r6
		ld	7(r8), r7	

                ld      r0, r8		 	;Point to the result

  		ret				;Exit.

;**************************** _ldiv ***************************
		
	.FRAME _n_func,?_n_func,RDATA
_0_ldiv:
	DS	4
 

        xdef	_0_ldiv

		end
