
;*************************************************
;*  Copyright (C) 2006-2008 by Zilog, Inc.
;*  All Rights Reserved
;*************************************************

    xdef __VECTOR_030

    define __VECTORS_030, space=ROM, org=%30

    segment __VECTORS_030

__VECTOR_030:

     dw  %FFFF
