
;*************************************************
;*  Copyright (C) 2006-2008 by Zilog, Inc.
;*  All Rights Reserved
;*************************************************

    xdef __VECTOR_02E

    define __VECTORS_02E, space=ROM, org=%2E

    segment __VECTORS_02E

__VECTOR_02E:

     dw  %FFFF
