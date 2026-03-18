;--------------------------------------------------------------
; Code Generation Helper
; For the Z8 Encore! Compiler
; 
; Copyright 2004-2008 by Zilog, Inc.
; All Rights Reserved
;--------------------------------------------------------------


   XDEF __a_framereset
   XDEF __b_framereset
   XDEF __framereset
   XREF __intrp
   .include "ez8.inc"


  SEGMENT PRAMSEG

 
__a_framereset:
__b_framereset:
__framereset:
 POP	R6
 POP    R7
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
 JP     @RR6


