/*************************************************
 *  Copyright (C) 1999-2008 by  Zilog, Inc.
 *  All Rights Reserved
 *************************************************/
#include <format.h>

/*  Global data used by the printf support functions.                       */
/*  This is only used of printfs are NOT generated in line
 *  (or of vsprintf/vprintf used).
 */
#ifndef __REENTRANT_PRINTFS__
far struct fmt_control_data __print_ctrl;

#endif

