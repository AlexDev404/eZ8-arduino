
;--------------------------------------------------------------
; Code Generation Helper
; For the Z8 Encore Compiler
; 
; Copyright (C) 2008 by Zilog, Inc.
; All Rights Reserved
;--------------------------------------------------------------

;--------------------------------------------------------------
;
;	load long from far memory
; Input
;   RR0:   Address in memory from where to load
; Output
;   RRRR0: Long loaded in register
;
;--------------------------------------------------------------

	segment PRAMSEG


	xdef	__b_ldxlr0
	xdef    __a_ldxlr0
	 
__b_ldxlr0:
__a_ldxlr0:
        push r8
        push r9
        ld r8, r0
        ld r9, r1
        ldx r0, @rr8
        ldx r1, 1(rr8)
        ldx r2, 2(rr8)
        ldx r3, 3(rr8)
        pop r9
        pop r8
        ret
