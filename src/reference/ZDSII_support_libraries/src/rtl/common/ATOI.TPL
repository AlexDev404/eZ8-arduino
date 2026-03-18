#include <stdlib.h>
#include <stddef.h>

/*************************************************
*
* atoi - ASCII to integer conversion
*
* Inputs:
*	str - pointer to the character string
*
* Returns:
*	the value of the number
*
*************************************************/
#undef PREFIX1##atoi

int PREFIX1##atoi(__CONST__ char SPACE1 * cp)
{
  return PREFIX1##strtol(cp,NULL,10);
}


