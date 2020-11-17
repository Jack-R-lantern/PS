#include <stdio.h>

int		main(void) {
	int		sum = 0;
	int		a = 0;

	scanf("%d\n", &a);
	while (a--)
		sum  += getchar() - '0';
	printf("%d\n", sum);
	return (0);
}