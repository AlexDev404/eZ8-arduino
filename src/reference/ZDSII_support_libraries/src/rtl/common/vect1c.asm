
;*************************************************
;*  Copyright (C) 2006-2008 by Zilog, Inc.
;*  All Rights Reserved
;*************************************************

    xdef __VECTOR_01C

    define __VECTORS_01C, space=ROM, org=%1C

    segment __VECTORS_01C

__VECTOR_01C:

     dw  %FFFF
