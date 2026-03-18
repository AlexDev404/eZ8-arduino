
;--------------------------------------------------------------
; Code Generation Helper
; For the Z8 Encore Compiler
; 
; Copyright (C) 2008 by Zilog, Inc.
; All Rights Reserved
;--------------------------------------------------------------

;--------------------------------------------------------------
;
;	Store long into far memory
; Input
;   R4:   Address in memory where to store
;   RRRR0: Long in register
;
;--------------------------------------------------------------

	segment PRAMSEG


	xdef	__b_stlr0
	xdef	__a_stlr0
	 
__b_stlr0:
__a_stlr0:
        ld @r4, r0
        ld 1(r4), r1
        ld 2(r4), r2
        ld 3(r4), r3
        ret
