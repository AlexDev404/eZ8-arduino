
;*************************************************
;*  Copyright (C) 2006-2008 by Zilog, Inc.
;*  All Rights Reserved
;*************************************************

    xdef __VECTOR_00C

    define __VECTORS_00C, space=ROM, org=%C

    segment __VECTORS_00C

__VECTOR_00C:

     dw  %FFFF

