/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                ATOI.C  built from template file ATOI.TPL
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
#undef atoi

int atoi(__CONST__ char  * cp)
{
  return strtol(cp,NULL,10);
}


