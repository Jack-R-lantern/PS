#include <cstdio>

int		a[8];
int		N, M;

void	increfunc(int s, int e, int depth) {
	if (depth == 0) {
		for (int i=0;i<M;i++)
			printf("%d ", a[i]);
		printf("\n");
		return ;
	}
	for (int i=s;i<=e;i++) {
		a[M-depth] = i;
		increfunc(i, e, depth - 1);
	}
}
int		main(void) {
	scanf("%d%d", &N, &M);
	increfunc(1, N, M);
	return (0);
}