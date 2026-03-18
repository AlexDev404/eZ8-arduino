/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                FATOF.C  built from template file ATOF.TPL
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
#undef f_atof

double f_atof(__CONST__ char far * str)
{
  return f_strtod(str,NULL);
}

