
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
;   R0:   Address in memory from where to load
; Output
;   RRRR0: Long loaded in register
;
;--------------------------------------------------------------

	segment CODE


	xdef	__b_ldlr0
	 
__b_ldlr0:
        push r8
        ld r8, r0
        ld r0, @r8
        ld r1, 1(r8)
        ld r2, 2(r8)
        ld r3, 3(r8)
        pop r8
        ret
