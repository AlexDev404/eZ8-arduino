
;*************************************************
;*  Copyright (C) 200-2008  by Zilog, Inc.
;*  All Rights Reserved
;*************************************************

    xdef __VECTOR_012

    define __VECTORS_012, space=ROM, org=%12

    segment __VECTORS_012

__VECTOR_012:

     dw  %FFFF
