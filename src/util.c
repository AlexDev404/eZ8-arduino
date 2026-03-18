#include "util.h"
#include "flash_tools.h"

void sync_ok_response(void)
{
	if (getch() == SPECIAL_Sync_CRC_EOP) { // Check if next command (typically Sync_CRC_EOP) is received
		putch(STK_INSYNC);
		putch(STK_OK);
	} else {
		putch(STK_NOSYNC);
	}
}

void byte_response(UINT8 val)
{
	if (getch() == SPECIAL_Sync_CRC_EOP) { // Check if next command (typically Sync_CRC_EOP) is received
		putch(STK_INSYNC);
		putch(val);
		putch(STK_OK);
	} else {
		putch(STK_NOSYNC);
	}
}
void string_response(__CONST__ char* val)
{
	if (getch() == SPECIAL_Sync_CRC_EOP) { // Check if next command (typically Sync_CRC_EOP) is received
		putch(STK_INSYNC);
		puts(val);
		putch(STK_OK);
	}
	else {
		putch(STK_NOSYNC);
	}
}

void getNch(UINT8 count) {
  do getch(); while (--count);
  putch(STK_INSYNC);
  putch(STK_OK);
}

// FUTURE
/*void trigger_watchdog() {
  if (getch() != SPECIAL_Sync_CRC_EOP) {
	
    watchdogConfig(WATCHDOG_16MS);    // shorten WD timeout
    while (1)			      // A busy-loop so that WD causes
      ;				      //  a reset and app start.
  }
  putch(STK_INSYNC);
}*/
