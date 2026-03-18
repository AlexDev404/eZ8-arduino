/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                FQSORT.C  built from template file QSORT.TPL
 *                          Do not edit directly
 ******************************************************************************/

#include <stddef.h>
#include <stdlib.h>

/*************************************************
*
* qsort - Quick sort
*
* Inputs:
*	base	- base of array to be sorted
*	nel	- number of elements
*	size	- size of each element
*	compar	- pointer to function for comparison
*
* Returns:
*	nothing
*
*************************************************/
static void f_swapmem(char far * a, char far * b, size_t size)
{
  register char t;
  register size_t i;

  for (i=0;i<size;++i,++b,++a) {
    t = *a;
    *a = *b;
    *b = t;
  }
}


struct f_stk {
  void far * l;
  void far * r;
};
static struct f_stk far f_stack[16];

#undef f_qsort
void f_qsort(char far * base,
		size_t nel,
		size_t size,
		reentrant int (*compar)(__CONST__ void far *,__CONST__ void far *))
{
  char far * i;
  char far * j;
  char far * x;
  char far * r;
  struct f_stk far *sp;

  sp = f_stack;
  r = base + (size_t)((nel-1)*size);
  for (;;) {
    do {
      x = base + (size_t)((r-base)/size/2 * size);
      i = base;
      j = r;
      do {
	while ((*compar)(i,x) < 0)
	  i += size;
	while ((*compar)(x,j) < 0)
	  j -= size;
	if (i < j) {
	  f_swapmem(i, j, size);
	  if (i == x)
	    x = j;
	  else if (j == x)
	    x = i;
	}
	if (i <= j) {
	  i += size;
	  j -= size;
	}
      } while (i <= j);
      if (j-base < r-i) {
	if (i < r) {	/* stack request for right partition */
	  sp->l = i;
	  sp->r = r;
	  ++sp;
	}
	r = j;			/* continue sorting left partition */
      }
      else {
	if (base < j) { /* stack request for left partition */
	  sp->l = base;
	  sp->r = j;
	  ++sp;
	}
	base = i;		/* continue sorting right partition */
      }
    } while (base < r);

    if (sp <= f_stack)
      break;
    --sp;
    base = sp->l;
    r = sp->r;
  }
}

