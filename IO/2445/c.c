#include <stdio.h>
#include <stdlib.h>

int     main(void) {
    int     cnt;
    int     i, j;

    scanf("%d", &cnt);
    i = 0;
    while (i < cnt) {
        j = 0;
        while (j++ <= i)
            printf("*");
        while (j++ <= 2 * cnt - 1 - i)
            printf(" ");
        while (j++ <= 2 * cnt + 1)
            printf("*");
        printf("\n");
        i++;
    }
    i = cnt - 2;
    while (i >= 0) {
        j = 0;
         while (j++ <= i)
            printf("*");
        while (j++ <= 2 * cnt - 1 - i)
            printf(" ");
        while (j++ <= 2 * cnt + 1)
            printf("*");
        printf("\n");
        i--;
    }
    return (0);
}