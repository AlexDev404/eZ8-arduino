

;--------------------------------------------------------------
; Code Generation Helper
; For the Z8 Encore Compiler
; 
; Copyright (C) 2008 by Zilog, Inc.
; All Rights Reserved
;--------------------------------------------------------------

;--------------------------------------------------------------
;
;	int increment
; Input
;   RR0:   Address of memory to be incremented
;
;--------------------------------------------------------------

	segment CODE


	xdef	__b_iincr
	 
__b_iincr:
        push r2  

        ldx r2, 1(rr0)
        add r2, #1
        ldx 1(rr0), r2

        ldx r2, @rr0
        adc r2, #0
        ldx @rr0, r2

        pop r2
        ret
