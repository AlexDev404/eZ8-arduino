/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                NFREXP.C  built from template file FREXP.TPL
 *                          Do not edit directly
 ******************************************************************************/

#include <math.h>
#include <stddef.h>

#undef n_frexp
double n_frexp(double x,int near * i)
{
  int neg;
  int j;

  if(x==0.0){
    *i=0;
    return(0.0);
  }

  j = 0;
  neg = 0;
  if(x<0){
    x = -x;
    neg = 1;
  }
  if(x>=1.0)
    while(x>=1.0){
      j = j+1;
      x = x/2;
    }
  else if(x<0.5)
    while(x<0.5){
      j = j-1;
      x = 2*x;
    }
  *i = j;
  if(neg) x = -x;
  return(x);
}


