#include <iostream>
#include <tuple>
#include <queue>
#include <unistd.h>
using namespace std;

int		N, M;
int		grid[50][50];
int		dx[]{-1, 0, 1, 0};
int		dy[]{0, 1, 0, -1};
int		ld[]{3, 0, 1, 2};
int		bd[]{2, 3, 0, 1};
queue<tuple<int, int, int, int>>	q;

bool	safe(int x, int y) {
	return (x >= 0 && y >= 0 && x < N  && y < M);
}

int		bfs(int x, int y, int dir) {
	q.push({x, y, dir, 1});
	grid[x][y] = 2;
	int		cnt;
	bool	back = false;
	while(!q.empty()) {
		tie(x, y, dir, cnt) = q.front();
		q.pop();
		for (int i=0;i<4;++i) {
			int nx = x + dx[ld[dir]];
			int ny = y + dy[ld[dir]];
			if (safe(nx, ny) && grid[nx][ny] == 0) {
				q.push({nx, ny, ld[dir], cnt + 1});
				grid[nx][ny] = 2;
				back = false;
				break;
			}
			dir = ld[dir];
			back = true;
		}

		if (back) {
			int bx = x + dx[bd[dir]];
			int by = y + dy[bd[dir]];
			if ((safe(bx, by) && grid[bx][by] == 1) || !safe(bx, by))
				break;
			else
				q.push({bx, by, dir, cnt});
		}
	}
	return cnt;
}

int		main(void) {
	int x, y, dir;

	cin >> N >> M;
	cin >> x >> y >> dir;
	for (int i=0;i<N;++i)
		for (int j=0;j<M;++j)
			cin >> grid[i][j];
	cout << bfs(x, y, dir) << endl;
	return (0);
}