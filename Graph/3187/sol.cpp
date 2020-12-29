#include <cstdio>
#include <queue>
#include <tuple>
using namespace std;

char	board[251][251];
bool	visit[251][251];
int		dx[]{0, 0, 1, -1};
int		dy[]{1, -1, 0, 0};
int		R, C, v, k;

bool	safe(int x, int y) {
	return (x >= 0 && y >=0 && x < R && y < C);
}

void	bfs(int x, int y) {
	queue<tuple<int, int, char>>	q;
	char	c;
	int		curv = 0, curk = 0;

	q.push({x, y, board[x][y]});
	board[x][y] = '#';
	while(!q.empty()) {
		tie(x, y, c) = q.front();
		q.pop();
		if (c == 'v')
			curv++;
		else if (c == 'k')
			curk++;
		for (int dir=0;dir<4;dir++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];
			if (safe(nx, ny) && board[nx][ny] != '#') {
				q.push({nx, ny, board[nx][ny]});
				board[nx][ny] = '#';
			}
		}
	}
	if (curv >= curk)
		v += curv;
	else
		k += curk;
}

int		main(void) {
	scanf("%d%d", &R, &C);
	for (int i=0;i<R;i++)
		scanf("%s", board[i]);
	for (int i=0;i<R;i++)
		for (int j=0;j<C;j++)
			if (board[i][j] == 'v' || board[i][j] == 'k')
				bfs(i, j);
	printf("%d %d\n", k, v);
	return (0);
}