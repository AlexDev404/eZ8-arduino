
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
;   R4:   Address in memory from where to load
; Output
;   RRRR4: Long loaded in register
;
;--------------------------------------------------------------

	segment CODE


	xdef	__b_ldlr4
	 
__b_ldlr4:
        push r8
        ld r8, r4
        ld r4, @r8
        ld r5, 1(r8)
        ld r6, 2(r8)
        ld r7, 3(r8)
        pop r8
        ret
