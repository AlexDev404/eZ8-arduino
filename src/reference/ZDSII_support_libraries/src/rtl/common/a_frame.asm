;--------------------------------------------------------------
; Code Generation Helper
; For the Z8 Encore! Compiler
; 
; Copyright 2004-2008 by Zilog, Inc.
; All Rights Reserved
;--------------------------------------------------------------


   XDEF __a_frameset, __a_frameset0, __a_frameset00
   XDEF __a_iframeset00
   XDEF __frameset, __frameset0, __frameset00
   XDEF __iframeset00
   XDEF __b_frameset, __b_frameset0, __b_frameset00
   XDEF __b_iframeset00
   XREF __intrp
   .include "ez8.inc"


  SEGMENT PRAMSEG

__a_iframeset00:
__b_iframeset00:
__iframeset00:
  LDX   RP, __intrp
  ADDX  __intrp, #16
__a_frameset00:
__b_frameset00:
__frameset00:
 CLR    R5
__a_frameset0:
__b_frameset0:
__frameset0:
 CLR    R4
__a_frameset:
__b_frameset:
__frameset:
 POP    R6
 POP	R7
 PUSH	R15
 PUSH	R14
ifdef __REVAA
 LDX	R14,SPH
 LDX	R15,SPL
 LDX	R13,4047
 DI	
else
 LDWX	RR14,SP
 ATM
endif
 SUBX	SPL,R5
 SBCX	SPH,R4
ifdef __REVAA
 LDX	4047,R13
endif
 JP     @RR6



