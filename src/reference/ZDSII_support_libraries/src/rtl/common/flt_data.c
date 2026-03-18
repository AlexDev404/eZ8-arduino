/*************************************************
 *  Copyright (C) 1999-2008 by  Zilog, Inc.
 *  All Rights Reserved
 *************************************************/
#include <format.h>

/*  Global data used by the printf support functions.                       */
/* This in only used in the formating of floats */
#ifndef __REENTRANT_PRINTFS__
far struct flt_fmt_data __flt_data;
#endif

