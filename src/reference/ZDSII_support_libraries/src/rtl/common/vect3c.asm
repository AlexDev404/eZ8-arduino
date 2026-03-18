
;*************************************************
;*  Copyright (C) 2006-2008 by Zilog, Inc.
;*  All Rights Reserved
;*************************************************

    xdef __VECTOR_03C

    define __VECTORS_03C, space=ROM, org=%3C

    segment __VECTORS_03C

__VECTOR_03C:

     dw  %FFFF

