/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                NSTRLEN.C  built from template file STRLEN.TPL
 *                          Do not edit directly
 ******************************************************************************/

#include <stddef.h>
#include <string.h>

#undef n_strlen
size_t n_strlen(__CONST__ char near * s)
{
  register __CONST__ char near * p = s;
  while (*p) ++p;
  return(p - s);
}

