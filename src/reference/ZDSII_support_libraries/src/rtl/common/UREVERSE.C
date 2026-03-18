/*************************************************
 *  Copyright (C) 1999-2008 by  Zilog, Inc.
 *  All Rights Reserved
 *************************************************/

#include <string.h>
#include <format.h>

#ifdef NEAR_FMT_BUFFERS
#define STRLEN strlen
#else
#define STRLEN f_strlen
#endif

/*************************************************
*
* _u_reverse - reverse a string leaving the end
*	       of string indicator at the end
*	       of the string
*
* Inputs:
*	str - string to be reversed
*
* Returns:
*	str - string reversed
*
*************************************************/
PF_REENTRANT void _u_reverse(char * s)
{
  register char * ss = s;
  register size_t len = STRLEN(s);
  register char * pp = s + len - 1;
  register char c;

  while (len > 1) {
    c = *pp;
    *pp-- = *ss;
    *ss++ = c;
    len -= 2;
  }
}
