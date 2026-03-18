/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                EQSORT.C  built from template file QSORT.TPL
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
static void e_swapmem(char pageE * a, char pageE * b, size_t size)
{
  register char t;
  register size_t i;

  for (i=0;i<size;++i,++b,++a) {
    t = *a;
    *a = *b;
    *b = t;
  }
}


struct e_stk {
  void pageE * l;
  void pageE * r;
};
static struct e_stk pageE e_stack[16];

#undef e_qsort
void e_qsort(char pageE * base,
		size_t nel,
		size_t size,
		reentrant int (*compar)(__CONST__ void pageE *,__CONST__ void pageE *))
{
  char pageE * i;
  char pageE * j;
  char pageE * x;
  char pageE * r;
  struct e_stk pageE *sp;

  sp = e_stack;
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
	  e_swapmem(i, j, size);
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

    if (sp <= e_stack)
      break;
    --sp;
    base = sp->l;
    r = sp->r;
  }
}

