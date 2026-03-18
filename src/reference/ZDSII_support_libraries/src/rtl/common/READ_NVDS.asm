;
;   _READ_NVDS and _READ_NVDS_GET_STATUS for parameters passed on the stack
;
;   READ_NVDS is hardwired into the chip.  This wrapper just jumps to
;   the hardware address
        INCLUDE "ez8.inc"

        XREF READ_NVDS
        XDEF _READ_NVDS
        XDEF _READ_NVDS_GET_STATUS
_READ_NVDS_GET_STATUS:
_READ_NVDS:
        JP   _READ_NVDS
        .FRAME _n_READ_NVDS,$_n_READ_NVDS,RDATA
        .FRAME _f_READ_NVDS,$_f_READ_NVDS,EDATA
        .FRAME _n_READ_NVDS_GET_STATUS,$_n_READ_NVDS_GET_STATUS,RDATA
        .FRAME _f_READ_NVDS_GET_STATUS,$_f_READ_NVDS_GET_STATUS,EDATA
