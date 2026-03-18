/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                NATOI.C  built from template file ATOI.TPL
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
#undef n_atoi

int n_atoi(__CONST__ char near * cp)
{
  return n_strtol(cp,NULL,10);
}


