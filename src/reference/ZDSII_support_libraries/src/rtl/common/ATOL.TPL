#include <stddef.h>
#include <stdlib.h>

/*************************************************
*
* atol - ASCII to long conversion
*
* Inputs:
*	str - pointer to the character string
*
* Returns:
*	the value of the number
*
*************************************************/
#undef PREFIX1##atol

long PREFIX1##atol(__CONST__ char SPACE1 * cp)
{
  return PREFIX1##strtol(cp, NULL, 10);
}

