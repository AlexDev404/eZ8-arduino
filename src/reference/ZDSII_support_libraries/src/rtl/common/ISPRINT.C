/*************************************************
 *  Copyright (C) 1999-2008 by  Zilog, Inc.
 *  All Rights Reserved
 *************************************************/

#define CTL	0x80	/* control character */
#define WS	0x40	/* whitespace character */
#define SP	0x20	/* space character */
#define HEX	0x10	/* hex digit (A-Z,a-z) */
#define UC	0x08	/* uppercase letter */
#define LC	0x04	/* lowercase letter */
#define PUN	0x02	/* punctuation */
#define DIG	0x01	/* decimal digit (0-9) */

extern rom unsigned char __maptab[];

int isprint(int c)
{
  if (c < 0 || c > 127)
    return(0);
  return(__maptab[c] & (UC|LC|DIG|PUN|SP));
}
