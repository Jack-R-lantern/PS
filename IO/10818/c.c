#include <stdio.h>

int		main(void) {
	int		cnt;
	int		max = 0, min = 0;
	int		temp;

	scanf("%d", &cnt);
	scanf("%d", &temp);
	cnt--;
	max = temp;
	min = temp;
	while (cnt--) {
		scanf("%d", &temp);
		if (temp > max)
			max = temp;
		else if (temp < min)
			min = temp;
	}
	printf("%d %d\n",min, max);
	return (0);
}