
;*************************************************
;*  Copyright (C) 2006-2008 by Zilog, Inc.
;*  All Rights Reserved
;*************************************************

    xdef __VECTOR_006

    define __VECTORS_006, space=ROM, org=%6

    segment __VECTORS_006

__VECTOR_006:

     dw  %FFFF
