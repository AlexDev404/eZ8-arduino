/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                NQSORT.C  built from template file QSORT.TPL
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
static void n_swapmem(char near * a, char near * b, size_t size)
{
  register char t;
  register size_t i;

  for (i=0;i<size;++i,++b,++a) {
    t = *a;
    *a = *b;
    *b = t;
  }
}


struct n_stk {
  void near * l;
  void near * r;
};
static struct n_stk near n_stack[16];

#undef n_qsort
void n_qsort(char near * base,
		size_t nel,
		size_t size,
		reentrant int (*compar)(__CONST__ void near *,__CONST__ void near *))
{
  char near * i;
  char near * j;
  char near * x;
  char near * r;
  struct n_stk near *sp;

  sp = n_stack;
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
	  n_swapmem(i, j, size);
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

    if (sp <= n_stack)
      break;
    --sp;
    base = sp->l;
    r = sp->r;
  }
}

