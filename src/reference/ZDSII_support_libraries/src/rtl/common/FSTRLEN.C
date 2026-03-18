/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                FSTRLEN.C  built from template file STRLEN.TPL
 *                          Do not edit directly
 ******************************************************************************/

#include <stddef.h>
#include <string.h>

#undef f_strlen
size_t f_strlen(__CONST__ char far * s)
{
  register __CONST__ char far * p = s;
  while (*p) ++p;
  return(p - s);
}

