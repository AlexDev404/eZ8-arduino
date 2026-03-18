; ufltinfo.asm
;------------------------------------------------------------------------
; __u_flt_info
;
; Parse a 4-byte float into a sign, base10 exponent and 10 BCD digits.
;
; Copyright (C) 2004-2008 by Zilog, Inc.  All rights reserved.
;------------------------------------------------------------------------

;------------------------------------------------------------------------
;	Floating Point Info
;
; Fills in a structure with information about a floating-point number.
; the information consists of the sign, the base10 exponent, and an
; array of up to MAX_DIGITS significant digits.  Here, we compute 10
; digits of accuracy, and assume that MAX_DIGITS is at least 10.
;
; This routine has a C interface as follows:
;	void _u_flt_info(double val, struct flt_info _PTR_ info);
;
; The algorithm used to produce the result is this:
; The mantissa is converted from a 24-bit (hex) integer into an
;   8-digit BCD representation.  This conversion can be performed
;   without loss of precision.  Then, the base2 exponent is forced to
;   zero by repeatedly multiplying or dividing the BCD representation
;   by 2.  
;   If multiplication by 2 causes the top byte to overflow,
;   then the BCD representation is shifted right by one digit (4
;   bits), and the base10 exponent is incremented.
;   Similarly, division by 2 may cause the digits to be shifted left
;   (in essence) and the base10 exponent to be decremented.
;

	xdef	__ufltinfo

	segment	code

;------------------------------------------------------------------------
; 
; INPUT:
;	R4:7	The IEEE 795 encoded float.
;
; OUTPUT:
;	R0:4	Ten BCD digits.
;	R10	The base10 exponent.
;	R11	The sign.
;
; Locals:
;	R12	The base2 exponent.
;	R0:3	The mantissa.
;	R4	A guard byte (2 decimal digits).
;	R5:9	Temp copy of the mantissa.
;
__ufltinfo:
	; Get the exponent into r12.
	ld	r11,r5		; Get the low-order bit,
	rl	r11		; and shift it into the carry.
	ld	r12,r4		; Get the high-order 7 bits,
	rlc	r12		; and shift in the low-order bit.

	; Get the sign into r11.
	clr	r11
	rlc	r11

	; Initialize the result to zero.
	clr	r4
	clr	r3
	clr	r2
	clr	r1
	clr	r0

	and	r5,#%7f		; Mask off the lsb of the exponent in r5.
	cp	r7,#0
	cpc	r6,#0
	cpc	r5,#0
	jr	nz,nonzero
	
	; The mantissa is zero, so the result may be 0.0 or Inf.
	clr	r10		; Set the base10 exponent to zero.

	; Check if the exponent is zero.
	cp	r12,#0
	jr	eq,zero

	; The exponent is not zero, try FF.
	cp	r12,#%ff
	jr	ne,nonzero

	; The exponent is FF, so this is Inf.
	or	r11,#2		; Set the Inf bit.
zero:
	ret

nonzero:
	; If the exponent is FF, this is NaN.
	cp	r12,#%ff
	jr	ne,not_nan

	; This is not a number (NaN).
	or	r11,#4		; Set the NaN bit.
	ret

not_nan:
	; If the exponent is zero, this is a denormalized number.
	cp	r12,#0
	jr	eq,denorm

	; Otherwise, add the implicit bit into the mantissa.
	or	r5,#%80
	dec	r12		; Denormalized numbers are offset 126, not 127.

denorm:
	; Convert the mantissa into BCD in r0 thru r3.
	call	hex2bcd
	ld	r5,r6
	call	hex2bcd
	ld	r5,r7
	call	hex2bcd

	; Now adjust the exponent.
	ld	r10,#7		; Init the base10 exponent.
	sub	r12,#21		; Exponent is offset 150 (= 1 + 21 + 128).
	jr	nc,exp_norm

exp_underflow:
	; Get a way-negative exponent back into the range of a signed char.
	call	inc_exp2
	jr	mi,exp_underflow

exp_norm:
	sub	r12,#%80

	; Now the exponent is in the range of a signed char.
	; If the base2 exponent is negative, continue to increment it
	; until it is zero.
	jr	pl,exp_nonneg
exp_neg:
	call	inc_exp2
	jr	mi,exp_neg

