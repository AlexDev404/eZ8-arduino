#include <stddef.h>
#include <stdlib.h>

/*************************************************
*
* bsearch - binary search
*
* Inputs:
*	key	- key to search for
*	base	- base of array to be sorted
*	num	- number of elements
*	width	- size of each element
*	comp	- pointer to function for comparison
*
* Returns:
*	nothing
*
*************************************************/
#undef PREFIX1##bsearch
void SPACE2 * PREFIX1##PREFIX2##bsearch(__CONST__ void SPACE1 * key,
			      __CONST__ void SPACE2 * base,
			      size_t num,
			      size_t span,
			      reentrant int (*comp)(__CONST__ void SPACE1 *, __CONST__ void SPACE2 *))
{
  unsigned int mid;
  unsigned int low;
  unsigned int high;
  int d;
  unsigned int pmid;
  char SPACE2 * addr;

	/* make high the nearest power of two for */
	/* efficiency and to ensure we always	  */
	/* terminate properly.			  */
	/* Note that high is always higher	  */
	/* than it should be so that we will	  */
	/* not fail to find the last entry in the */
	/* table.				  */

  high = 0x0001;
  while (high <= num)
    high <<= 1;
  low = 0;
  mid = 0;

	/* begin the search */

  for(;;) {
    pmid = mid;
    mid = ((high - low) >> 1) + low;

    if (pmid == mid)		/* terminate because we're  */
      return(NULL);		/* oscilating.		    */

    if (mid >= num) {		/* we're above the array.   */
      high = mid;		/* pretend element is larger*/
      continue; 		/* than the key.	    */
    }

    d = (*comp)(key,addr = (char SPACE2 *)base + (size_t)(mid * span));

    if (d == 0) 		/* we found it		    */
      return(addr);
    if (d < 0)			/* key is less than mid,    */
      high = mid;		/* set high to mid.	    */
    else			/* key is greater than mid, */
      low = mid;		/* set low to mid.	    */
  }
}


