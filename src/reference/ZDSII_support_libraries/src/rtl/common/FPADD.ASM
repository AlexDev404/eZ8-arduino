;--------------------------------------------------------------
; Code Generation Helper
; For the Opti-C Compiler
; 
; Copyright (C) 1999-2008 by Zilog, Inc.
; All Rights Reserved
;--------------------------------------------------------------

;--------------------------------------------------------------
;
;	  	IEEE Single precision add
;
; INPUTS:	RR0:RR2		OP1.
;		RR4:RR6		OP2.
;
; OUTPUTS:	RR0:RR2		Sum.
; USES:		RR4:RR6
;
;--------------------------------------------------------------

	segment	CODE

	xref	__b_fpupop1, __b_fpupop2, __b_fppack
	xdef	__b_fpadd
	xdef	__fpadd

__b_fpadd:
__fpadd:
	push	r8		;Preserve working registers.
	push	r9
	push	r10
	push	r11
	push	r12

	call	__b_fpupop2	;Unpack operand 2.
	jr	eq, cleanup	;If zero just return op1.

	call	__b_fpupop1	;Unpack operand 1.
	jr	eq, ret_op2	;If operand 1 zero, ret op2.

	ld	r12, r8
	sub	r12, r10	;Which exp is the largest.
	jr	eq, binadd	;If the same size, just add.

	jr	c, shift_op1	;If op1 exponent less branch.

	cp	r12, #24	;Is an excessive shift indicated?
	jr	nc, ret_op1	;If so return op1.

shift_op2bytes:
	cp	r12, #%8
	jr	c, shift_op2bits
	ld	r7, r6
	ld	r6, r5
	ld	r5, r4
	sub	r12, #%8
	jr	nz, shift_op2bytes
	jr	binadd
shift_op2bits:
	rcf
	rrc	r5	;Perform the bit shifts.
	rrc	r6
	rrc	r7
	djnz	r12, shift_op2bits

	jr	binadd
shift_op1:
	com	r12
	inc	r12 
	cp	r12, #24	;Is an exessive shift indicated?
	jr	nc, ret_op2	;If so return op1.
	add	r8, r12		;Adjust op1 exponent.

shift_op1bytes:
	cp	r12, #%8
	jr	c, shift_op1bits
	ld	r3, r2
	ld	r2, r1
	ld	r1, r0
	sub	r12, #%8
	jr	nz, shift_op1bytes
	jr	binadd

shift_op1bits:
	rcf
	rrc	r1	;Perform the bit shifts.
	rrc	r2
	rrc	r3
	djnz	r12, shift_op1bits
binadd:		
	cp	r9, r11
	jr	eq, doadd

	sub	r3, r7
	sbc	r2, r6
	sbc	r1, r5
	sbc	r0, r4
	jr	ret_op1
doadd:
	add	r3, r7
	adc	r2, r6
	adc	r1, r5
	adc	r0, r4
	jr	ret_op1

ret_op2:
	ld	r0, r4
	ld	r1, r5
	ld	r2, r6
	ld	r3, r7
	ld	r8, r10
	ld	r9, r11
ret_op1:
	call	__b_fppack				
cleanup:
	pop	r12
	pop	r11
	pop	r10
	pop	r9
	pop	r8
	ret
