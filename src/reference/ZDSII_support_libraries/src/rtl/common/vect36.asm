
;*************************************************
;*  Copyright (C) 2006-2008 by Zilog, Inc.
;*  All Rights Reserved
;*************************************************

    xdef __VECTOR_036

    define __VECTORS_036, space=ROM, org=%36

    segment __VECTORS_036

__VECTOR_036:

     dw  %FFFF
