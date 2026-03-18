
;*************************************************
;*  Copyright (C) 2006-2008 by Zilog, Inc.
;*  All Rights Reserved
;*************************************************

    xdef __VECTOR_026

    define __VECTORS_026, space=ROM, org=%26

    segment __VECTORS_026

__VECTOR_026:

     dw  %FFFF
