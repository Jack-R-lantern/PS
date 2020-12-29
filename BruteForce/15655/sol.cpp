#include <algorithm>
#include <cstdio>
using namespace std;

int		a[8], r[8];
int		N, M;

void	stincfunc(int s, int depth) {
	if (depth == 0) {
		for (int i=0;i<M;i++)
			printf("%d ", r[i]);
		printf("\n");
		return ;
	}
	for (int i=s;i<N;i++) {
		r[M-depth] = a[i];
		stincfunc(i+1, depth-1);
	}
}

int		main(void) {
	scanf("%d%d", &N, &M);
	for (int i=0;i<N;i++)
		scanf("%d", &a[i]);
	sort(a, a+N);
	stincfunc(0, M);
	return (0);
}