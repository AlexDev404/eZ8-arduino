
;*************************************************
;*  Copyright (C) 2006-2008 by Zilog, Inc.
;*  All Rights Reserved
;*************************************************

    xdef __VECTOR_014

    define __VECTORS_014, space=ROM, org=%14

    segment __VECTORS_014

__VECTOR_014:

     dw  %FFFF
