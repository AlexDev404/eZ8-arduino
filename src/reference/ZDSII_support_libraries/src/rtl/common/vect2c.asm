
;*************************************************
;*  Copyright (C) 2006-2008 by Zilog, Inc.
;*  All Rights Reserved
;*************************************************

    xdef __VECTOR_02C

    define __VECTORS_02C, space=ROM, org=%2C

    segment __VECTORS_02C

__VECTOR_02C:

     dw  %FFFF

