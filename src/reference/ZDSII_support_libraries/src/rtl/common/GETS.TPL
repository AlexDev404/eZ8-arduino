#include <stddef.h>
#include <stdio.h>
#include <errno.h>
#include <sio.h>

#define LF 10

/*************************************************
*
* gets - get a string from the uart
*	Dangerous! Buffer overrun is possible.
*
* Inputs:
*	string - address of string
*
* Returns:
*	pointer to string or NULL
*
*************************************************/
#undef PREFIX1##gets
char SPACE1 * PREFIX1##gets(__CONST__ char SPACE1 * string)
{
  char SPACE1 * sptr = string;
  char chr;

  while ((chr = getchar()) != EOF) {
    if (chr == LF) {
      *sptr = '\0';
      return (string);
    } /* Remove LF */
    *(sptr++) = chr;
  }
  /* EOF encountered */
  if (sptr == string)
    return NULL;
  *sptr = '\0';
  return string;
}


