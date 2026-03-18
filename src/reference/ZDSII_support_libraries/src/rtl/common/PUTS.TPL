#include <stddef.h>
#include <stdio.h>
#include <errno.h>
#include <sio.h>

/*************************************************
*
* puts - put a string to stdout
*
* Inputs:
*	string - address of string
*
* Returns:
*	Non-zero if an error occurs, else zero
*
*************************************************/
#undef PREFIX1##puts
int PREFIX1##puts(__CONST__ char SPACE1 * str)
{
  for(;*str;++str)
    putch(*str);
  putch('\n');
  putch('\r');
  return(0);
}

