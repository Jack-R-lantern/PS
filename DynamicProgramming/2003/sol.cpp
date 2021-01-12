#include <cstdio>

int		main(void) {
	int		N, M, total = 0, cnt = 0;
	int		i = 0, j = 0;
	int		arr[10001];

	scanf("%d%d",&N, &M);
	for (int i=0;i<N;i++)
		scanf("%d", &arr[i]);
	while (j<=N) {
		if (total == M)
			cnt++;
		if (total >= M)
			total -= arr[i++];
		else
			total += arr[j++];
	}
	printf("%d\n", cnt);
	return (0);
}