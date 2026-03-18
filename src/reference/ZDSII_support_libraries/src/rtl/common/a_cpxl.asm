
;--------------------------------------------------------------
; Code Generation Helper
; For the Z8 Encore Compiler
; 
; Copyright (C) 2008 by Zilog, Inc.
; All Rights Reserved
;--------------------------------------------------------------

;--------------------------------------------------------------
;
;	compare far long
; Input
;   RR0:   Address of op0
;   RR2:   Address of op1
;
;
;--------------------------------------------------------------

	segment PRAMSEG


	xdef	__a_cpxl, __b_cpxl
	 
__a_cpxl:
__b_cpxl:
        push r4
        push r5

        ldx r4, 3(rr0)
        ldx r5, 3(rr2)
        cp r4, r5

        ldx r4, 2(rr0)
        ldx r5, 2(rr2)
        cpc r4, r5

        ldx r4, 1(rr0)
        ldx r5, 1(rr2)
        cpc r4, r5

        ldx r4, @rr0
        ldx r5, @rr2
        cpc r4, r5

        pop r5
        pop r4
        ret
