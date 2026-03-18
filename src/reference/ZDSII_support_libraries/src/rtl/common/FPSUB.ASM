;--------------------------------------------------------------
; Code Generation Helper
; For the Opti-C Compiler
; 
; Copyright (C) 1999-2008 by Zilog, Inc.
; All Rights Reserved
;--------------------------------------------------------------

;--------------------------------------------------------------
;
;	  	IEEE Single precision sub
;
; INPUTS:	RR0:RR2		OP1.
;		RR4:RR6		OP2.
;
; OUTPUTS:	RR0:RR2		Sum.
;
;--------------------------------------------------------------

		segment	CODE

		xref	__b_fpadd
                xdef    __b_fpsub
                xdef    __fpsub

op2byte1	equ	r4

__b_fpsub:
__fpsub:	
		xor	op2byte1, #%80 	;Change op2 sign.
		jp	__b_fpadd		;Add the two.

		end
