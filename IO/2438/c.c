#include <stdio.h>

int		main(void) {
	int		cnt;
	int		i, j;

	scanf("%d", &cnt);
	i = 0;
	while (i < cnt) {
		j = 0;
		while (j <= i) {
			printf("*");
			j++;
		}
		printf("\n");
		i++;
	}
	return (0);
}
