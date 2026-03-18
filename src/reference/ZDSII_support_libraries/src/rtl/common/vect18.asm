
;*************************************************
;*  Copyright (C) 2006-2008 by Zilog, Inc.
;*  All Rights Reserved
;*************************************************

    xdef __VECTOR_018

    define __VECTORS_018, space=ROM, org=%18

    segment __VECTORS_018

__VECTOR_018:

     dw  %FFFF
