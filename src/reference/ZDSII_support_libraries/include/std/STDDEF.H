/*************************************************
 *  Copyright (C) 1999-2006 by  Zilog, Inc.
 *  All Rights Reserved
 *************************************************/


#pragma once // Include this file only once
#ifndef STDDEF_H
#define STDDEF_H

#ifndef SIZE_T_DEFINED
#define SIZE_T_DEFINED
typedef unsigned int size_t;
#endif

#define NULL	(void *)0
 
#define offsetof(type,member)   ((size_t) &((type*)0)->member)

typedef long ptrdiff_t;

#ifndef WCHAR_T_DEFINED
#define WCHAR_T_DEFINED
typedef unsigned short wchar_t;
#endif

#endif
