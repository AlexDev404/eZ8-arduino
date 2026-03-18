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
		push	r15
		ldx	r15,spl                 

		ld	r0, _1_ldiv		;Load the numerator		 
		ld	r1, _1_ldiv+1	
		ld	r2, _1_ldiv+2
		ld	r3, _1_ldiv+3

		ld	r4, _2_ldiv		;Load the denominator		 
		ld	r5, _2_ldiv+1	
		ld	r6, _2_ldiv+2
		ld	r7, _2_ldiv+3

		call	__sldiv			;Call signed long div helper.

		ld	r8, _0_ldiv		;Load the address

		ld	@r8, r0			;Store the results.
		ld	1(r8), r1
		ld	2(r8), r2
		ld	3(r8), r3
		ld	4(r8), r4
		ld	5(r8), r5
		ld	6(r8), r6
		ld	7(r8), r7	

                ld      r0, r8		 	;Point to the result

                ldx     spl,r15
                pop     r15
		ret				;Exit.

;**************************** _ldiv ***************************
		
	.FRAME _n_func,?_n_func,RDATA
_0_ldiv:
	DS	1
_1_ldiv:
	DS	4
_2_ldiv:
	DS	4

        xdef	_0_ldiv
	xdef	_1_ldiv
	xdef	_2_ldiv

		end
