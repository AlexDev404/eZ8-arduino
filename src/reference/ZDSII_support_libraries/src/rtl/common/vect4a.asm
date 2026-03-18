
;*************************************************
;*  Copyright (C) 2006-2012 by Zilog, Inc.
;*  All Rights Reserved
;*************************************************

    xdef __VECTOR_04A

    define __VECTORS_04A, space=ROM, org=%4A

    segment __VECTORS_04A

__VECTOR_04A:

     dw  %FFFF

