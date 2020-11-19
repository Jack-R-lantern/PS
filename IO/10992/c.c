#include <stdio.h>

int     main(void) {
    int     cnt;
    int     i, j;

    scanf("%d", &cnt);
    i = 0;
    while (i < cnt) {
        j = 0;
         while (j++ < cnt - i - 1)
            printf(" ");
        if (i != cnt - 1) {
            while (j++ <= cnt + i) {
                if (j - 1 == cnt + i || j - 2 == cnt - i -1)
                    printf("*");
                else
                    printf(" "); 
            }
        }
        else
            while (j++ <= 2 * cnt - 1)
                printf("*");
        printf("\n");
        i++;
    }
}