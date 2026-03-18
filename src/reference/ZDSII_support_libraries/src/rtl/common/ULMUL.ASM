;--------------------------------------------------------------
; Code Generation Helper
; For the Opti-C Compiler
; 
; Copyright (C) 1999-2008 by Zilog, Inc.
; All Rights Reserved
;--------------------------------------------------------------

;--------------------------------------------------------------
;
;	Signed/Unsigned long word multiply
;	Note:	When multiplying two n-bit values, the low-order n-bits
;		of the product are the same, whether or not the values
;		are considered signed or unsigned.
;
; INPUTS:	RR0:RR2		32 Bit Multiplier.
;		RR4:RR6		32 Bit Multiplicand.
;
; OUTPUTS:	RR4:RR6		32 Bit Product.
;
;		R0    R1    R2	  R3
;	     X	R4    R5    R6	  R7
;	     =======================
;				 R7*R3 (R11)
;			   R7*R2
;		    R7*R1  R6*R3       (R10)
;	     R7*R0  R6*R2
;	     R6*R1  R5*R3	       (R9)
;	     R5*R2
;	     R4*R3		       (R8)
;
;--------------------------------------------------------------

	segment CODE

	xdef	__b_ulmul,__b_slmul
	xdef	__ulmul,__slmul
	xref    __b_umul4X1

__b_slmul:
__b_ulmul:
__slmul:
__ulmul:
	push r13
	push r12
	push r10
	push r9
	push r8
 
	push r4
	push r5
	push r6
	push r7
	
	clr r4
	clr r5
	clr r6
	clr r7

	ld  r10,#%4
mloop:
	pop r9
	call __b_umul4X1
        ld r0,r1
	ld r1,r2
	ld r2,r3
	clr r3
	djnz r10,mloop
	
	pop r8
	pop r9
	pop r10
	pop r12
	pop r13
	ret

	 

