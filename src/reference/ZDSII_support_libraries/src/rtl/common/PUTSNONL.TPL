#include <stddef.h>
#include <stdio.h>
#include <errno.h>
#include <sio.h>

/*************************************************
*
* putsNOnl - put a string to stdout (without the trailing new line)
*
* Inputs:
*	string - address of string
*
* Returns:
*	Non-zero if an error occurs, else zero
*
*************************************************/
#undef PREFIX1##putsNOnl
int PREFIX1##putsNOnl(__CONST__ char SPACE1 * str)
{
  for(;*str;++str)
    putch(*str);
  return(0);
}

