#include <stdio.h>

int		main(void) {
	int		cnt;
	int		a, b;

	scanf("%d", &cnt);
	while (cnt--) {
		scanf("%d %d", &a, &b);
		printf("%d\n", a + b);
	}
	return (0);
}