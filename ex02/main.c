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

/* Listing 4-1 */

/* copy.c

   Copy the file named argv[1] to a new file named in argv[2].
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

#include <unistd.h>
#include <fcntl.h>

#ifndef BUF_SIZE        /* Allow "cc -D" to override definition */
#define BUF_SIZE 1024
#endif

int
main(int argc, char *argv[])
{
    if (argc != 3 || strcmp(argv[1], "--help") == 0) {
        fprintf(stderr, "%s old-file new-file\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    /* Open input file */
    /* ====================== write your code here ====================== */



    /* ================================================================== */
    if (inputFd == -1) {
        fprintf(stderr, "opening file %s", argv[1]);
        exit(EXIT_FAILURE);
    }

    int openFlags = O_CREAT | O_WRONLY | O_TRUNC;
    mode_t filePerms = S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP |
                       S_IROTH | S_IWOTH;      /* rw-rw-rw- */

    /* Open output file */
    /* ====================== write your code here ====================== */



    /* ================================================================== */
    if (outputFd == -1) {
        fprintf(stderr, "opening file %s", argv[2]);
        exit(EXIT_FAILURE);
    }

    /* Transfer data until we encounter end of input or an error */
    /* ====================== write your code here ====================== */



    /* ================================================================== */

    if (numRead == -1) {
        fprintf(stderr, "read");
        exit(EXIT_FAILURE);
    }

    /* close input file */
    /* ====================== write your code here ====================== */



    /* ================================================================== */

    if (close(outputFd) == -1) {
        fprintf(stderr, "close output");
        exit(EXIT_FAILURE);
    }

    return 0;
}
