/*************************************************
 *  Copyright (C) 1999-2006 by  Zilog, Inc.
 *  All Rights Reserved
 *************************************************/

#pragma once // Include this file only once
#ifndef CTYPE_H
#define CTYPE_H

#define TRUE 1
#define FALSE 0

int isalnum(int c);
int isalpha(int c);
int iscntrl(int c);
int isdigit(int c);
int isgraph(int c);
int islower(int c);
int isprint(int c);
int ispunct(int c);
int isspace(int c);
int isupper(int c);
int isxdigit(int c);
int tolower(int c);
int toupper(int c);
#endif
