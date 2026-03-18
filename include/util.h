#pragma once
#include "stk500.h"
#include <eZ8.h>
#include <stdio.h>
#include <sio.h> // non-standard I/O

/* Legacy utility functions - kept for compatibility */
void sync_ok_response(void);
void byte_response(UINT8 val);
void string_response(__CONST__ char* val);

/* Note: getNch and verifySpace are now implemented locally in terminal.c
 * to match optiboot's architecture */