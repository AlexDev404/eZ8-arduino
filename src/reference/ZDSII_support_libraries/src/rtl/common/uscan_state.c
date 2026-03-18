/*************************************************
 *  Copyright (C) 1999-2007 by  ZiLOG, Inc.
 *  All Rights Reserved
 *************************************************/

#include <format.h>
#include "scanf.h"

/* classes */

#define PERCENT 0
#define AST 1
#define SIZE 2
#define DIGIT 3
#define TYPES 4
#define SET_BEGIN 5
#define SET_END 6
#define SPACE 7
#define OTHER 8
#define NCLASSES 9


#define TRUE 1
#define FALSE 0


/*				       +-{0..9}
			        {h,l,L}|   +-{d,i,o,u,x,e,f,g,s,c,p,n}
			           |   |   |        {N,F,R}{others}
			   %   *   |   |   |   [   ]   |   |
			+-----------------------------------+ */
static rom signed char sscan_fsa[NACTIONS][NCLASSES] = {
	/*INI*/ 	{PCT,PST,PST,PST,PST,PST,PST,PST,PST},
	/*PCT*/ 	{PST,IGN,SIZ,WDT,TYP,SET,ERR,SPC,ERR},
	/*IGN*/ 	{ERR,ERR,SIZ,WDT,TYP,SET,ERR,SPC,ERR},
	/*WDT*/ 	{ERR,ERR,SIZ,WDT,TYP,SET,ERR,SPC,ERR},
	/*SIZ*/ 	{ERR,ERR,ERR,ERR,TYP,SET,ERR,SPC,ERR},
	/*SPC*/ 	{ERR,ERR,SIZ,ERR,TYP,SET,ERR,ERR,ERR},
	/*SET*/ 	{SET,SET,SET,SET,SET,SET,EST,SET,SET},
	/*EST*/ 	{ACC,ACC,ACC,ACC,ACC,ACC,ACC,ACC,ACC},
	/*PST*/ 	{ACC,ACC,ACC,ACC,ACC,ACC,ACC,ACC,ACC},
	/*TYP*/ 	{ACC,ACC,ACC,ACC,ACC,ACC,ACC,ACC,ACC},
			};

signed char _u_sscan_state(char ch, signed char state)
{


  unsigned char class;


  switch(ch)
  {
   case '%':
    class = PERCENT;
    break;
   case '*':
    class = AST;
    break;
   case 'h':   case 'l':   case 'L':
    class = SIZE;
    break;
   case '0':   case '1':   case '2':   case '3':   case '4':
   case '5':   case '6':   case '7':   case '8':   case '9':
    class = DIGIT;
    break;
   case 'A':   case 'E':   case 'G':   case 'X':
   case 'a':   case 'c':   case 'd':   case 'e':   case 'f':
   case 'g':   case 'i':   case 'n':   case 'o':   case 'p':
   case 's':   case 'u':   case 'x':
    class = TYPES;
    break;
   case 'F':
   case 'N':
   case 'R':
    class = SPACE;
    break;
   case '[':
    class = SET_BEGIN;
    break;
   case ']':
    class = SET_END;
    break;
   default:
    class = OTHER;
  }

  return sscan_fsa[state][class];
}

