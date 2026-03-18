;--------------------------------------------------------------
; Code Generation Helper
; For the Opti-C Compiler
; 
; Copyright (C) 1999-2008 by Zilog, Inc.
; All Rights Reserved
;--------------------------------------------------------------

;--------------------------------------------------------------
;
;	  	IEEE Single precision to long.
;
; INPUTS:	RR0:RR2		IEEE Single precision.
;
; OUTPUTS:	RR0:RR2		unsigned long.
;
;--------------------------------------------------------------

		segment	PRAMSEG

		xref	__a_fpupop1
                xdef    __a_fpftol
                xdef    __b_fpftol
                xdef    __fpftol

op1hi		equ	rr0
op1lo		equ	rr2
op1byte1	equ	r0
op1byte2	equ	r1
op1byte3	equ	r2
op1byte4	equ	r3

op1exp		equ	r8
op1sign		equ	r9
temp1		equ	r12

__a_fpftol:
__b_fpftol:
__fpftol:
		push	op1exp		;Preserve working regs.
		push	op1sign
		push	temp1

		call	__a_fpupop1
		jr	eq, fexit 
		
		cp	op1exp, #%7f
		jr	ult, retz		
		
		cp	op1exp, #(%7f+31)
		jr	ugt, retmax

shiftem: 
		sub	op1exp, #(%7f+23)
		jr	eq, fexit
		jr	pl, shiftl

shiftr:
		sra	op1byte1
		rrc	op1byte2
		rrc	op1byte3
		rrc	op1byte4

		inc	op1exp
		jr	ne, shiftr
        jr  signchk

shiftl:
		rcf
		rlc	op1byte4
		rlc	op1byte3
		rlc	op1byte2
		rlc	op1byte1

		dec	op1exp
		jr	ne, shiftl

signchk:
		or	op1sign, op1sign
		jr	pl,fexit

		com	op1byte1
		com	op1byte2
		com	op1byte3
		com	op1byte4

		incw	op1lo
		jr	ne,fexit
		incw	op1hi

fexit:
		pop	temp1
		pop	op1sign
		pop	op1exp
		ret
retz:
		clr	op1byte1
		clr	op1byte2
		clr	op1byte3
		clr	op1byte4
		jr	fexit
retmax:
		ld	op1byte1, #%ff		
		ld	op1byte2, #%ff		
		ld	op1byte3, #%ff		
		ld	op1byte4, #%ff		
		jr	fexit

		end
