/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                NITOD.C  built from template file ITOD.TPL
 *                          Do not edit directly
 ******************************************************************************/

#include <stdlib.h>

/*  Convert an integer to a decimal string and return a pointer to the string */

#if defined(__ZNEO__)
#  define BUFFSIZ 12   // sizeof(int) == 4
#elif defined(__EZ80__)
#  define BUFFSIZ 10    // sizeof(int) == 3
#elif defined(__EZ8__) || defined(__Z8__)
#  define BUFFSIZ 7    // sizeof(int) == 2
#endif

#undef n_itof
near char* n_itod(int i)
{

  static near char buff[BUFFSIZ];
  char s;
  near char*  pbuff = &buff[sizeof(buff)];

  *--pbuff = '\0';
  if (i == 0)
    *--pbuff = '0';
  else
  {
    if (i < 0)
    {
      s = 1;
      i = -i;
    }
    else
    {
      s = 0;
    }
    while(i)
    {
      *--pbuff = (i%10) + '0';
      i = i/10;
    }
    if (s)
      *--pbuff = '-';
  }
  return pbuff;
}
