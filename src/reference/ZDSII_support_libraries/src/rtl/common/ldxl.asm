
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
;   RR0:   Address of dest
;   RR2:   Address of src
;
;
;--------------------------------------------------------------

	segment CODE


	xdef	__b_ldxl
	 
__b_ldxl:
        push r4

        ldx r4, @rr2
        ldx @rr0, r4

        ldx r4, 1(rr2)
        ldx 1(rr0),r4

        ldx r4, 2(rr2)
        ldx 2(rr0),r4

        ldx r4, 3(rr2)
        ldx 3(rr0), r4

        pop r4
        ret
