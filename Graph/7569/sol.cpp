#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

queue<tuple<int, int, int, int>>	q;
tuple<int, int, int>				dir[6] = {{1, 0, 0}, {-1, 0, 0}, {0, 1, 0}, {0, -1, 0}, {0, 0, 1}, {0, 0, -1}};
int			board[100][100][100];
int			M, N, H;
int			cnt;

bool	safe(int x, int y, int z) {
	return (x >= 0 && y >= 0 && z >= 0 && x < M && y < N && z < H);
}

int		bfs(void) {
	int	x, y, z, d;

	while (!q.empty()) {
		tie(x, y, z, d) = q.front();
		q.pop();
		for (int i=0;i<6;i++) {
			int nx, ny, nz;
			tie(nx, ny, nz) = dir[i];
			nx = x + nx;
			ny = y + ny;
			nz = z + nz;
			if (safe(nx, ny, nz) && !board[nx][ny][nz]) {
				q.push({nx, ny, nz, d + 1});
				board[nx][ny][nz] = d + 1;
				cnt--;
			}
		}
	}
	if (!cnt)
		return (d);
	else
		return (-1);
}

int		main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> M >> N >> H;
	for (int i=0;i<H;i++) {
		for (int j=0;j<N;j++) {
			for (int k=0;k<M;k++) {
				cin >> board[k][j][i];
				if (board[k][j][i] == 1)
					q.push({k, j, i, 0});
				else if (!board[k][j][i])
					cnt++;
			}
		}
	}
	cout << bfs() << "\n";
	return (0);
}