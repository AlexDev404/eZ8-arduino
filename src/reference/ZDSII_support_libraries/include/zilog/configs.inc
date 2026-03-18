;--------------------------------------------------------------
; Copyright (C) 1999-2006 by Zilog, Inc.
;--------------------------------------------------------------

	.include "ez8dev.inc"
;
; CPU equates
;
	Z8F64           EQU     0

;
;  TRUE/FALSE equates 
;
	TRUE	EQU	1
	FALSE	EQU	0

;	
;	Model equates
;
;	LS bit is 1 if stack is to be placed
;	in internal RAM.
;
	SMALL	EQU	1
	LARGE	EQU	0

;
;	Set memory model.
;
;<MODEL> I.E.
	MODEL   EQU     SMALL

;
;	Set to TRUE if the stack pointer is to be initialized
;
	INITSP	EQU	TRUE

;
;	Set to TRUE if register ram (nearbss) is to be initialized
;	to 0's.
;
        CLRRRAM SET     TRUE

;
;       Set to TRUE if extended ram (farbss) is to be initialized
;	to 0's.
;
IF  (__Z8F012A=0) && (__Z8F011A=0) && \
    (__Z8F0123XH=0) && (__Z8F0113XH=0) && \
    (__Z8F012AXB=0) && (__Z8F011AXB=0) && \
    (__Z8F0123=0) && (__Z8F0113=0) && \
    (__Z8F0123XB=0) && (__Z8F0113XB=0) && \
    (__Z8F083A=0) && (__Z8F043A=0)
        CLRERAM SET     TRUE
ELSE
        CLRERAM SET     FALSE
ENDIF

;
;       Set to TRUE if Page_E (memory above 0xE00) bss is to be initialized
;	to 0's.
;
IFDEF HavePageE
        CLRPAGEE SET    TRUE
ELSE
        CLRPAGEE SET    FALSE
ENDIF
;
;	Set to TRUE if (neardata) is to be copied from ROM
;
	COPYRRAM SET	TRUE 
;
;	Set to TRUE if (fardata) is to be copied from ROM
;
IF  (__Z8F012A=0) && (__Z8F011A=0) && \
    (__Z8F0123XH=0) && (__Z8F0113XH=0) && \
    (__Z8F012AXB=0) && (__Z8F011AXB=0) && \
    (__Z8F0123=0) && (__Z8F0113=0) && \
    (__Z8F0123XB=0) && (__Z8F0113XB=0) && \
    (__Z8F083A=0) && (__Z8F043A=0)
	COPYERAM SET    TRUE
ELSE
	COPYERAM SET    FALSE
ENDIF
;

;       Set to TRUE if Page_E (memory above 0xE00) data is to be copied from ROM
;
IFDEF HavePageE
        COPYPAGEE SET   TRUE
ELSE
        COPYPAGEE SET   FALSE
ENDIF

;
;	Set to TRUE if (pramseg) is to be copied from ROM
;
IF  (__Z8F1680=1)
	COPYPRAM SET TRUE
ELSE
	COPYPRAM SET FALSE
ENDIF

;
;	Heap used - Set to TRUE if the heap is used, otherwise
;	FALSE. If this value is set to FALSE then _malloc and _calloc
;	cannot be used.
;
	HEAP	EQU 	TRUE

