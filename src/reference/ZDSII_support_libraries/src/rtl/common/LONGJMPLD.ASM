;--------------------------------------------------------------
; eZ8 Runtime Assembly Routine                    
; 
; Copyright (C) 1999-2008 by Zilog, Inc.
; All Rights Reserved
;--------------------------------------------------------------

                XDEF _longjmp


;--------------------------------------------------------------
;
;                          longjmp
;                       Large Model, Dynamic Frames
;
;
;  Prototype:        int longjmp(jmp_buf env,int val);
;
;  Buffer Layout:        r14
;                        r15        ;frame pointer.
;                        rp        ;register pointer.
;                        spl        ;stack pointer low.
;                        sph        ;stack pointer high.
;                        retpcl        ;return pc low.
;                        retpch        ;return pc high.
;
;--------------------------------------------------------------

                SEGMENT CODE

_longjmp:
                ldx     r6,SPH
                ldx     r7,SPL
                ldx     r2, 2(rr6)      ; RR2 -> jmpbuf
                ldx     r3, 3(rr6)

                ldx     r4, 2(rr2)      ; Load Saved RP
                ldx     RP, r4          ;  and Restore

                ;  Reload jmpbuf, as change RP changes all regs
                ldx     r6,SPH
                ldx     r7,SPL
                ldx     r2, 2(rr6)      ; RR2 -> jmpbuf
                ldx     r3, 3(rr6)
                ldx     r0, 4(rr6)      ; RR0 = ret val
                ldx     r1, 5(rr6)

                ldx     r14,@rr2        ;Restore the frame pointer.
                ldx     r15,1(rr2)      ;
                ldx     r4,3(rr2)       ;  Restore SP
                ldx     r5,4(rr2)       ;
                ldx     SPH, r4
                ldx     SPL, r5
                ldx     r6,5(rr2)       ;  Restore RET ADDR on Stack
                ldx     r7,6(rr2)       ;
                ldx     @rr4,r6
                ldx     1(rr4),r7

                ld      r2,r0           ; Map 0 to 1
                or      r2,r1
                jr      nz,LRET
                ld      r1,#1
LRET:
                ret

;**************************** _longjmp ***************************

                end
