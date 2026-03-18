/*************************************************
 *  Copyright (C) 1999-2006 by  Zilog, Inc.
 *  All Rights Reserved
 *************************************************/


#pragma once // Include this file only once
#ifndef STDIO_H
#define STDIO_H

#include <stdarg.h>
#include <zconst.h>

#define EOF		(-1)		/* end of file */
 
/* ANSI prototypes */
#ifndef SIZE_T_DEFINED
#define SIZE_T_DEFINED
typedef unsigned int size_t;
#endif
#include <format.h>

#define NULL		(void *)0

PF_REENTRANT int printf(__CONST__ char * format, ...);
PF_REENTRANT int n_printf(__CONST__ char near * format, ...);
PF_REENTRANT int f_printf(__CONST__ char far * format, ...);
#ifdef _PG_E_ENABLED
PF_REENTRANT int e_printf(__CONST__ char pageE * format, ...);
#endif
PF_REENTRANT int r_printf(__CONST__ char rom * format, ...);
#if __MODEL__ == 0
#define printf n_printf
#else
#define printf f_printf
#endif

int scanf(__CONST__ char * format, ...);
int n_scanf(__CONST__ char near * format, ...);
int f_scanf(__CONST__ char far * format, ...);
#ifdef _PG_E_ENABLED
int e_scanf(__CONST__ char pageE * format, ...);
#endif
int r_scanf(__CONST__ char rom * format, ...);
#if __MODEL__ == 0
#define scanf n_scan
#else
#define scanf f_scanf
#endif

PF_REENTRANT int sprintf(char * s,__CONST__ char * format, ...);
PF_REENTRANT int n_n_sprintf(char near * s,__CONST__ char near * format, ...);
PF_REENTRANT int n_f_sprintf(char near * s,__CONST__ char far * format, ...);
PF_REENTRANT int n_r_sprintf(char near * s,__CONST__ char rom * format, ...);
PF_REENTRANT int f_n_sprintf(char far * s,__CONST__ char near * format, ...);
PF_REENTRANT int f_f_sprintf(char far * s,__CONST__ char far * format, ...);
PF_REENTRANT int f_r_sprintf(char far * s,__CONST__ char rom * format, ...);
#ifdef _PG_E_ENABLED
PF_REENTRANT int n_e_sprintf(char near * s,__CONST__ char pageE * format, ...);
PF_REENTRANT int f_e_sprintf(char far * s,__CONST__ char pageE * format, ...);
PF_REENTRANT int e_n_sprintf(char pageE * s,__CONST__ char near * format, ...);
PF_REENTRANT int e_f_sprintf(char pageE * s,__CONST__ char far * format, ...);
PF_REENTRANT int e_e_sprintf(char pageE * s,__CONST__ char pageE * format, ...);
PF_REENTRANT int e_r_sprintf(char pageE * s,__CONST__ char rom * format, ...);
#endif
#if __MODEL__ == 0
#define sprintf n_n_sprintf
#else
#define sprintf f_f_sprintf
#endif

int sscanf(__CONST__ char * s,__CONST__ char * format, ...);
int n_n_sscanf(__CONST__ char near * s,__CONST__ char near * format, ...);
int n_f_sscanf(__CONST__ char near * s,__CONST__ char far * format, ...);
int n_r_sscanf(__CONST__ char near * s,__CONST__ char rom * format, ...);
int f_n_sscanf(__CONST__ char far * s,__CONST__ char near * format, ...);
int f_f_sscanf(__CONST__ char far * s,__CONST__ char far * format, ...);
int f_r_sscanf(__CONST__ char far * s,__CONST__ char rom * format, ...);
#ifdef _PG_E_ENABLED
int n_e_sscanf(__CONST__ char near * s,__CONST__ char pageE * format, ...);
int f_e_sscanf(__CONST__ char far * s,__CONST__ char pageE * format, ...);
int e_n_sscanf(__CONST__ char pageE * s,__CONST__ char near * format, ...);
int e_f_sscanf(__CONST__ char pageE * s,__CONST__ char far * format, ...);
int e_e_sscanf(__CONST__ char pageE * s,__CONST__ char pageE * format, ...);
int e_r_sscanf(__CONST__ char pageE * s,__CONST__ char rom * format, ...);
#endif
#if __MODEL__ == 0
#define sscanf n_n_sscanf
#else
#define sscanf f_f_sscanf
#endif

