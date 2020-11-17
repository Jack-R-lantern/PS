#include <stdio.h>

int		main(void) {
	int		cnt, i;
	int		a, b;

	scanf("%d", &cnt);
	i = cnt;
	while (cnt--) {
		scanf("%d %d", &a, &b);
		printf("Case #%d: %d + %d = %d\n",i - cnt, a, b, a + b);
	}
	return (0);
}