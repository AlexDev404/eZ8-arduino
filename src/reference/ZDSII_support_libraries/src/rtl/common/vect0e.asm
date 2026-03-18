
;*************************************************
;*  Copyright (C) 2006-2008 by Zilog, Inc.
;*  All Rights Reserved
;*************************************************

    xdef __VECTOR_00E

    define __VECTORS_00E, space=ROM, org=%E

    segment __VECTORS_00E

__VECTOR_00E:

     dw  %FFFF
