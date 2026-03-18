;
;   _READ_NVDS and _READ_NVDS_GET_STATUS for fast calls
;
;   READ_NVDS is hardwired into the chip, but requires parameters passed
;   on the stack.  This wrapper puts the registers on the stack.
        INCLUDE "ez8.inc"

        XREF READ_NVDS
        XDEF _READ_NVDS
        XDEF _READ_NVDS_GET_STATUS
_READ_NVDS_GET_STATUS:
_READ_NVDS:
        PUSH    R8
        CALL    _READ_NVDS
        POP     R8
        RET
        .FRAME _n_READ_NVDS,$_n_READ_NVDS,RDATA
        .FRAME _f_READ_NVDS,$_f_READ_NVDS,EDATA
        .FRAME _n_READ_NVDS_GET_STATUS,$_n_READ_NVDS_GET_STATUS,RDATA
        .FRAME _f_READ_NVDS_GET_STATUS,$_f_READ_NVDS_GET_STATUS,EDATA

