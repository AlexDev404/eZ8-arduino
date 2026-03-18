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
static void PREFIX1##swapmem(char SPACE1 * a, char SPACE1 * b, size_t size)
{
  register char t;
  register size_t i;

  for (i=0;i<size;++i,++b,++a) {
    t = *a;
    *a = *b;
    *b = t;
  }
}


struct PREFIX1##stk {
  void SPACE1 * l;
  void SPACE1 * r;
};
static struct PREFIX1##stk SPACE1 PREFIX1##stack[16];

#undef PREFIX1##qsort
void PREFIX1##qsort(char SPACE1 * base,
		size_t nel,
		size_t size,
		reentrant int (*compar)(__CONST__ void SPACE1 *,__CONST__ void SPACE1 *))
{
  char SPACE1 * i;
  char SPACE1 * j;
  char SPACE1 * x;
  char SPACE1 * r;
  struct PREFIX1##stk SPACE1 *sp;

  sp = PREFIX1##stack;
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
	  PREFIX1##swapmem(i, j, size);
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

    if (sp <= PREFIX1##stack)
      break;
    --sp;
    base = sp->l;
    r = sp->r;
  }
}

