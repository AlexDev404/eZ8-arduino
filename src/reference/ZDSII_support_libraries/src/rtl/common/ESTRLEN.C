/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                ESTRLEN.C  built from template file STRLEN.TPL
 *                          Do not edit directly
 ******************************************************************************/

#include <stddef.h>
#include <string.h>

#undef e_strlen
size_t e_strlen(__CONST__ char pageE * s)
{
  register __CONST__ char pageE * p = s;
  while (*p) ++p;
  return(p - s);
}

