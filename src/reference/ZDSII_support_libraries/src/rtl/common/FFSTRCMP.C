/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                FFSTRCMP.C  built from template file STRCMP.TPL
 *                          Do not edit directly
 ******************************************************************************/

#include <stddef.h>
#include <string.h>

#undef f_f_strcmp
int f_f_strcmp(register __CONST__ char far * s1, register __CONST__ char far * s2)
{
  while (*s1 && *s1 == *s2)
    s1++, s2++;
  return(*s1 - *s2);
}

