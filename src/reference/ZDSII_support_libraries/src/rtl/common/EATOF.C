/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                EATOF.C  built from template file ATOF.TPL
 *                          Do not edit directly
 ******************************************************************************/

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
#undef e_atof

double e_atof(__CONST__ char pageE * str)
{
  return e_strtod(str,NULL);
}

