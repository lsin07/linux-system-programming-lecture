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

/* Listing 44-2 */

/* simple_pipe.c

   Simple demonstration of the use of a pipe to communicate
   between a parent and a child process.

   Usage: simple_pipe "string"

   The program creates a pipe, and then calls fork() to create a child process.
   After the fork(), the parent writes the string given on the command line
   to the pipe, and the child uses a loop to read data from the pipe and
   print it on standard output.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define BUF_SIZE 10

int main(int argc, char *argv[])
{
    /* create pipe file descripters */
    /* ====================== write your code here ====================== */



    /* ================================================================== */

    char buf[BUF_SIZE];
    ssize_t numRead;

    if (argc != 2 || strcmp(argv[1], "--help") == 0) {
        fprintf(stderr, "Usage: %s string\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    /* Create the pipe */
    /* ====================== write your code here ====================== */



    /* ================================================================== */

    switch (fork()) {
    case -1:
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    case 0:             /* Child  - reads from pipe */
        if (close(pfd[1]) == -1)            /* Write end is unused */
        {
            perror("close - child");
            exit(EXIT_FAILURE);
        }

        /* Read data from pipe, echo on stdout */
        /* ====================== write your code here ====================== */



        /* ================================================================== */

        write(STDOUT_FILENO, "\n", 1);
        if (close(pfd[0]) == -1)
        {
            perror("close");
            exit(EXIT_FAILURE);
        }
        exit(EXIT_SUCCESS);

    default:            /* Parent - writes to pipe */
        if (close(pfd[0]) == -1)            /* Read end is unused */
        {
            perror("close - parent");
            exit(EXIT_FAILURE);
        }

        /* write to pipe */
        /* ====================== write your code here ====================== */



        /* ================================================================== */

        if (close(pfd[1]) == -1)            /* Child will see EOF */
        {
            perror("close");
            exit(EXIT_FAILURE);
        }
        wait(NULL);                         /* Wait for child to finish */

        exit(EXIT_SUCCESS);
    }

    return 0;

}
