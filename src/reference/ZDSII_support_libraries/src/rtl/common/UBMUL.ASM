;--------------------------------------------------------------
; Code Generation Helper
; For the Opti-C Compiler
; 
; Copyright (C) 1999-2008 by Zilog, Inc.
; All Rights Reserved
;--------------------------------------------------------------

;--------------------------------------------------------------
;
;	Signed/Unsigned byte multiply
;	Note:	When multiplying two n-bit values, the low-order n-bits
;		of the product are the same, whether or not the values
;		are considered signed or unsigned.
;
; INPUTS:	R0		8 Bit Multiplier.
;		R1		8 Bit Multiplicand.
;
; OUTPUTS:	R1		8 Bit Product.
;
;--------------------------------------------------------------

	segment CODE


	xdef	__b_ubmul,__b_sbmul
	xdef	__ubmul,__sbmul
__b_ubmul:
__b_sbmul:
__ubmul:
__sbmul:
	mult    rr0
	ret

