
;*************************************************
;*  Copyright (C) 2006-2008 by Zilog, Inc.
;*  All Rights Reserved
;*************************************************

    xdef __VECTOR_010

    define __VECTORS_010, space=ROM, org=%10

    segment __VECTORS_010

__VECTOR_010:

     dw  %FFFF
