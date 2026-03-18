/*************************************************
 *  Copyright (C) 1999-2008 by  Zilog, Inc.
 *  All Rights Reserved
 *************************************************/

#include <stddef.h>
#include <format.h>

/*************************************************
*
* _u_ustoa - convert an unsigned short to a number of base rad
*
* Inputs:
*	int - int to be converted
*	str - target char array
*	rad - radix
*	fmt - format structure with conversion info
*
* Returns:
*	next address past the end of the string
*
*************************************************/
PF_REENTRANT void _u_ustoa(PRINT_FMT_ARG unsigned short n)
{
  _u_ultoa(PRNT_FMT_ARG (unsigned long)n);
}
