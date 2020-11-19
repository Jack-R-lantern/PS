#include <stdio.h>

int		main(void) {
	char	*day[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
	int		month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int		x, y;
	int		i;
	int		sum;

	i = 0;
	sum = 0;
	scanf("%d %d", &x, &y);
	while (i < x - 1) {
		sum += month[i];
		i++;
	}
	sum += y;
	printf("%s\n", day[sum % 7]);
	return (0);
}