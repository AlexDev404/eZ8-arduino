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
	MODEL   EQU     LARGE

;
;	Set to TRUE if the stack pointer is to be initialized
;
	INITSP	EQU	TRUE

;
;	Set to TRUE if register ram (c_nearbss) is to be initialized
;	to 0's.
;
        CLRRRAM SET     TRUE

;
;       Set to TRUE if extended ram (c_farbss) is to be initialized
;	to 0's.
;
        CLRERAM SET     TRUE

;
;       Set to TRUE if PAGE_E ram (PAGE_E_BSS) is to be initialized
;	to 0's.
;
IFDEF HavePageE
        CLRPAGEE SET    TRUE
ELSE
        CLRPAGEE SET    FALSE
ENDIF

;
;	Set to TRUE if (c_neardata) is to be copied from ROM
;
	COPYRRAM SET	TRUE 
;
;	Set to TRUE if (c_fardata) is to be copied from ROM
;
        COPYERAM SET    TRUE

;
;	Set to TRUE if PAGE_E_DATA is to be copied from ROM
;
IFDEF HavePageE
        COPYPAGEE SET   TRUE
ELSE
        COPYPAGEE SET   FALSE
ENDIF

;
;	Set to TRUE if (pramseg) is to be copied from ROM
;
IF (__Z8F1680=1)
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

