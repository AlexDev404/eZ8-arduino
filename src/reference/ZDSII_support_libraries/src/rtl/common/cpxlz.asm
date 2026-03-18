
;--------------------------------------------------------------
; Code Generation Helper
; For the Z8 Encore Compiler
; 
; Copyright (C) 2008 by Zilog, Inc.
; All Rights Reserved
;--------------------------------------------------------------

;--------------------------------------------------------------
;
;	compare far long with zero
; Input
;   RR0:   Address of op0
;
;
;--------------------------------------------------------------

	segment CODE


	xdef	__b_cpxlz
	 
__b_cpxlz:
        push r4

        ldx r4, 3(rr0)
        cp  r4, #0        

        ldx r4, 2(rr0)
        cpc r4, #0

        ldx r4, 1(rr0)
        cpc r4, #0

        ldx r4, @rr0
        cpc r4, #0

        pop r4
        ret
