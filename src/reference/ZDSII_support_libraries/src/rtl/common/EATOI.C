/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                EATOI.C  built from template file ATOI.TPL
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
#undef e_atoi

int e_atoi(__CONST__ char pageE * cp)
{
  return e_strtol(cp,NULL,10);
}