exp_nonneg:
	jr	z,exp_zero
exp_nonzero:
	; Decrement the base2 exponent until it is zero.
	call	times2norm
	dec	r12
	jr	nz,exp_nonzero

exp_zero:
	; One last thing.
	; The leading digit may be zero, so we have to test and shift
	; one digit left if it is.
	tm	r0,#%F0
	jr	nz,exp_ok
	call	norm_left

exp_ok:
	ret


;------------------------------------------------------------------------
; hex2bcd
;
; Append a hex byte to a BCD value.
;
; Shifts the bits from the input byte r5 into the BCD bytes r0:3.
; The decimal point is to the right of the last byte shifted in.
;
hex2bcd:
	ld	r8,#8		; Process 8 bits.
$next_bit:
	rl	r5		; Shift another bit into the carry.
	call	times2		; Multipy mantissa by two.
	djnz	r8,$next_bit	; Loop for the next bit.

	ret			; Done.


;------------------------------------------------------------------------
; inc_exp2
;
; Transfer a factor of .5 from the exponent to the mantissa, shifting
; the result left one decimal digit and decrementing the base10
; exponent if necessary.
;
inc_exp2:
	; Copy out the mantissa
	ld	r5,r0
	ld	r6,r1
	ld	r7,r2
	ld	r8,r3
	ld	r9,r4

	; Multiply by 4.
	call	times2norm
	call	times2norm

	; Add in the copy, to get a net factor of 5.
	add	r4,r9
	da	r4
	adc	r3,r8
	da	r3
	adc	r2,r7
	da	r2
	adc	r1,r6
	da	r1
	adc	r0,r5
	da	r0

	; Normalize the result, if the top byte overflowed.
	jr	nc,$no_norm
	call	norm
$no_norm:
	; So, by here, we have multiplied the mantissa by 5 and not
	; updated the exponents.  To get things right, we decrement
	; the base10 exponent, to get a factor of .5, and increment
	; the base2 exponent to get a net factor of 1.0.  The form is
	; changed, but the value is the same.
	dec	r10
	inc	r12

	ret


;------------------------------------------------------------------------
; times2norm
;
; Multiply the mantissa by 2 and shift right by one decimal digit if
; it overflows.  Also, add back in the overflow digit (1), to make the
; answer correct.
;
times2norm:
	add	r4,r4		; Multiply the guard digits by 2.
	da	r4
	call	times2		; Multiply the rest of the digits by 2.

	; Normalize if the upper byte overflowed.
	jr	nc,$nonorm
	call	norm
$nonorm:
	ret


;------------------------------------------------------------------------
; times2
;
; Multiply the mantissa by 2.
;
times2:
	adc	r3,r3	; Compute the BCD result.
	da	r3
	adc	r2,r2
	da	r2
	adc	r1,r1
	da	r1
	adc	r0,r0
	da	r0
	ret


;------------------------------------------------------------------------
; norm
;
; Shift the BCD digits right by one nibble and increment the base10
; exponent.  The overflow bit is shifted in by the very first rrc.
; After that, the carry flag is zeroed before each shift.
;
; I don't bother to try to round prior to a normalization, so this is
; not exactly IEEE 754 compliant.  Boo hoo. <THH>
;
; Note that we shift the nibbles in the addend right at the same time,
; so they will be correctly aligned when added back in.  This wastes
; time when times2norm is called directly from the main routine (since
; the addend in r5:9 is no longer used, but so what? printf is
; expected to be dog-slow anyway. <THH>
;
norm:
	ld	r13,#4		; Shift right 4 bits.
$norm1:
	rrc	r0
	rrc	r1
	rrc	r2
	rrc	r3
	rrc	r4
	rcf
	rrc	r5
	rrc	r6
	rrc	r7
	rrc	r8
	rrc	r9
	rcf
	djnz	r13,$norm1
	
	inc	r10		; Increment the base10 exponent.
	ret


;------------------------------------------------------------------------
; norm_left
;
; Shift the BCD digits left by one nibble and decrement the base10
; exponent.
;
norm_left:
	ld	r13,#4
$norm_left1:
	rl	r4
	rlc	r3
	rlc	r2
	rlc	r1
	rlc	r0
	djnz	r13,$norm_left1

	dec	r10
	ret


	end
