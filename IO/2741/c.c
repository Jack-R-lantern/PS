#include <stdio.h>

int		main(void) {
	int		cnt;

	scanf("%d", &cnt);
	int		i = 1;
	while (cnt--)
		printf("%d\n", i++);
	return (0);
}