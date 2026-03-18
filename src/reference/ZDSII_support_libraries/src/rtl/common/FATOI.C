/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                FATOI.C  built from template file ATOI.TPL
 *                          Do not edit directly
 ******************************************************************************/

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
#undef f_atoi

int f_atoi(__CONST__ char far * cp)
{
  return f_strtol(cp,NULL,10);
}


