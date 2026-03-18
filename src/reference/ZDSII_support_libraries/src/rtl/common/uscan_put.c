/*   __uscan_put
 *   Save data read by uscan() to its destination
 *   
 *   call:  __uscan_put(size, data);
 *   size:  size of data to save (1,2, 3 for acclaim, or 4)
 */
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <stdarg.h>
#include <format.h>
#include <ZilogWarnings.h>

/* Suppress used before defined for np, fp, and p below */
#pragma warning disable USED_BEFORE_DEF

void __uscan_put(struct fmt_type* print_fmt, char size, unsigned long val)
{
   char space;
   if (!(print_fmt->flags & FMT_FLAG_IGNORE))
   {
      near char * np;
      far char * fp;
      char * p;

      switch(print_fmt->space)
      {
   #if __MODEL__
      case 'N':
         np = va_arg(_u_argp,near char *);
         space = 8;
         break;
   #else
      case 'F':
         fp = va_arg(_u_argp,far char *);
         space = 16;
         break;
   #endif
      default:
         p = va_arg(_u_argp,char *);
         space = 0;
         break;
      }
      switch(size + space)
      {
      case 1:
         *(char*)p = (char)val;
         break;
      case 2:
         *(short*)p = (short)val;
         break;
      case 4:
         *(long*)p = (long)val;
         break;
   #if __MODEL__
      case 8+1:
         *(near char*)np = (char)val;
         break;
      case 8+2:
         *(near short*)np = (short)val;
         break;
      case 8+4:
         *(near long*)np = (long)val;
         break;
   #else
      case 16+1:
         *(far char*)fp = (char)val;
         break;
      case 16+2:
         *(far short*)fp = (short)val;
         break;
      case 16+4:
         *(far long*)fp = (long)val;
         break;
   #endif
      }
      ++_u_fields;
   }
}
