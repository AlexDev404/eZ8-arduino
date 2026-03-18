;--------------------------------------------------------------
; Code Generation Helper
; For the Opti-C Compiler
; 
; Copyright (C) 1999-2008 by Zilog, Inc.
; All Rights Reserved
;--------------------------------------------------------------

;--------------------------------------------------------------
;
;		IEEE Single precision multiplication
;
; INPUTS:	RR0:RR2		OP1.
;		RR4:RR6		OP2.
;
; OUTPUTS:	RR0:RR2		Product.
; USES:		RR4:RR6
;
;--------------------------------------------------------------

	segment	PRAMSEG

	xref	__a_fpupop1, __a_fpupop2, __a_fppack
	xdef	__a_fpmul
	xdef	__b_fpmul
	xdef	__fpmul
	xref    __a_umul4X1
__a_fpmul:
__b_fpmul:
__fpmul:
	push	r8		;Preserve working registers.
	push	r9
	push	r10
	push	r11
	push	r12
	push	r13

	call	__a_fpupop1	;Unpack operand 1.
	jr	eq, ret_op1	;If zero just return op1.

	call	__a_fpupop2	;Unpack operand 2.
	jr	eq, ret_op2	;If operand 2 zero, ret op2.

	ld	r0, r1
	ld	r1, r2
	ld	r2, r3
	clr r3
		
	rcf	
	rlc	r7
	rlc	r6
	rlc	r5
	rlc	r4

	push r10
	push r8
	push r9
	push r7
	push r6
	push r5
	push r4
	
	clr r4
	clr r5
	clr r6
	clr r7
	clr r8

	ld  r10,#%4
mloop:
	pop r9
	call __a_umul4X1
	ld r3,r2
	ld r2,r1
	ld r1,r0
	clr r0
	djnz r10,mloop			

	rlc r7
	adc r3,r6
	adc r2,r5 
	adc r1,r4
	adc r0,r8
	 
	pop  r9
	pop  r8
	pop	 r10
	
	xor	r9, r11

	add	r8, r10
	sub	r8, #%7f		
	jr ret_op1

;CHECK FOR UNDERFLOW ETC.

	 
ret_op2:
	ld	r0, r4
	ld	r1, r5
	ld	r2, r6
	ld	r3, r7
	ld	r8, r10
	ld	r9, r11
ret_op1:
	call	__a_fppack				
cleanup:
	pop	r13
	pop	r12
	pop	r11
	pop	r10
	pop	r9
	pop	r8
	ret
