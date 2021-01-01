#include <cstdio>

int		a[20];
int		N, S;

int		dfs(int depth, int sum) {
	if (depth == N)
		return (sum == S);
	else
		return dfs(depth+1, sum) + dfs(depth+1, sum + a[depth]);
}

int		main(void) {
	scanf("%d%d", &N, &S);
	for (int i=0;i<N;i++)
		scanf("%d", &a[i]);
	printf("%d\n", dfs(0,0) + (!S ? -1 : 0));
	return (0);
}