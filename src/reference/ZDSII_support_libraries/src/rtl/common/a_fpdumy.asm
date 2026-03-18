;--------------------------------------------------------------
; Dumy floating point entry points
; For the Z8 Encore! Compiler
; 
; Copyright (C) 2008 by Zilog, Inc.
; All Rights Reserved
;--------------------------------------------------------------
;
;
 

	SEGMENT PRAMSEG

;
;	Code entry points
;
        XDEF __a_fpadd,__a_fpupop1,__a_fpupop2,__a_fppack,__a_fpsub,__a_fpmul,__a_fpdiv
        XDEF __a_fpultof,__a_fpltof,__a_fpftol,__a_fpneg,__a_fpcmp
 
__a_fpadd:
__a_fpupop1:
__a_fpupop2:
__a_fppack:
__a_fpsub:
__a_fpmul:
__a_fpdiv:
__a_fpultof:
__a_fpltof:
__a_fpftol:
__a_fpneg:
__a_fpcmp:
 
	RET

 
