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
;                       Large Model, Fast Calls
;
;
;  Prototype:        int longjmp(jmp_buf env,int val);
;
;                        Enter with jmp_buf in RR8, val in RR10
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
                ;   Since changing RP changes all regs, save RR8,RR10 on stack
                push    r11
                push    r10
                push    r9
                push    r8

                ldx     r4, 2(rr8)      ; Load Saved RP
                ldx     RP, r4          ;  and Restore

                ;  Reload jmpbuf, as change RP changes all regs
                pop     r8              ; RR2 -> jmpbuf
                pop     r9              ;
                pop     r0              ; RR0 = ret val
                pop     r1              ;

                ldx     r14,@rr8        ;Restore the frame pointer.
                ldx     r15,1(rr8)      ;
                ldx     r4,3(rr8)       ;  Restore SP
                ldx     r5,4(rr8)       ;
                ldx     SPH, r4
                ldx     SPL, r5
                ldx     r6,5(rr8)       ;  Restore RET ADDR on Stack
                ldx     r7,6(rr8)       ;
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
