#include <stdio.h>
#include <stdlib.h>

int		main(void) {
	int		cnt;
	int		i, j;

	scanf("%d", &cnt);
	i = 0;
	while (i <  2 * cnt - 1) {
		j = 0;
		while (j++ < abs(cnt - i - 1))
			printf(" ");
		if (i < cnt)
			while (j++ <= cnt + i)
				printf("*");
		else
			while (j++ < 2 * cnt - i % cnt - 1)
				printf("*");
		printf("\n");
		i++;
	}
	return (0);
}