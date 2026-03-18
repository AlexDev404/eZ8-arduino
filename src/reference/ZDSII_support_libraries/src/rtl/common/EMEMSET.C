/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                EMEMSET.C  built from template file MEMSET.TPL
 *                          Do not edit directly
 ******************************************************************************/

#include <stddef.h>
#include <string.h>
#undef e_memset

PF_REENTRANT void pageE * e_memset(void pageE * s, int c, size_t n)
{
  unsigned char pageE * p = s;

  for (;n;--n)
    *p++ = c;
  return(s);
}

