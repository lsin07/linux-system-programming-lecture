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

/* Listing 30-1 */

/* thread_incr.c

   This program employs two POSIX threads that increment the same global
   variable, without using any synchronization method. As a consequence,
   updates are sometimes lost.

   Try protect shared resorce `glob` by adding mutex properly!
*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define LOOPS 10000000

static volatile int glob = 0;   /* "volatile" prevents compiler optimizations
                                   of arithmetic operations on 'glob' */

static void *threadFunc(void *arg)              /* Loop 'arg' times incrementing 'glob' */
{
    int loops = *((int *) arg);
    int loc, j;

    for (j = 0; j < loops; j++) {
        loc = glob;
        loc++;
        glob = loc;
    }

    return NULL;
}

int main(void)
{
    pthread_t t1, t2;
    int loops, s;

    loops = LOOPS;

    s = pthread_create(&t1, NULL, threadFunc, &loops);
    if (s != 0) {
        perror("pthread_create");
        exit(EXIT_FAILURE);
    }
    s = pthread_create(&t2, NULL, threadFunc, &loops);
    if (s != 0) {
        perror("pthread_create");
        exit(EXIT_FAILURE);
    }

    s = pthread_join(t1, NULL);
    if (s != 0) {
        perror("pthread_join");
        exit(EXIT_FAILURE);
    }
    s = pthread_join(t2, NULL);
    if (s != 0) {
        perror("pthread_join");
        exit(EXIT_FAILURE);
    }

    printf("glob = %d\n", glob);
    
    return 0;
}
