;--------------------------------------------------------------
; Z8 Encore! Runtime Assembly Routine				
; 
; Copyright (C) 1999-2008 by Zilog, Inc.
; All Rights Reserved
;--------------------------------------------------------------
 
		XREF	__sldiv

;--------------------------------------------------------------
;
;               ldiv - Small model dynamic frames
;
;
;  Prototype:	ldiv_t ldiv(int numer,int denom);
;
;
;--------------------------------------------------------------

		segment CODE
		xdef	_ldiv
_ldiv:
		push	r15
		ldx	r15,spl                 

		ld	r0, 4(r15)	;Load the numerator		 
		ld	r1, 5(r15)	
		ld	r2, 6(r15)
		ld	r3, 7(r15)

		ld	r4, 8(r15)	;Load the denominator
		ld	r5, 9(r15)	
		ld	r6, 10(r15)
		ld	r7, 11(r15)

		call	__sldiv		;Call signed long div helper.

		ld	r8, 3(r15)	;Load the address

		ld	@r8, r0		;Store the results.
		ld	1(r8), r1
		ld	2(r8), r2
		ld	3(r8), r3
		ld	4(r8), r4
		ld	5(r8), r5
		ld	6(r8), r6
		ld	7(r8), r7	

                ld      r0, r8		;Point to the results.

                ldx     spl,r15
                pop     r15
		ret				;Exit.

;**************************** _ldiv ***************************
		end



