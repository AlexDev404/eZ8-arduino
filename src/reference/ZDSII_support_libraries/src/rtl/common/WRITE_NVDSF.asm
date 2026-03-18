;
;   _WRITE_NVDS and _WRITE_NVDS_GET_STATUS for fast calls
;
;   WRITE_NVDS is hardwired into the chip, but requires parameters passed
;   on the stack.  This wrapper puts the registers on the stack.
        INCLUDE "ez8.inc"

        XREF WRITE_NVDS
        XDEF _WRITE_NVDS
        XDEF _WRITE_NVDS_GET_STATUS
_WRITE_NVDS:
        CLR     R1      ; Return 0 in low byte for int value
_WRITE_NVDS_GET_STATUS:
        PUSH    R9
        PUSH    R8
        CALL    WRITE_NVDS
        POP     R8
        POP     R9
        RET
        .FRAME _n_WRITE_NVDS,$_n_WRITE_NVDS,RDATA
        .FRAME _f_WRITE_NVDS,$_f_WRITE_NVDS,EDATA
        .FRAME _n_WRITE_NVDS_GET_STATUS,$_n_WRITE_NVDS_GET_STATUS,RDATA
        .FRAME _f_WRITE_NVDS_GET_STATUS,$_f_WRITE_NVDS_GET_STATUS,EDATA

