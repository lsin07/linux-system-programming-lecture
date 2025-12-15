#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

/* ====================== write your code here ====================== */



/* ================================================================== */

int main(void)
{
    /* ====================== write your code here ====================== */



    /* ================================================================== */

    while (1)
    {
        printf("\r      \r");
        fflush(stdout);
        for (int i = 0; i < 3; i++) {
            printf(".");
            fflush(stdout);
            sleep(1);
        }
    }
    
    return 0;
}