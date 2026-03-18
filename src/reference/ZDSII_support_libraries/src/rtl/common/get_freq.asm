;--------------------------------------------------------------
; 
; Copyright (C) 2003-2008 by Zilog, Inc.
; All Rights Reserved
;--------------------------------------------------------------
;
 
	SEGMENT code
	xref __user_frequency
 
_get_freq:
	LD	R0,#high(high16(__user_frequency))
	LD	R1,#low(high16(__user_frequency))
	LD	R2,#high(low16(__user_frequency))
	LD	R3,#low(low16(__user_frequency))
	RET	


	.FRAME _n_get_freq,?_n_get_freq,RDATA

	XDEF _get_freq
	END
