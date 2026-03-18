;--------------------------------------------------------------
; Code Generation Helper
; For the Opti-C Compiler
; 
; Copyright (C) 1999-2008 by Zilog, Inc.
; All Rights Reserved
;--------------------------------------------------------------
; sbrk - Small Dynamic Model


;      void* near_s_sbrk(size_t);


        SEGMENT NEAR_DATA        

        XREF    _near_heapbot

__near_heapbot:
        DB       _near_heapbot+1


;*************************************************
;
; $_s_sbrk - get more memory from far heap space
;
; Inputs:
;    size - number of bytes to get 
;
; Returns:
;    Address of memory, or -1 for none available
;        R0
;
; Special Considerations:
;
;*************************************************
        SEGMENT CODE
        XDEF    _near_s_sbrk
     
_near_s_sbrk:

        PUSH    R15
        PUSH    R14
        LDX     R15,SPL        
        LDX     R14,SPH        
; get size
        LDX     R4,4(RR14)
        CP      R4,#0
        JP      NE, OUT_OF_MEM

        LDX     R4,5(RR14)

; add size to heap bottom
        LD      R2,__near_heapbot
        LD      R0,R2

        ADD     R2,R4
        JR      C,OUT_OF_MEM  ;  Branch if overflowed

; Check for higher than near stack pointer (out of memory)
        CP      R15,R2
        CPC     R14,#0
        JR        UGT,OK

OUT_OF_MEM:
        LD      R0,#255
        JR      SRET
OK:
        LD      __near_heapbot,R2
SRET:
        POP     R14        
        POP     R15        
        RET

        .FRAME  _n_near_s_sbrk,$_n_near_s_sbrk,RDATA
        .FRAME  _f_near_s_sbrk,$_f_near_s_sbrk,EDATA

        END
