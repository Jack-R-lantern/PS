#include <cstdio>

bool	t[9];
int		a[8];
int		N, M;

void	permutation(int depth) {
	if (depth == 0) {
		for (int i=0;i<M;i++)
			printf("%d ", a[i]);
		printf("\n");
		return ;
	}
	for (int i=1;i<=N;i++) {
		if (t[i]) continue;
		a[M - depth] = i;
		t[i] = true;
		permutation(depth - 1);
		t[i] = false;
	}
}

int		main(void) {
	scanf("%d%d", &N, &M);
	permutation(M);
	return (0);
}