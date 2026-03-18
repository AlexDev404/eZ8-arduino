;--------------------------------------------------------------
; Code Generation Helper
; For the Opti-C Compiler
; 
; Copyright (C) 1999-2008 by Zilog, Inc.
; All Rights Reserved
;--------------------------------------------------------------

;--------------------------------------------------------------
;
;	Signed/Unsigned word multiply
;	Note:	When multiplying two n-bit values, the low-order n-bits
;		of the product are the same, whether or not the values
;		are considered signed or unsigned.
;
; INPUTS:	RR0		16 Bit Multiplier.
;		RR2		16 Bit Multiplicand.
;
; OUTPUTS:	RR2		16 Bit Product.
;
;
;		 R0   R1
;	     X	 R2   R3
;	     ============
;		  C R3*R1
;	      R0*R3
;	      R2*R1
;	    =============
;		 R2    R3
;--------------------------------------------------------------

	segment PRAMSEG

	xdef	__a_uwmul,__a_swmul
	xdef	__b_uwmul,__b_swmul
	xdef	__uwmul,__swmul

__a_swmul:
__a_uwmul:
__b_swmul:
__b_uwmul:
__swmul:
__uwmul:
	push	r5		
	push	r4

	ld      r4, r3

	push    r2
	ld	r2, r1
	mult	rr2		; R1*R3

	ld	r5, r0
	mult	rr4		; R0*R3
	add	r2,r5
 
	pop     r4
	ld	r5, r1
	mult	rr4		; R2*R1
	add	r2, r5

	pop	r4
	pop	r5

	ret

