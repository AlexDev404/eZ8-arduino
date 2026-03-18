/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                STRLEN.C  built from template file STRLEN.TPL
 *                          Do not edit directly
 ******************************************************************************/

#include <stddef.h>
#include <string.h>

#undef strlen
size_t strlen(__CONST__ char  * s)
{
  register __CONST__ char  * p = s;
  while (*p) ++p;
  return(p - s);
}

