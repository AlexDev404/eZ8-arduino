
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
;   RR0:   Address in memory where to store
;   RRRR4: Long in register
;
;--------------------------------------------------------------

	segment PRAMSEG


	xdef	__b_stxlr4
	xdef	__a_stxlr4
	 
__b_stxlr4:
__a_stxlr4:
        ldx @rr0, r4
        ldx 1(rr0), r5
        ldx 2(rr0), r6
        ldx 3(rr0), r7
        ret
