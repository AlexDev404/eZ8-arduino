;***************************************************************************
;               Copyright (C) 2001-2008, Zilog Inc.
;               All rights reserved
;***************************************************************************
	xdef   _WRITE_FLASH, _READ_FLASH, _INIT_FLASH

	include "ez8.inc"

if (__Z8F04A == 0)
	segment near_bss
__newflash:  ds 1
endif
	segment CODE

_INIT_FLASH:
   	push	R15			;Save Frame
	push	R14

ifdef __REVAA
	ldx		R15, SPL	;Save current stack
	ldx		R14, SPH
else
	ldwx		RR14, SP
endif
	ldx		r0, 4(rr14)	;HB
	ldx		r1, 5(rr14)	;LB

ifdef __REVAA
	ldx		FFAH, r0
	ldx		FFBH, r1
else
	ldwx		FFAH, rr0
endif

if (__Z8F04A == 0)
	ldx		FF8H, #%0   ; Ensure flash controller is locked
	ldx		FF8H, #%5E	; Select sector protect register
	ldx		r0, FF8H	; Read FSTAT
	ld		__newflash, #%0	; 
	cp		r0, #%4		; If FSTAT = 0x4 newflash else oldflash
	jr		nz, revaa	; 
	ld		__newflash, #%1	; 
	ldx		FF8H, #%0   ; Ensure flash controller is locked
revaa:
endif
	pop		R14
	pop		R15
	ret



_WRITE_FLASH:
	push	R15		;Save Frame
	push	R14

ifdef __REVAA
	ldx		R15, SPL	;Save current stack
	ldx		R14, SPH
else
	ldwx		RR14, SP
endif

if (__Z8F04A == 0)
	cp		__newflash, #%1
	jr		z, newseq
	ldx		FF8H, #0	;Lock if unlocked
	ldx		FF8H, #73H	;Unlock sequence
	ldx		FF8H, #8CH	;Unlock sequence
	jr		writechar
newseq:
endif
	 
	ldx		r0, 4(rr14)	;HB
	rcf
	rrc		r0 		;Get the page number in r0

	ldx		FF8H, #0	;Lock if unlocked 
	ldx		FF9H, r0  
	ldx		FF8H, #73H	;Unlock sequence
	ldx		FF8H, #8CH	;Unlock sequence
	ldx		FF9H, r0
writechar: 

	ldx		r2, 6(rr14)	;Grab the passed character
	ldx		r0, 4(rr14)	;HB
	ldx		r1, 5(rr14)	;LB of pointer
	ldc		@rr0, r2	;Save the character
 
	ldx		FF8H, #0	;Lock if unlocked
 
	pop		R14
	pop		R15		;Restore the frame
	ret

_READ_FLASH:
	push	R15		;Save Frame
	push	R14

ifdef __REVAA
	ldx		R15,SPL         ;Save current stack
	ldx		R14,SPH
else
	ldwx		RR14, SP
endif

	ldx		r0,4(rr14)      ;Address high
	ldx		r1,5(rr14)      ;Address low
	ldc		r0,@rr0         ;Read byte from flash and return it

	pop		R14		;Restore the frame
	pop		R15
	ret

