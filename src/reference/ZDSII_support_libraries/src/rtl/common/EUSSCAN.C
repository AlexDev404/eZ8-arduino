/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                EUSSCAN.C  built from template file USSCAN.TPL
 *                          Do not edit directly
 ******************************************************************************/

#include <format.h>
#include <stddef.h>
#include <stdarg.h>

#include "scanf.h"

#define ACC -1
#define ERR -2


/*************************************************
*
* _u_sscan - scan a scanf format string
*
* Inputs:
*	fmt - pointer to format string
*	str - pointer to fmt_type structure
*	      where the results are put
*
* Returns:
*	new pointer to format string
*
*************************************************/
__CONST__ char pageE * _u_e_sscan (__CONST__ char pageE * fmt
   , struct fmt_type* print_fmt 
   , struct fmt_control_data * print_ctrl
   , struct pageE_set_type * setp)
{
  signed char pstate;
  signed char state = INIT;
  char ch;

  print_fmt->flags = 0;
  print_fmt->field_width = 0;
  print_fmt->precision = 0;
  print_fmt->size = 0;
  print_fmt->space = 0;
  print_fmt->type = '\0';

  for (;;) {
    ch = *(fmt++);
    pstate = state;
    state = _u_sscan_state(ch, state);

    switch (state) {
      case ACC:
		print_ctrl->status = FMT_OK;
		return(fmt-1);
      case ERR:
		print_ctrl->status = FMT_ERR;
		return(fmt-1);
      case PST:  // Pass through
		print_ctrl->status = FMT_PASS_THRU;
		print_ctrl->chr = ch;
		return(fmt);
      case IGN: // Ignore
		print_fmt->flags |= FMT_FLAG_IGNORE;
		break;
      case WDT: // Width character
		print_fmt->field_width = print_fmt->field_width * 10 + (ch - '0');
		break;
      case SIZ: // Size character, e.g. 'h' or 'l'
		print_fmt->size = ch;
		break;
      case SET: // Set, i.e. chars between '[' and ']'
		if (pstate != state) {
		  print_fmt->flags |= FMT_FLAG_SET;
		  setp->begin = fmt;
                  /* Check for sets that start with [] or [^] */
                  if (*fmt == '^')
                     fmt++;
                  if (*fmt == ']')
                     fmt++;
		}
		break;
      case EST: // End of set
		setp->end = fmt-1;
		break;
      case TYP: // Type character, e.g. d, x, i, s
		print_fmt->type = ch;
		break;
      case SPC: // Space character, F.N, or R
		print_fmt->space = ch;
		break;
    }
  }
}

