;--------------------------------------------------------------
; Code Generation Helper
; For the Opti-C Compiler
; 
; Copyright (C) 1999-2008 by Zilog, Inc.
; All Rights Reserved
;--------------------------------------------------------------

; far_sbrk - Large Model With Fast Calls
;
;  c prototype:  
;      void* _far_s_sbrk(size_t);


        SEGMENT FAR_DATA

        XREF    _far_heapbot

__far_heapbot:
        DW       _far_heapbot+1

;*************************************************
;
; $far__s_sbrk - get more memory from far heap space
;
; Inputs:
;    size - number of bytes to get in RR8
;
; Returns:
;    Address of memory, or -1 for none available
;        RR0
;
; Special Considerations:
;
;*************************************************
        SEGMENT CODE
        XDEF    _far_s_sbrk
     
_far_s_sbrk:

        PUSH    R15
        PUSH    R14
        LDX     R14,SPH
        LDX     R15,SPL
        
; add size to heap bottom
        LDX     R2,__far_heapbot
        LDX     R3,__far_heapbot+1
ifdef __REVAA
        LEA     RR0,0(RR2)
else
        LDWX    RR0, RR2
endif
        ADD     R3,R9
        ADC     R2,R8
        JR      C,OUT_OF_MEM  ;  Branch if overflowed
; Check for higher than far stack pointer (out of memory)
        CP      R14,#0          ; Near model?
        JR      EQ,OK           ; OK if so (or we're totally hosed)
        CP      R3,R15
        CPC     R2,R14
        JR      ULT,OK 

; Load out of memory value into return registers
OUT_OF_MEM:
        LD      R0,#255
        LD      R1,#255
        JR      SRET

OK:
        LDX     __far_heapbot,R2
        LDX     __far_heapbot+1,R3
SRET:
        POP     R14
        POP     R15
        RET
        .FRAME  _n_far_s_sbrk,$_n_far_s_sbrk,RDATA
        .FRAME  _f_far_s_sbrk,$_f_far_s_sbrk,EDATA

        END
