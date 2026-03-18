;--------------------------------------------------------------
; Z8 Runtime Assembly Routine                                
; 
; Copyright (C) 1999-2008 by Zilog, Inc.
; All Rights Reserved
;--------------------------------------------------------------

                XDEF _setjmp

;--------------------------------------------------------------
;
;                          setjmp
;                       Small Model, DYNAMIC Frames
;
;
;  Prototype:        int setjmp(jmp_buf env);
;
;  Buffer Layout:        r14       ;   Not used in small model
;                        r15       ;frame pointer.
;                        rp        ;register pointer.
;                        spl       ;stack pointer low.
;                        sph       ;stack pointer high.
;                        retpch    ;return pc low.
;                        retpcl    ;return pc high.
;
;--------------------------------------------------------------

                SEGMENT CODE

_setjmp:
                ldx    r0,SPL
                ld     r2, 2(r0)      ; RR2 -> jmpbuf
                ld     r3, 3(r0)

                ldx    1(rr2), r15     ; Save the frame pointer.

                ldx    r4, RP          ; Save register pointer
                ldx    2(rr2), r4 
                
                ldx    r4, SPH         ; Save the stack pointer.
                ldx    r5, SPL
                ldx    3(rr2), r4 
                ldx    4(rr2), r5 

                ldx    r0,@rr4         ; Save Ret addr
                ldx    r1,1(rr4)       
                ldx    5(rr2), r0 
                ldx    6(rr2), r1 

                clr    r0              ; Always return 0
                clr    r1

                RET        

;**************************** _setjmp ***************************

                end

