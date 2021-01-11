#include <cstdio>

void	sol(unsigned long o, unsigned long t, int depth) {
	if (depth == 0) {
		printf("%ld\n", t);
		return;
	}
	sol(t, o + t, depth - 1);
}

int		main(void) {
	int		N;

	scanf("%d", &N);
	sol(0, 1, N-1);
	return (0);
}