#include <cstdio>
#include <queue>
#include <tuple>
using namespace std;

queue<tuple<int, int, int, int>>	q;
pair<int, int>	horse[]{{2, 1}, {2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {-2, 1}, {-2, -1}};
pair<int, int>	monkey[]{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int		board[200][200];
bool	visit[200][200][31];
int		K, W, H;

bool	safe(int x, int y) {
	return (x >= 0 && y >= 0 && x < H && y < W);
}

int		bfs(void) {
	int	x, y, k, cnt;
	while (!q.empty()) {
		tie(x, y ,k, cnt) = q.front();
		q.pop();
		if (x == H - 1 && y == W - 1)
			return (cnt);
		if (k < K) {
			for (int i=0;i<8;i++) {
				int	nx = x + horse[i].first;
				int	ny = y + horse[i].second;

				if (safe(nx, ny))
					if (!board[nx][ny] && !visit[nx][ny][k + 1]) {
						visit[nx][ny][k + 1] = true;
						q.push({nx, ny, k+1, cnt+1});
					}
			}
		}
		for (int i=0;i<4;i++) {
			int nx = x + monkey[i].first;
			int ny = y + monkey[i].second;

			if (safe(nx, ny))
				if (!board[nx][ny] && !visit[nx][ny][k]) {
					visit[nx][ny][k] = true;
					q.push({nx, ny, k, cnt+1});
				}
		}
	}
	return (-1);
}

int		main(void) {
	scanf("%d", &K);
	scanf("%d%d", &W, &H);
	for(int i=0;i<H;i++)
		for(int j=0;j<W;j++)
			scanf("%d", &board[i][j]);
	q.push({0,0,0,0});
	visit[0][0][0] = true;
	printf("%d\n", bfs());
	return (0);
}