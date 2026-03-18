/*******************************************************************************
 *                Copyright (C) 1999-2012 by  ZiLOG, Inc.
 *                         All Rights Reserved
 ******************************************************************************/

/*******************************************************************************
 *                FUPSCAN.C  built from template file UPSCAN.TPL
 *                          Do not edit directly
 ******************************************************************************/

#include <stdarg.h>
#include <format.h>
#include <ctype.h>
#include <string.h>

/* classes */

#define SFLAGS 0
#define DIGIT 1
#define SIZE 2
#define DOT 3
#define TYPES 4
#define PERCENT 5
#define AST 6
#define SPACE 7
#define OTHER 8
#define NCLASSES 9

/* actions */

#define ACC -1 // Accept
#define ERR -2 // Error
#define INIT 0 // Initial state
#define PCT 1  // Handle % character
#define FLG 2  // Handle flag character (+,-,#,' ')
#define WDT 3  // Handle digit as width
#define PGV 4  // Precision Given (handle DOT in prep. for precision)
#define PRC 5  // Handle digit as precision
#define SIZ 6  // Handle size character (h or l)
#define SPC 7  // Handle space character (N,R,F)
#define TYP 8  // Handle type character (i,d,f,u,x,X,s,E,G,)
#define PST 9  // Handle pass through (%%)
#define NACTIONS 10

#define CR 13
#define LF 10

#define TRUE 1
#define FALSE 0

/*
						    P
						    E
				F   D		T   R	    S  O
				L   I	S	Y   C	    P  T
				A   G	I   D	P   E	A   A  H
				G   I	Z   O	E   N	S   C  E
				S   T	E   T	S   T	T   E  R	*/
static rom signed char pscan_fsa[NACTIONS][NCLASSES] = {
/* Init state:  INIT */      {ERR,ERR,ERR,ERR,ERR,PCT,ERR,ERR,ERR},
/* Got '%':      PCT */      {FLG,WDT,SIZ,PGV,TYP,PST,WDT,SPC,ERR},
/* Handle  flag: FLG */      {FLG,WDT,SIZ,PGV,TYP,ERR,WDT,SPC,ERR},
/* Handle width  WDT */      {ERR,WDT,SIZ,PGV,TYP,ERR,WDT,SPC,ERR},
/* Prpar for prec: 4 */      {ERR,PRC,ERR,ERR,TYP,ERR,PRC,ERR,ERR},
/* Hndl precision: 5 */      {ERR,PRC,SIZ,ERR,TYP,ERR,PRC,SPC,ERR},
/* Handle size:  SIZ */      {ERR,ERR,ERR,ERR,TYP,ERR,ERR,SPC,ERR},
/* Handle space: SPC */      {ERR,ERR,SIZ,ERR,TYP,ERR,ERR,ERR,ERR},
/* Get Type:     TYP */      {ACC,ACC,ACC,ACC,ACC,ACC,ACC,ACC,ACC},
/* pass through: PST */      {ACC,ACC,ACC,ACC,ACC,ACC,ACC,ACC,ACC},
			     };

