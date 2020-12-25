#include <cstdio>
#include <queue>
using namespace std;

bool	visit[100001];
int		N, K;
int		dx[]{1, -1};

bool	safe(int x) {
	return (x >= 0 && x <= 100000);
}

int		bfs(void) {
	queue<pair<int, int>>	q;
	int	x, nx, d = 0;

	q.push({N, d});
	visit[N] = true;
	while (!q.empty()) {
		x = q.front().first;
		d = q.front().second;
		q.pop();
		if (x == K)
			return (d);
		for (int i = 0;i < 3;i++) {
			if (i != 2) {
				nx = x + dx[i];
				if (safe(nx) && !visit[nx]) {
					q.push({nx, d + 1});
					visit[nx] = 1;
				}
			} else {
				nx = 2 * x;
				if (safe(nx) && !visit[nx]) {
					q.push({nx, d + 1});
					visit[nx] = 1;
				}
			}
		}
	}
	return (0);
}

int		main(void) {
	scanf("%d %d", &N, &K);
	printf("%d\n", bfs());
	return (0);
}