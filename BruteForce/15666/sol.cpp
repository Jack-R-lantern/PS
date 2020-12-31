#include <algorithm>
#include <cstdio>

int		a[8], r[9];
int		N, M;

void	sol(int s, int depth) {
	if (depth == 0) {
		for (int i=0;i<M;i++)
			printf("%d ", r[i]);
		printf("\n");
		return ;
	}
	for (int i=s;i<N;i++) {
		if (r[M-depth] == a[i]) continue;
		r[M-depth] = a[i];
		sol (i, depth - 1);
		r[M-depth+1] = 0;
	}
}

int		main(void) {
	scanf("%d%d", &N, &M);
	for (int i=0;i<N;i++)
		scanf("%d", &a[i]);
	std::sort(a,a+N);
	sol(0, M);
	return (0);
}