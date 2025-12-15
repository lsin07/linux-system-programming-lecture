/*************************************************************************\
*                  Copyright (C) Michael Kerrisk, 2025.                   *
*                  Modified by Sein Lee on Dec 15, 2025.                  *
*                                                                         *
* This program is free software. You may use, modify, and redistribute it *
* under the terms of the GNU General Public License as published by the   *
* Free Software Foundation, either version 3 or (at your option) any      *
* later version. This program is distributed without any warranty.  See   *
* the file COPYING.gpl-v3 for details.                                    *
\*************************************************************************/

/* Listing 24-1 */

/* t_fork.c

   Demonstrate the use of fork(), showing that parent and child
   get separate copies of stack and data segments.
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

static int idata = 111;             /* Allocated in data segment */

int main(void)
{
    int istack = 222;               /* Allocated in stack segment */
    pid_t childPid;

    /* fork a process, and make a calculation only on child process */
    /* ====================== write your code here ====================== */



    /* ================================================================== */

    /* Both parent and child come here */

    printf("PID=%ld %s idata (%p) = %d istack (%p) = %d\n", (long) getpid(),
            (childPid == 0) ? "(child) " : "(parent)", &idata, idata, &istack, istack);

    return 0;
}
