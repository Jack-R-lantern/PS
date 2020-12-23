#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <tuple>
using namespace std;

pair<int, int>	s, t;
bool	board[300][300];
int		dx[]{2, 2, 1, 1, -2, -2, -1, -1};
int		dy[]{1, -1, 2, -2, 1, -1, 2, -2};
int		T, I;

bool	safe(int x, int y) {
	return (min(x,y) >= 0 && max(x,y) < I);
}

int		bfs(void) {
	queue<tuple<int, int, int>>	q;
	int	x, y, d = 0;

	q.push({s.first, s.second, d});
	while(!q.empty()) {
		tie(x, y, d) = q.front();
		q.pop();
		if (x == t.first && y == t.second)
			break;
		for (int dir = 0; dir < 8; dir++) {
			int	nx = x + dx[dir];
			int ny = y + dy[dir];
			if(!board[nx][ny] && safe(nx, ny)) {
				board[nx][ny] = 1;
				q.push({nx, ny, d + 1});
			}
		}
	}
	return (d);
}

int		main(void) {
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &I);
		scanf("%d %d", &s.first, &s.second);
		scanf("%d %d", &t.first, &t.second);
		memset(board, 0, sizeof(board));
		printf("%d\n", bfs());
	}
	return (0);
}