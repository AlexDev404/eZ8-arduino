/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                EATOL.C  built from template file ATOL.TPL
 *                          Do not edit directly
 ******************************************************************************/

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
#undef e_atol

long e_atol(__CONST__ char pageE * cp)
{
  return e_strtol(cp, NULL, 10);
}

