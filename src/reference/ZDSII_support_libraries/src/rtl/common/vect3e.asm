
;*************************************************
;*  Copyright (C) 2006-2012 by Zilog, Inc.
;*  All Rights Reserved
;*************************************************

    xdef __VECTOR_03E

    define __VECTORS_03E, space=ROM, org=%3E

    segment __VECTORS_03E

__VECTOR_03E:

     dw  %FFFF

