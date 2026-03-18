
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
;   RR4:   Address in memory from where to load
; Output
;   RRRR4: Long loaded in register
;
;--------------------------------------------------------------

	segment PRAMSEG


	xdef	__b_ldxlr4
	xdef	__a_ldxlr4
	 
__b_ldxlr4:
__a_ldxlr4:
        push r8
        push r9
        ld r8, r4
        ld r9, r5
        ldx r4, @rr8
        ldx r5, 1(rr8)
        ldx r6, 2(rr8)
        ldx r7, 3(rr8)
        pop r9
        pop r8
        ret
