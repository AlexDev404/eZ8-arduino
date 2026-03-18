; ufltinfols.asm
;------------------------------------------------------------------------
;
; void _u_flt_info(float val, struct flt_info _PTR_ info);
;
;	LARGE STATIC MODEL
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


	xref	__ufltinfo
	
	xdef	__u_flt_info
	xdef	_0__u_flt_info, _1__u_flt_info

	segment code

__u_flt_info:
	ldx	r4,_0__u_flt_info
	ldx	r5,_0__u_flt_info+1
	ldx	r6,_0__u_flt_info+2
	ldx	r7,_0__u_flt_info+3

	call	__ufltinfo

	; Get the address of the info structure.
	ld	r12,_1__u_flt_info
	ld	r13,_1__u_flt_info+1

	ldx	@rr12,r11	; Store the sign.
	incw	rr12
	ldx	@rr12,r10	; Store the base10 exponent.
	incw	rr12

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

	
.FRAME __u_flt_info,_seg___u_flt_info,RDATA
_0__u_flt_info:
	ds	4
_1__u_flt_info:
	ds	2


	end
