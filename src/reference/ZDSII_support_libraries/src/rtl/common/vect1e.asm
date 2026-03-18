
;*************************************************
;*  Copyright (C) 2006-2008 by Zilog, Inc.
;*  All Rights Reserved
;*************************************************

    xdef __VECTOR_01E

    define __VECTORS_01E, space=ROM, org=%1E

    segment __VECTORS_01E

__VECTOR_01E:

     dw  %FFFF

