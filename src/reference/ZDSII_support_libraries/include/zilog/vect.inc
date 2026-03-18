;--------------------------------------------------------------
; 
; Copyright (C) 2006-2018 by Zilog, Inc.
; All Rights Reserved
;--------------------------------------------------------------

;
;   flash option bytes space allocation
;
 
	XREF    _flash_option1
	XREF    _flash_option2
 
_fbyte1  equ  _flash_option1
_fbyte2  equ  _flash_option2


;
;   vector table space allocation
;


	xref __VECTOR_004
	xref __VECTOR_006
	xref __VECTOR_008
	xref __VECTOR_00A
	xref __VECTOR_00C
	xref __VECTOR_00E
	xref __VECTOR_010
	xref __VECTOR_012
	xref __VECTOR_014
	xref __VECTOR_016
	xref __VECTOR_018
	xref __VECTOR_01A
	xref __VECTOR_01C
	xref __VECTOR_01E
	xref __VECTOR_020
	xref __VECTOR_022
	xref __VECTOR_024
	xref __VECTOR_026
	xref __VECTOR_028
	xref __VECTOR_02A
	xref __VECTOR_02C
	xref __VECTOR_02E
	xref __VECTOR_030
	xref __VECTOR_032
vect_00C equ __VECTOR_00C
	xref __VECTOR_034
	xref __VECTOR_036

vect_004 equ __VECTOR_004
vect_006 equ __VECTOR_006
vect_008 equ __VECTOR_008
vect_00A equ __VECTOR_00A
vect_00E equ __VECTOR_00E
vect_010 equ __VECTOR_010
vect_012 equ __VECTOR_012
vect_014 equ __VECTOR_014
vect_016 equ __VECTOR_016
vect_018 equ __VECTOR_018
vect_01A equ __VECTOR_01A
vect_01C equ __VECTOR_01C
vect_01E equ __VECTOR_01E
vect_020 equ __VECTOR_020
vect_022 equ __VECTOR_022
vect_024 equ __VECTOR_024
vect_026 equ __VECTOR_026
vect_028 equ __VECTOR_028
vect_02A equ __VECTOR_02A
vect_02C equ __VECTOR_02C
vect_02E equ __VECTOR_02E
vect_030 equ __VECTOR_030
vect_032 equ __VECTOR_032
vect_034 equ __VECTOR_034
vect_036 equ __VECTOR_036
 
IF (__Z8F04A=1) || (__Z8FMC16=1) || (__Z8F04=1) || (__Z8F1680=1)  \
                || (__Z8F648=1)  || (__Z8FXX24=1)
	xref __VECTOR_038
	xref __VECTOR_03A
	xref __VECTOR_03C
vect_038 equ __VECTOR_038
vect_03A equ __VECTOR_03A
vect_03C equ __VECTOR_03C
ENDIF 

IF (__Z8F648=1)   || (__Z8FXX24=1)
	xref __VECTOR_03E
	xref __VECTOR_040
	xref __VECTOR_042
	xref __VECTOR_044
	xref __VECTOR_046
	xref __VECTOR_048
vect_03E equ __VECTOR_03E
vect_040 equ __VECTOR_040
vect_042 equ __VECTOR_042
vect_044 equ __VECTOR_044
vect_046 equ __VECTOR_046
vect_048 equ __VECTOR_048
ENDIF

IF (__Z8F648=1)
	xref __VECTOR_04A
vect_04A equ __VECTOR_04A
ENDIF
