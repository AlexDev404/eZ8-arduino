
;*************************************************
;*  Copyright (C) 2006-2008 by Zilog, Inc.
;*  All Rights Reserved
;*************************************************

    xdef __VECTOR_02A

    define __VECTORS_02A, space=ROM, org=%2A

    segment __VECTORS_02A

__VECTOR_02A:

     dw  %FFFF
