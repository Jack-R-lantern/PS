#include <stdio.h>

int		main(void) {
	int		cnt;
	scanf("%d", &cnt);
	while (cnt)
		printf("%d\n", cnt--);
	return (0);
}