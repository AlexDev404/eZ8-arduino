#include <stddef.h>
#include <math.h>
#include <stdlib.h>

/*************************************************
*
* atof - ASCII to float conversion
*
* Inputs:
*	str - pointer to the character string
*
* Returns:
*	the value of the number
*
*************************************************/
#undef PREFIX1##atof

double PREFIX1##atof(__CONST__ char SPACE1 * str)
{
  return PREFIX1##strtod(str,NULL);
}

