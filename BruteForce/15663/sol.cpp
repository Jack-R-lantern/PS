#include <algorithm>
#include <cstdio>

bool	b[8];
int		a[8], r[9];
int		N, M;

void	sol(int depth) {
	if (depth == 0) {
		for (int i=0;i<M;i++)
			printf("%d ",r[i]);
		printf("\n");
		return ;
	}
	for (int i=0;i<N;i++) {
		if (b[i] || r[M-depth] == a[i]) continue;
		b[i] = true;
		r[M-depth] = a[i];
		sol(depth - 1);
		r[M-depth + 1] = 0;
		b[i] = false;
	}
}

int		main(void) {
	scanf("%d%d", &N, &M);
	for (int i=0;i<N;i++)
		scanf("%d", &a[i]);
	std::sort(a,a+N);
	sol(M);
	return (0);
}