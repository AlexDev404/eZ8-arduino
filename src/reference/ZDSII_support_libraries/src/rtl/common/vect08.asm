
;*************************************************
;*  Copyright (C) 2006-2008 by Zilog, Inc.
;*  All Rights Reserved
;*************************************************
    xdef __VECTOR_008

    define __VECTORS_008, space=ROM, org=%8

    segment __VECTORS_008

__VECTOR_008:

     dw  %FFFF
