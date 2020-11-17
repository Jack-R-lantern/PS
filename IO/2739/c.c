#include <stdio.h>

int		main(void) {
	int		n, i;

	i = 1;
	scanf("%d", &n);
	while (i <= 9)
		printf("%d * %d = %d\n", n, i++, n * i);
	return (0);
}