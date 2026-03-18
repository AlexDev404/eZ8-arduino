#include <format.h>
#include <stdio.h>
#include <stdarg.h>

/*************************************************
*
* vsprintf - print to a string (variable args)
*
* Inputs:
*	string - pointer to string to write to
*	fmt - format string
*	args - argument list
*
* Returns:
*	Number of characters transmitted, or
*	-1 if an error occured.
*
*************************************************/
#undef PREFIX1##PREFIX2##vsprintf
PF_REENTRANT int PREFIX1##PREFIX2##vsprintf(char SPACE1 * string,__CONST__ char SPACE2 * fmt,va_list args)
{
#ifdef __REENTRANT_PRINTFS__
  struct fmt_type print_fmt;
#undef __print_fmt
#define __print_fmt print_fmt
#undef PRNT_FMT_ARG0
#define PRNT_FMT_ARG0 &print_fmt
#undef PRNT_FMT_ARG
#define PRNT_FMT_ARG &print_fmt,
#endif

  int retVal;

  __clr_print_fmt(PRNT_FMT_ARG0);
  __print_fmt.print_len = 0;
  __print_fmt.dest = (far char*)string;
  _u_##PREFIX2##print(PRNT_FMT_ARG fmt, args);
  return __print_fmt.print_len; 
}
