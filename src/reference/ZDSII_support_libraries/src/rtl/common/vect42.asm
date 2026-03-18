
;*************************************************
;*  Copyright (C) 2006-2012 by Zilog, Inc.
;*  All Rights Reserved
;*************************************************

    xdef __VECTOR_042

    define __VECTORS_042, space=ROM, org=%42

    segment __VECTORS_042

__VECTOR_042:

     dw  %FFFF

