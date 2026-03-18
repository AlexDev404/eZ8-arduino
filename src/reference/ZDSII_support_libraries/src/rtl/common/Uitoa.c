/*************************************************
 *  Copyright (C) 1999-2008 by  Zilog, Inc.
 *  All Rights Reserved
 *************************************************/

#include <stddef.h>
#include <format.h>

/*************************************************
*
* _u_itoa - convert an integer to a number of base rad
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
PF_REENTRANT void _u_itoa(struct fmt_type* print_fmt, int n)
{
  _u_ltoa(printf_fmt, (long)n);
}
