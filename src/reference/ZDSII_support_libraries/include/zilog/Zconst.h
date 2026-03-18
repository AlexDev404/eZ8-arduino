/*************************************************
 *  Copyright (C) 2005-2006 by  Zilog, Inc.
 *  All Rights Reserved
 *************************************************/

#pragma once // Include this file only once
/*
 *  The __CONST__ macro is used for variables that, according to the ANSI
 *  standard, ought to be const.  On Harvard Architectures, this causes
 *  problems; especially if the option -const:ROM is used.  The macro
 *  expands to the keyword const on architectures where there is no problem;
 *  where there are potential problems the macro expands to white space
 *  but serves as a documentary aid.
 *
 *  ZiLOG users may override this file, for example to force correct prototypes
 *  on the ENCORE, by using an option such as -define __CONST__=const
 *  on the command line.
 */
#ifndef __CONST__

#ifdef __EZ8__
# ifdef __CONST_IN_RAM__
#  define __CONST__ const
# else
#  define __CONST__
# endif
#endif

#ifdef __Z8__
# ifdef __CONST_IN_RAM__
#  define __CONST__ const
# else
#  define __CONST__
# endif
#endif

#ifdef __EZ80__
#define __CONST__ const
#endif

#ifdef __ZNEO__
#define __CONST__ const
#endif

#ifndef __CONST__
#define __CONST__ const
#endif

#endif  /* __CONST__ */

