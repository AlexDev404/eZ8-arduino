
;*************************************************
;*  Copyright (C) 2006-2012 by Zilog, Inc.
;*  All Rights Reserved
;*************************************************

    xdef __VECTOR_040

    define __VECTORS_040, space=ROM, org=%40

    segment __VECTORS_040

__VECTOR_040:

     dw  %FFFF

