#include <algorithm>
#include <cstdio>
using namespace std;

bool	board[50][50];
int		dx[]{0, 0, 1, -1, -1, -1, 1, 1};
int		dy[]{1, -1, 0, 0, 1, -1, 1, -1};
int		w, h;

bool	safe(int x, int y) {
	return (min(x, y) >= 0 && x < h && y < w);
}

void	dfs(int x, int y) {
	board[x][y] = 0;
	for (int dir = 0;dir < 8; dir++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];
		if (board[nx][ny] && safe(nx, ny))
			dfs(nx, ny);
	}
}

int		main(void) {
	int		v, total;

	while ((scanf("%d%d", &w, &h)) && (w && h)) {
		total = 0;
		for (int i = 0;i < h;i++)
			for (int j = 0;j < w;j++) {
				scanf("%d", &v);
				board[i][j] = v;
			}
		for (int i = 0;i < h;i++)
			for (int j = 0;j < w;j++)
				if(board[i][j]) {
					dfs(i, j);
					total++;
				}
		printf("%d\n", total);
	}
}