#include <stdio.h>
#include <stdlib.h>

int     main(void) {
    int     cnt;
    int     i, j;

    scanf("%d", &cnt);
    i = 0;
    while (i < cnt) {
        j = 0;
        while (j++ < cnt - i - 1)
            printf(" ");
        while (j++ <= cnt + i)
            if (((cnt % 2 == 0) && ((i + j) % 2 == 1)) || ((cnt % 2 == 1) && ((i + j) % 2 == 0)))
                printf("*");
            else
                printf(" ");
        printf("\n");
        i++;
    }
    return (0);
}