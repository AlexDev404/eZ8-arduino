;--------------------------------------------------------------
; eZ8 Runtime Assembly Routine                    
; 
; Copyright (C) 1999-2008 by Zilog, Inc.
; All Rights Reserved
;--------------------------------------------------------------

                XDEF _0_longjmp, _1_longjmp, _longjmp


;--------------------------------------------------------------
;
;                          longjmp
;                       SMALL Model, Static Frames
;
;
;  Prototype:        int longjmp(jmp_buf env,int val);
;
;  Buffer Layout:        r14    ; ( r14 unused in small model)
;                        r15    ;frame pointer.
;                        rp     ;register pointer.
;                        spl    ;stack pointer low.
;                        sph    ;stack pointer high.
;                        retpcl ;return pc low.
;                        retpch ;return pc high.
;
;--------------------------------------------------------------

                SEGMENT CODE

_longjmp:
                ldx     r2, _0_longjmp  ; RR2 -> jmpbuf
                ldx     r3, _0_longjmp+1


                ldx     r4,2(rr2)      ; Load Saved RP
                ldx     RP,r4          ;  and Restore


                ;  Reload jmpbuf, as change RP changes all regs
                ldx     r2, _0_longjmp  ; R2 -> jmpbuf
                ldx     r3, _0_longjmp+1

                ldx     r15,1(rr2)      ; Restore the frame pointer.
                ldx     r4,3(rr2)       ;  Restore SP
                ldx     r5,4(rr2)       ;
                ldx     SPH, r4
                ldx     SPL, r5
                ldx     r6,5(rr2)       ;  Restore RET ADDR on Stack
                ldx     r7,6(rr2)       ;
                ldx     @rr4,r6
                ldx     1(rr4),r7

                ldx     r0, _1_longjmp  ;  Load return value
                ldx     r1, _1_longjmp+1

                ld      r2,r1           ; Map 0 to 1
                or      r2,r0
                jr      nz,LRET
                ld      r1,#1
LRET:
                ret

;**************************** _longjmp ***************************


.FRAME _longjump,_seg__longjump,RDATA
_0_longjmp:
        DS 2
_1_longjmp:
        DS 2
                end
