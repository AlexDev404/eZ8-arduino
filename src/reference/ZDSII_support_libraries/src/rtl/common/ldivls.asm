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
;               ldiv - Large model static frames
;
;
;  Prototype:	ldiv_t ldiv(int numer,int denom);
;
;
;--------------------------------------------------------------

		segment CODE
		xdef	_ldiv
_ldiv:
		push	r14
		push	r15
ifdef __REVAA
		ldx	r14,sph
		ldx	r15,spl                 
else
		ldwx	rr14, SP
endif
		ldx	r0, _1_ldiv		;Load the numerator		 
		ldx	r1, _1_ldiv+1	
		ldx	r2, _1_ldiv+2
		ldx	r3, _1_ldiv+3

		ldx	r4, _2_ldiv		;Load the denominator
		ldx	r5, _2_ldiv+1	
		ldx	r6, _2_ldiv+2
		ldx	r7, _2_ldiv+3

		call	__sldiv			;Call signed long div helper.

		ldx	r8, _0_ldiv		;Load the address
		ldx	r9, _0_ldiv+1

		ldx	@rr8, r0		;Store the results.
		ldx	1(rr8), r1
		ldx	2(rr8), r2
		ldx	3(rr8), r3
		ldx	4(rr8), r4
		ldx	5(rr8), r5
		ldx	6(rr8), r6
		ldx	7(rr8), r7	

ifdef __REVAA
                ld      r0, r8		 	;Point to the results.
		ld	r1, r9

                ldx     spl,r15
                ldx     sph,r14
else
		ldwx	rr0, rr8
		ldwx	SP, rr14
endif

                pop     r15
                pop     r14
		ret				;Exit.

;**************************** _ldiv ***************************
		

	.FRAME _n_func,?_n_func,RDATA
	.FRAME _f_func,?_f_func,EDATA
_0_ldiv:
	DS	2
_1_ldiv:
	DS	4
_2_ldiv:
	DS	4
	xdef	_0_ldiv
	xdef	_1_ldiv
	xdef	_2_ldiv

		end


