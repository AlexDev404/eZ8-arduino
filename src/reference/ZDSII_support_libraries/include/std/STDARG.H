/*************************************************
 *  Copyright (C) 1999-2006 by  Zilog, Inc.
 *  All Rights Reserved
 *************************************************/

#pragma once // Include this file only once
#ifndef STDARG_H
#define STDARG_H

typedef char * va_list;
#define va_start(ap, parm) ap = (char *)&parm + sizeof(parm)
#define va_arg(ap, type) (ap += sizeof(type), * (type *)(ap - sizeof(type)))
#define va_end(ap)

#endif
