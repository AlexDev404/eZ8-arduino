;--------------------------------------------------------------
;
;	  	IEEE Single precision square root
;		Copyright 2003-2008 Zilog, Inc.
;
;--------------------------------------------------------------
;--------------------------------------------------------------
;
; INPUTS:
;	Operand1: 
;		  (stack) : 32 bit IEEE format
;
; OUTPUTS:
;	Result: 
;		  RR0:RR2 : 32 bit IEEE format result
;
; ALGORITHM:
;	This algorithm is very similar to that used for binary
;	division;  readers should be familiar with that
;	algorithm of repetitive compare/subtract, and shift.
;	This algorithm uses the same concepts, except that the
;	number compared/subtracted is 2*x+1, where 'x' is the
;	developing result.  Briefly, if 'y' is the input parameter,
;	and 'x' is the result developed (and subtracted out) so
;	far, then 'y - x^2' is the residual value.  If the residual
;	is greater than '2*x + 1', then we subtract that out,
;	and add one to x;  this means that the new residual is
;	'y - (x+1)^2'.  Repetitively applied with shifting, 'x^2'
;	approaches the value of 'y'.
;
; Registers Used:
;	R4-R13
;
;--------------------------------------------------------------

	segment	code

	xref	__fpupop2, __fppack
        xdef	_sqrtf

_sqrtf:
	push 	r15
	push 	r14
	ldx	r15, spl
	ldx	r14, sph
	ldx	r4, 4(rr14)	;get argument
	ldx	r5, 5(rr14)
	ldx	r6, 6(rr14)
	ldx	r7, 7(rr14)
	call	__fpupop2	;unpack argument
	jr	z,exit1

	clr	r9		;set sign positive
	ld	r8,r10		;save exponent
	clr	r13		;initialize high-order mantissa
	clr	r12
	clr	r11
	clr	r10
	srl	r8		;compute new exponent
	jr	c,nadjust	;skip if old exponent was odd

	add	r7,r7		;adjust (shift) argument
	rlc	r6
	rlc	r5
	rlc	r13
nadjust:
	adc	r8,#63		;normalize exponent
	add	r7,r7		;shift argument left
	rlc	r6
	rlc	r5
	rlc	r13
	dec	r13		;subtract initial root
	ld	r3,#1		;initialize result
	clr	r2
	clr	r1
	clr	r0
	ld	r4,#23		;set loop count
loop1:
	add	r3,r3		;shift result left
	rlc	r2
	rlc	r1
	add	r7,r7		;shift argument left
	rlc	r6
	rlc	r5
	rlc	r13
	rlc	r12
	rlc	r11
	rlc	r10
	add	r7,r7		;shift argument left
	rlc	r6
	rlc	r5
	rlc	r13
	rlc	r12
	rlc	r11
	rlc	r10
	sub	r13,r3		;result exceeds residual ?
	sbc	r12,r2
	sbc	r11,r1
	sbc	r10,r0
	jr	c,under		;no, skip

	inc	r3		;add in possible result bit
	sub	r13,r3		;result exceeds residual ?
	sbc	r12,r2
	sbc	r11,r1
	sbc	r10,r0
	jr	nc,common	;yes, done

	add	r13,r3		;reverse 2nd subtract
	adc	r12,r2
	adc	r11,r1
	adc	r10,r0
	dec	r3		;remove result bit
under:
	add	r13,r3		;reverse 1st subtract
	adc	r12,r2
	adc	r11,r1
	adc	r10,r0
common:	
	djnz	r4,loop1

	cp	r13,r3		;result exceeds residual ?
	cpc	r12,r2
	cpc	r11,r1
	cpc	r10,r0		;carry = 0 if rounding
	ccf			;set carry if rounding
	adc	r3,r4		;round (note that r4==0)
	adc	r2,r4
	adc	r1,r4
	adc	r0,r4
exit1:
	call	__fppack
	pop	r14
	pop	r15
	ret

