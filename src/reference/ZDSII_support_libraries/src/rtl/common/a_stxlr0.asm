
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
;   RR4:   Address in memory where to store
;   RRRR0: Long in register
;
;--------------------------------------------------------------

	segment PRAMSEG


	xdef	__b_stxlr0
        xdef    __a_stxlr0

__a_stxlr0:	 
__b_stxlr0:
        ldx @rr4, r0
        ldx 1(rr4), r1
        ldx 2(rr4), r2
        ldx 3(rr4), r3
        ret
