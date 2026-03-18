/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                NATOF.C  built from template file ATOF.TPL
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
#undef n_atof

double n_atof(__CONST__ char near * str)
{
  return n_strtod(str,NULL);
}

