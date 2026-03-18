/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                RSTRLEN.C  built from template file STRLEN.TPL
 *                          Do not edit directly
 ******************************************************************************/

#include <stddef.h>
#include <string.h>

#undef r_strlen
size_t r_strlen(__CONST__ char rom * s)
{
  register __CONST__ char rom * p = s;
  while (*p) ++p;
  return(p - s);
}

