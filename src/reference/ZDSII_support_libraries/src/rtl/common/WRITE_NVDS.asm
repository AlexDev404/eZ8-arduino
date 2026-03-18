;
;   _WRITE_NVDS and _WRITE_NVDS_GET_STATUS for parameters passed on the stack
;
;   WRITE_NVDS is hardwired into the chip.  This wrapper just jumps to
;   the hardware address
        INCLUDE "ez8.inc"

        XREF WRITE_NVDS
        XDEF _WRITE_NVDS
        XDEF _WRITE_NVDS_GET_STATUS
_WRITE_NVDS:
        CLR     R1      ; Return 0 in low byte for int value
_WRITE_NVDS_GET_STATUS:
        JP      WRITE_NVDS
        .FRAME _n_WRITE_NVDS,$_n_WRITE_NVDS,RDATA
        .FRAME _f_WRITE_NVDS,$_f_WRITE_NVDS,EDATA
        .FRAME _n_WRITE_NVDS_GET_STATUS,$_n_WRITE_NVDS_GET_STATUS,RDATA
        .FRAME _f_WRITE_NVDS_GET_STATUS,$_f_WRITE_NVDS_GET_STATUS,EDATA
