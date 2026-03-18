;--------------------------------------------------------------
; Code Generation Helper
; For the EZ8 C Compiler
; 
; Copyright (C) 1999-2008 by Zilog, Inc.
; All Rights Reserved
;--------------------------------------------------------------
	xdef __b_umul4X1
	xdef __a_umul4X1

; input : R0,R1,R2,R3 :multiplicand
;       : R9 : multiplier
;       ; R4,R5,R6,R7 :partial result
; output: R8,R4,R5,R6,R6 :partial result updated
;       : R0,R1,R2,R3 : left shifted by 8
; temporary: R12,R13

	segment PRAMSEG

__mul1X1:
	adc r4,#0
	adc r8,#0
	ld r12,r9
	mult rr12
	ret 

__a_umul4X1:
__b_umul4X1:
	rcf
	ld r13,r3
	call __mul1X1
	add r7,r13
	adc r6,r12
	adc r5,#0
	 
	ld r13,r2
	call __mul1X1
	add r6,r13
	adc r5,r12
	 
	ld r13,r1
	call __mul1X1
	add r5,r13
	adc r4,r12
	adc r8,#0

	rcf	 
	ld r13,r0
	call __mul1X1
	add r4,r13
	adc r8,r12

	ret

