
;*************************************************
;*  Copyright (C) 2006-2008 by Zilog, Inc.
;*  All Rights Reserved
;*************************************************

    xdef __VECTOR_016

    define __VECTORS_016, space=ROM, org=%16

    segment __VECTORS_016

__VECTOR_016:

     dw  %FFFF
