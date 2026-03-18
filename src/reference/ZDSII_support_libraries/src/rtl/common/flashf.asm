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
  
	ldwx		FFAH, rr8

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
	ret



_WRITE_FLASH:
if (__Z8F04A == 0)
	cp		__newflash, #%1
	jr		z, newseq
	ldx		FF8H, #0	;Lock if unlocked
	ldx		FF8H, #73H	;Unlock sequence
	ldx		FF8H, #8CH	;Unlock sequence
	jr		writechar
newseq:
endif
	 
	ldx		r0, r8	;HB
	rcf
	rrc		r0 		;Get the page number in r0

	ldx		FF8H, #0	;Lock if unlocked 
	ldx		FF9H, r0  
	ldx		FF8H, #73H	;Unlock sequence
	ldx		FF8H, #8CH	;Unlock sequence
	ldx		FF9H, r0
writechar: 
 	ldc		@rr8, r10	;Save the character
 
	ldx		FF8H, #0	;Lock if unlocked 
	ret

_READ_FLASH: 
 	ldc		r0,@rr8         ;Read byte from flash and return it
	ret

