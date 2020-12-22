#include <algorithm>
#include <cstdio>
#include <queue>
using namespace std;

bool	board[25][25];
bool	visit[25][25];
int		dx[]{0, 0, 1, -1};
int		dy[]{1, -1, 0 ,0};
int		N;

bool	validate(int x, int y) {
	return (min(x,y) >= 0 && max(x, y) < N);
}

int		dfs(int x, int y) {
	int		total = 1;

	visit[x][y] = true;
	for (int dir = 0;dir < 4;dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (!visit[nx][ny] && board[nx][ny] && validate(nx, ny))
			total += dfs(nx, ny);
	}
	return (total);
}

int		main(void) {
	char	c;

	scanf("%d\n", &N);
	for (int i = 0;i < N;i++)
		for (int j = 0;j <= N;j++)
			if ((c = getchar()) && c != '\n')
				board[i][j] = c - '0';
	priority_queue<int, vector<int>, greater<int>>	pq;
	for (int i = 0;i < N;i++)
		for (int j = 0;j < N;j++)
			if (!visit[i][j] && board[i][j]) {
				pq.push(dfs(i, j));
			}
	printf("%ld\n",pq.size());
	while (!pq.empty()) {
		printf("%d\n", pq.top());
		pq.pop();
	}
	return (0);
}