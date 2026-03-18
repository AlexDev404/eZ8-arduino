/*************************************************
 *  Copyright (C) 1999-2006 by  Zilog, Inc.
 *  All Rights Reserved
 *************************************************/

/*
  Buffer Layout:	r14
			r15	;frame pointer.
			rp	;register pointer.
			spl	;stack pointer low.
			sph	;stack pointer high.
			retpch	;return pc low.
			retpcl	;return pc high.

*/

#pragma once // Include this file only once
#ifndef SETJMP_H
#define SETJMP_H

typedef unsigned char far jmp_buf[7];

int setjmp(jmp_buf env);
void longjmp(jmp_buf env,int val);

#endif
