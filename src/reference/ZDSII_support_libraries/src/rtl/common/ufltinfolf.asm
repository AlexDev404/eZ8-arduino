; ufltinfolf.asm
;------------------------------------------------------------------------
;
; void _u_flt_info(float val, FAR_FMT_BUFFERS struct flt_info _PTR_ info);
;
;	LARGE MODEL, FAST CALLS
;
;------------------------------------------------------------------------
;
; Unpack a float into the pointed-to flt_info structure.
;	(See ufltinfo.asm for details.)
;
;------------------------------------------------------------------------
;
; Copyright (C) 2004-2008 by Zilog, Inc.  All rights reserved.
;

	xref	__frameset00
	xref	__framereset
	xref	__ufltinfo

	xdef	__u_flt_info

	segment code

__u_flt_info:
	ldwx	rr4,rr8
	ldwx	rr6,rr10
	 
        push	r13
	push	r12
	call	__ufltinfo
	pop	r12
	pop	r13

	ldx	@rr12,r11	; Store the sign.
	incw	rr12
	ldx	@rr12,r10	; Store the base10 exponent.
	incw	rr12

	; Store the ten BCD mantissa digits.
	call	unpack_bcd_l
	ld	r0,r1
	call	unpack_bcd_l
	ld	r0,r2
	call	unpack_bcd_l
	ld	r0,r3
	call	unpack_bcd_l
	ld	r0,r4
	call	unpack_bcd_l
	ret


unpack_bcd_l:
	ld	r10,r0
	swap	r10		; Get the high-order nibble,
	and	r10,#%F
	ldx	@rr12,r10	; and store it.
	incw	rr12
	and	r0,#%F		; Get the low-order nibble,
	ldx	@rr12,r0	; and store it.
	incw	rr12
	ret


	end

