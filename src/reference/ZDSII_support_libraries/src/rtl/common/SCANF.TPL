#include <format.h>
#include <stdarg.h>
#include <stdio.h>

/*************************************************
*
* scanf - scan from stdin
*
* Inputs:
*	fmt - format string
*	args - argument list
*
* Returns:
*	Number of characters transmitted, or
*	-1 if an error occured.
*
*************************************************/
#undef PREFIX1##scanf
int PREFIX1##scanf(__CONST__ char SPACE1 * fmt,...)
{
  va_list ap;
  va_start(ap,fmt);
  /* The space associated with the first argument does not matter. */
  return(_u_n_##PREFIX1##scan(NULL,fmt,ap));
}

