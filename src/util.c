/*
 * Utility functions for STK500v1 bootloader
 * Note: verifySpace and getNch are now implemented locally in terminal.c
 * to match optiboot's architecture.
 */
#include "util.h"
#include "flash_tools.h"

/* These legacy functions are kept for compatibility but may not be used */

void sync_ok_response(void)
{
	if (getch() == SPECIAL_Sync_CRC_EOP) {
		putch(STK_INSYNC);
		putch(STK_OK);
	} else {
		putch(STK_NOSYNC);
	}
}

void byte_response(UINT8 val)
{
	if (getch() == SPECIAL_Sync_CRC_EOP) {
		putch(STK_INSYNC);
		putch(val);
		putch(STK_OK);
	} else {
		putch(STK_NOSYNC);
	}
}

void string_response(__CONST__ char* val)
{
	if (getch() == SPECIAL_Sync_CRC_EOP) {
		putch(STK_INSYNC);
		puts(val);
		putch(STK_OK);
	}
	else {
		putch(STK_NOSYNC);
	}
}
