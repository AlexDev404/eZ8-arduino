; ufltinfosd.asm
;------------------------------------------------------------------------
;
; void _u_flt_info(float val, struct flt_info _PTR_ info);
;
;	SMALL DYNAMIC MODEL
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
	call	__frameset00

	ldx	r4,4(rr14)
	ldx	r5,5(rr14)
	ldx	r6,6(rr14)
	ldx	r7,7(rr14)

	call	__ufltinfo

	; Get the address of the info structure.
	ldx	r12,8(rr14)

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


	call	__framereset
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

