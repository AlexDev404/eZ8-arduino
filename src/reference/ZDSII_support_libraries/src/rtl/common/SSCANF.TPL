#include <format.h>
#include <stdarg.h>
#include <stddef.h>

/*************************************************
*
* sscanf - scan from a string
*
* Inputs:
*	string - string to print to
*	fmt - format string
*	args - argument list
*
* Returns:
*	Number of characters transmitted, or
*	-1 if an error occured.
*
*************************************************/
#undef PREFIX1##PREFIX2##sscanf
int PREFIX1##PREFIX2##sscanf(__CONST__ char SPACE1 * string,__CONST__ char SPACE2 * fmt,...)
{
  va_list ap;
  va_start(ap,fmt);
  return(_u_##PREFIX1##PREFIX2##scan(string,fmt,ap));
}

