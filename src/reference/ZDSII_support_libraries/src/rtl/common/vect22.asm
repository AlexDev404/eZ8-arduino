
;*************************************************
;*  Copyright (C) 2006-2008 by Zilog, Inc.
;*  All Rights Reserved
;*************************************************

    xdef __VECTOR_022

    define __VECTORS_022, space=ROM, org=%22

    segment __VECTORS_022

__VECTOR_022:

     dw  %FFFF
