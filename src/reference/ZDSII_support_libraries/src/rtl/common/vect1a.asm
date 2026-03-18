
;*************************************************
;*  Copyright (C) 2006-2008 by Zilog, Inc.
;*  All Rights Reserved
;*************************************************

    xdef __VECTOR_01A

    define __VECTORS_01A, space=ROM, org=%1A

    segment __VECTORS_01A

__VECTOR_01A:

     dw  %FFFF
