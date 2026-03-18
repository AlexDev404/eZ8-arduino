
;*************************************************
;*  Copyright (C) 2006-2008 by Zilog, Inc.
;*  All Rights Reserved
;*************************************************

    xdef __VECTOR_03A

    define __VECTORS_03A, space=ROM, org=%3A

    segment __VECTORS_03A

__VECTOR_03A:

     dw  %FFFF
