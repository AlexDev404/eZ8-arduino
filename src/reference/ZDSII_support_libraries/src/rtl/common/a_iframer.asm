;--------------------------------------------------------------
; Code Generation Helper
; For the Z8 Encore! Compiler
; 
; Copyright 2004-2008 by Zilog, Inc.
; All Rights Reserved
;--------------------------------------------------------------

 
   XDEF __a_iframereset
   XDEF __b_iframereset
   XDEF __iframereset 
   XREF __intrp
   .include "ez8.inc"


  SEGMENT PRAMSEG 

__a_iframereset:
__b_iframereset:
__iframereset:
 POP	R4
 POP    R5
ifdef __REVAA
 LDX	R13,4047
 DI	
 LDX	SPL,R15
 LDX	SPH,R14
 LDX	4047,R13
else
 LDWX   SP,RR14
 ATM    ; Fix CR 13589
endif
 POP	R14
 POP	R15
 POP    R6
 PUSH   R5
 PUSH   R4
 PUSH   R6
 SUBX   __intrp,#16
 POPX	RP
 RET
