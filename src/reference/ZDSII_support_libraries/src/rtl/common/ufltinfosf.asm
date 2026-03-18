; ufltinfosf.asm
;------------------------------------------------------------------------
;
; void _u_flt_info(float val, struct flt_info _PTR_ info);
;
;	SMALL MODEL, FAST CALLS
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
	 
	push	r12
	call	__ufltinfo
	pop	r12

	ld	@r12,r11	; Store the sign.
	inc	r12
	ld	@r12,r10	; Store the base10 exponent.
	inc	r12

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
	ld	@r12,r10	; and store it.
	inc	r12
	and	r0,#%F		; Get the low-order nibble,
	ld	@r12,r0	; and store it.
	inc	r12
	ret


	end

