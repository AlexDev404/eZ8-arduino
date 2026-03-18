

;--------------------------------------------------------------
; Code Generation Helper
; For the Z8 Encore Compiler
; 
; Copyright (C) 2008 by Zilog, Inc.
; All Rights Reserved
;--------------------------------------------------------------

;--------------------------------------------------------------
;
;	int decrement
; Input
;   RR0:   Address of memory to be decremented
;
;--------------------------------------------------------------

	segment CODE


	xdef	__b_idecr
 
	 
__b_idecr:
        push r2        

        ldx r2, 1(rr0)
        sub r2, #1
        ldx 1(rr0), r2

        ldx r2, @rr0
        sbc r2, #0
        ldx @rr0, r2

        pop r2
        ret