PF_REENTRANT int vprintf(__CONST__ char * format,va_list arg);
PF_REENTRANT int n_vprintf(__CONST__ char near * format,va_list arg);
PF_REENTRANT int f_vprintf(__CONST__ char far * format,va_list arg);
#ifdef _PG_E_ENABLED
PF_REENTRANT int e_vprintf(__CONST__ char pageE * format,va_list arg);
#endif
PF_REENTRANT int r_vprintf(__CONST__ char rom * format,va_list arg);
#if __MODEL__ == 0
#define vprintf n_vprintf
#else
#define vprintf f_vprintf
#endif

PF_REENTRANT int vsprintf(char * s,__CONST__ char * format,va_list arg);
PF_REENTRANT int n_n_vsprintf(char near * s,__CONST__ char near * format,va_list arg);
PF_REENTRANT int n_f_vsprintf(char near * s,__CONST__ char far * format,va_list arg);
PF_REENTRANT int n_r_vsprintf(char near * s,__CONST__ char rom * format,va_list arg);
PF_REENTRANT int f_n_vsprintf(char far * s,__CONST__ char near * format,va_list arg);
PF_REENTRANT int f_f_vsprintf(char far * s,__CONST__ char far * format,va_list arg);
PF_REENTRANT int f_r_vsprintf(char far * s,__CONST__ char rom * format,va_list arg);
#ifdef _PG_E_ENABLED
PF_REENTRANT int n_e_vsprintf(char near * s,__CONST__ char pageE * format,va_list arg);
PF_REENTRANT int f_e_vsprintf(char far * s,__CONST__ char pageE * format,va_list arg);
PF_REENTRANT int e_n_vsprintf(char pageE * s,__CONST__ char near * format,va_list arg);
PF_REENTRANT int e_f_vsprintf(char pageE * s,__CONST__ char far * format,va_list arg);
PF_REENTRANT int e_e_vsprintf(char pageE * s,__CONST__ char pageE * format,va_list arg);
PF_REENTRANT int e_r_vsprintf(char pageE * s,__CONST__ char rom * format,va_list arg);
#endif
#if __MODEL__ == 0
#define vsprintf n_n_vsprintf
#else
#define vsprintf f_f_vsprintf
#endif

char* gets(char * s);
#ifdef _PG_E_ENABLED
char pageE* e_gets(pageE char * s);
#endif
char far* f_gets(far char * s);
char near* n_gets(near char * s);
#if __MODEL__ == 0
#define gets n_gets
#else
#define gets f_gets
#endif

int puts(__CONST__ char * s);
int n_puts(__CONST__ char near * s);
int f_puts(__CONST__ char far * s);
#ifdef _PG_E_ENABLED
int e_puts(__CONST__ char pageE * s);
#endif
int r_puts(__CONST__ char rom * s);
#if __MODEL__ == 0
#define puts n_puts
#else
#define puts f_puts
#endif

int getchar(void);
int putchar(int c);

// ZiLOG extension, output string without the trailing newline
// provided for use in the assert macro but available for general use
int putsNOnl(__CONST__ char * s);
int n_putsNOnl(__CONST__ char near * s);
int f_putsNOnl(__CONST__ char far * s);
#ifdef _PG_E_ENABLED
int e_putsNOnl(__CONST__ char pageE * s);
#endif
int r_putsNOnl(__CONST__ char rom * s);
#if __MODEL__ == 0
#define putsNOln n_putsNOln
#else
#define putsNOln f_putsNOln
#endif

#endif