/*************************************************
*
* _u_pscan - scan a printf format string
*
* Inputs:
*	fmt - pointer to format string
*	str - pointer to fmt_type structure
*	      where the results are put
*	argp - address of pointer to arguments for
*	       use with * precision or * field width
*
* Returns:
*	new pointer to format string
*
*************************************************/
PF_REENTRANT __CONST__ char far *_u_f_pscan (PRINT_FMT_ARG
      PRINT_CTRL_ARG
      __CONST__ char far * fmt
    , va_list * argp)
{
#ifdef __REENTRANT_PRINTFS__
#define __print_fmt (*print_fmt)
#define __print_crtl (*print_crtl)
#endif
  signed char pstate;
  signed char state = 0;
  unsigned char class;
  char ch;
  unsigned char precision_given = FALSE;

  for(;;) {
    ch = *(fmt++);
    switch (ch) {
      case '-':
      case '+':
      case ' ':
      case '#':
		class = SFLAGS;
		break;
      case '0':
      case '1':
      case '2':
      case '3':
      case '4':
      case '5':
      case '6':
      case '7':
      case '8':
      case '9':
		class = DIGIT;
		break;
      case '.':
		class = DOT;
		break;
      case '*':
		class = AST;
		break;
      case 'h':
      case 'l':
      case 'L':
		class = SIZE;
		break;
      case 'E':
#ifdef __ZNEO__
                if (*fmt == 'R')
                {
                   /* Treat %ERs as erom specification */
                   class = SPACE;
                   fmt++;
                   break;
                }
                /* Else fall into other TYPE cases */
#endif
      case 'd':
      case 'i':
      case 'o':
      case 'u':
      case 'x':
      case 'X':
      case 'f':
      case 'e':
      case 'g':
      case 'G':
      case 'c':
      case 's':
      case 'p':
      case 'n':
		class = TYPES;
		break;
#ifndef __EZ80__
#ifdef __S3__
      case 'P':
#else
      case 'F':
      case 'N':
#endif
      case 'R':
		class = SPACE;
		break;
#endif
      case '%':
		class = PERCENT;
		break;

      default:
		class = OTHER;
		break;
    }

    pstate = state;
    state = pscan_fsa[state][class];

    switch (state) {
      case ACC:
		__print_ctrl.status = FMT_OK;
		return(fmt-1);
      case ERR:
		__print_ctrl.status = FMT_ERR;
		return(fmt-1);

      case FLG:
		switch (ch) {

		  case '-':
			__print_fmt.flags |= FMT_FLAG_MINUS;
			break;
		  case '+':
			__print_fmt.flags |= FMT_FLAG_PLUS;
			break;
		  case ' ':
			__print_fmt.flags |= FMT_FLAG_SPACE;
			break;
		  case '#':
			__print_fmt.flags |= FMT_FLAG_POUND;
			break;
		}
		break;

      case WDT: // Get width
		if (ch == '*')
		  __print_fmt.field_width = va_arg(*argp,int);
		else {
		  if (pstate != state &&
			ch == '0')
		    __print_fmt.flags |= FMT_FLAG_PAD_ZERO;
		  __print_fmt.field_width = __print_fmt.field_width * 10 + (ch - '0');
		}
		break;
       case PGV:  // Prepare for precision
		precision_given = TRUE;
		break;
       case PRC:  // Precision
		precision_given = TRUE;
		if (ch == '*')
		  __print_fmt.precision = va_arg(*argp,int);
		else
		  __print_fmt.precision = __print_fmt.precision * 10 + (ch - '0');
		break;
      case SIZ:  // Size
		__print_fmt.size = ch;
		break;
      case SPC: // Space
#ifdef __S3__
                if (ch == 'P')
                {
                   // For S3, allow %PXs to print a string in _PageX
                   // and %P0s to print a string in _Page0.
                   // %Ps is equivalent to %P0s.
                   if (*fmt == 'X')
                   {
                      __print_fmt.space = 'X';
                      fmt++;
                   } else
                   {
                      __print_fmt.space = '0';
                      if (*fmt == '0')
                         fmt++;
                   }
                } else
#endif
		   __print_fmt.space = ch;
		break;
      case TYP: // Type
		__print_fmt.type = tolower(ch);
		if (isupper(ch))
		  __print_fmt.flags |= FMT_FLAG_UPPERCASE;
		if (__print_fmt.field_width < 0)
		{
		  __print_fmt.flags |= FMT_FLAG_MINUS;
		  __print_fmt.field_width = -__print_fmt.field_width;
		}
		if (!precision_given || __print_fmt.precision < 0)
		{
		  if (ch == 'e' ||
		      ch == 'E' ||
		      ch == 'g' ||
		      ch == 'G' ||
		      ch == 'f')
		    __print_fmt.precision = DEFAULT_PRECISION;
		  else
		    __print_fmt.precision = 0;
		}
                if (ch == 's' && precision_given)
		  __print_fmt.flags |= FMT_FLAG_PRECISION;
		break;
      case PST: // Pass through
		__print_ctrl.status = FMT_PASS_THRU;
		__print_ctrl.chr = ch;
		return(fmt);
    }
  }
}
