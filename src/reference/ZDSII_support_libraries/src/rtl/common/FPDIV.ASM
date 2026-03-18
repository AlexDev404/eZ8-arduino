;--------------------------------------------------------------
; Code Generation Helper
; For the Opti-C Compiler
	
; Copyright (C) 1999-2008 by Zilog, Inc.
; All Rights Reserved
;--------------------------------------------------------------

;--------------------------------------------------------------
;
;	  	IEEE Single precision division
;
; INPUTS:	RR0:RR2		OP1.
;		RR4:RR6		OP2.
;
; OUTPUTS:	RR0:RR2		Quotient.
; USES:		RR4:RR6
;
;--------------------------------------------------------------

	segment	CODE

	xref	__b_fpupop1, __b_fpupop2, __b_fppack
	xdef	__b_fpdiv
	xdef	__fpdiv

__b_fpdiv:
__fpdiv:
	push	r8		;Preserve working registers.
	push	r9
	push	r10
	push	r11
	push	r12
	push	r13

	call	__b_fpupop2	;Unpack operand 2.
	scf
	jr	eq, div0	;If zero error.

	call	__b_fpupop1	;Unpack operand 1.
	jr	eq, ret_op1	;If operand 1 zero ret op1.

	xor	r9, r11		;Calclate the sign.
	sub	r8, r10		;Calc the exponent.
	sbc	r10, R10	;sign extend result
	add	r8, #%7f
	adc	r10, #0
	jr	z, skip		;skip OK if high-order is zero
div0:
	sbc	r8, r8
	ld	r3, r8
	ld	r2, r8
	ld	r1, r8
	clr	r0
	jr	ret_op1
skip:
	ld	r10, #24	;Init a bit counter.
loop1:
	cp	r3, r7
	cpc	r2, r6
	cpc	r1, r5
	cpc	r0, r4
	jr	c, nosub

	sub	r3, r7
	sbc	r2, r6
	sbc	r1, r5
	sbc	r0, r4
nosub:
	ccf
	rlc	r13
	rlc	r12
	rlc	r11		;can't carry out

	rlc	r3
	rlc	r2
	rlc	r1
	rlc	r0

	djnz	r10, loop1

	ld	r3, r13
	ld	r2, r12
	ld	r1, r11
	clr	r0

ret_op1:
	call	__b_fppack				
cleanup:
	pop	r13
	pop	r12
	pop	r11
	pop	r10
	pop	r9
	pop	r8
	ret
