
;*************************************************
;*  Copyright (C) 2006-2008 by Zilog, Inc.
;*  All Rights Reserved
;*************************************************

    xdef __VECTOR_020

    define __VECTORS_020, space=ROM, org=%20

    segment __VECTORS_020

__VECTOR_020:

     dw  %FFFF
