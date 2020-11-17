#include <stdio.h>

int		main(void) {
	char	a[101] = {0};
	int		i = 0;
	scanf("%s", a);
	while(printf("%.10s\n", a + i) == 11)
		i += 10;
	return (0);
}