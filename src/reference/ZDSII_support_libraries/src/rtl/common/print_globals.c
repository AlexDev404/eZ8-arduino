/*************************************************
 *  Copyright (C) 1999-2008 by  Zilog, Inc.
 *  All Rights Reserved
 *************************************************/
#include <format.h>

/*  Global data used by the printf support functions.                       */
/*  The compiler may manipulate this data directly to bypass the runtime    */
/*  parsing of (s)printf formats.                                           */
#ifndef __REENTRANT_PRINTFS__
far struct fmt_type __print_fmt;
#endif

