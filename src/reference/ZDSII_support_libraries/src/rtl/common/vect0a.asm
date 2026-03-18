
;*************************************************
;*  Copyright (C) 2006-2008 by Zilog, Inc.
;*  All Rights Reserved
;*************************************************

    xdef __VECTOR_00A

    define __VECTORS_00A, space=ROM, org=%A

    segment __VECTORS_00A

__VECTOR_00A:

     dw  %FFFF
