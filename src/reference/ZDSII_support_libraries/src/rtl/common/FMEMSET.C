/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                FMEMSET.C  built from template file MEMSET.TPL
 *                          Do not edit directly
 ******************************************************************************/

#include <stddef.h>
#include <string.h>
#undef f_memset

PF_REENTRANT void far * f_memset(void far * s, int c, size_t n)
{
  unsigned char far * p = s;

  for (;n;--n)
    *p++ = c;
  return(s);
}

