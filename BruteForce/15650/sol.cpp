#include <cstdio>

int		a[8];
int		N, M;

void	combination(int s, int e, int depth) {
	if (depth == 0) {
		for(int i=0;i<M;i++)
			printf("%d ", a[i]);
		printf("\n");
		return ;
	}
	for (int i=s;i<=e-(depth -1);i++) {
		a[M-depth] = i;
		combination(i + 1, e, depth -1);
	}
}

int		main(void) {
	scanf("%d%d", &N, &M);
	combination(1, N, M);
}