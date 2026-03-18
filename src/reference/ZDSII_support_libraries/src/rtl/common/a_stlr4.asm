
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
;   R0:   Address in memory where to store
;   RRRR4: Long in register
;
;--------------------------------------------------------------

	segment PRAMSEG


	xdef	__b_stlr4
	xdef	__a_stlr4
	 
__b_stlr4:
__a_stlr4:
        ld @r0, r4
        ld 1(r0), r5
        ld 2(r0), r6
        ld 3(r0), r7
        ret
