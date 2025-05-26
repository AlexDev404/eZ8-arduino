#pragma once
#include "stk500.h"
#include <eZ8.h>
#include <stdio.h>
#include <sio.h> // non-standard I/O

void sync_ok_response(void);
void byte_response(UINT8 val);
void string_response(__CONST__ char* val);
void getNch(UINT8 count);
//void trigger_watchdog(); // FUTURE