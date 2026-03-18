
extern signed char _u_sscan_state(char ch, signed char state);

/* Values returned by _u_sscan_state, being the action to perform on
 * the current character and the state for the next call
 *
 * Not to be confused with largely same defines for printf, in
 * upscan.c or files derived from upscan.tpl, which are local to those files.
 */

#pragma once    // Include this file only once
#define ACC -1 // Accept
#define ERR -2 // Error
#define INIT 0 // Initial state
#define PCT 1  // Handle % character
#define IGN 2  // Ignore
#define WDT 3  // Handle digit as width
#define SIZ 4  // Handle size character (h or l)
#define SPC 5  // Handle space character (R, N, F)
#define SET 6  // Handle set (chars between [ and ])
#define EST 7  // Handle end of set ( ] )
#define PST 8  // Handle pass through (%%)
#define TYP 9  // Handle pass type (d,i,o,u,s,etc)
#define NACTIONS 10
