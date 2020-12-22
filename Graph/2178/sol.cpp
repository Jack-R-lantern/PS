#include <algorithm>
#include <cstdio>
#include <cstring>
#include <queue>
#include <tuple>
using namespace std;

const int	SIZE = 100;
bool		board[SIZE][SIZE];
int			dx[]{0, 0, 1, -1};
int			dy[]{1, -1, 0, 0};
int			N, M;

bool	safe(int x, int y) {
	return (min(x, y) >= 0 && (x < N && y < M));
}

int		bfs(void) {
	queue<tuple<int, int, int>>	q;
	int		distance = 1;
	q.push({0, 0, 1});
	board[0][0] = 0;
	while (!q.empty()) {
		int	x, y, d;
		tie(x,y,d) = q.front();
		q.pop();
		if (x == N - 1 && y == M - 1) {
			distance = d;
			break;
		}
		for(int i = 0;i < 4;i++) {
			int	nx = x + dx[i];
			int ny = y + dy[i];
			if (board[nx][ny] && safe(nx, ny)) {
				board[nx][ny] = 0;
				q.push({nx, ny, d + 1});
			}
		}
	}
	return (distance);
}
int		main(void) {
	char	ch;

	scanf("%d %d\n", &N, &M);
	for (int i = 0;i < N;i++)
		for (int j = 0;j <= M;j++)
			if ((ch = getchar()) && ch != '\n')
				board[i][j] = ch - '0';	
	printf("%d\n", bfs());
	return (0);
}