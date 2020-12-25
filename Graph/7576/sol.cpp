#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

pair<int, int>	dir[4] ={{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
queue<tuple<int, int, int>>	q;
int		board[1000][1000];
int		N, M;
int		cnt;

bool	safe(int x, int y) {
	return (x >= 0 && y >= 0 && x < M && y < N);
}

int	bfs(void) {
	int	x, y, d;

	while (!q.empty()) {
		tie(x, y, d) = q.front();
		q.pop();
		for (int i = 0; i < 4;i++) {
			int	nx = x + dir[i].first;
			int ny = y + dir[i].second;
			if (safe(nx, ny) && !board[nx][ny]) {
				q.push({nx, ny, d + 1});
				board[nx][ny] = d + 1;
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
	int		result;
	
	cin >> N >> M;
	for (int i = 0;i < M;i++)
		for (int j = 0;j < N;j++) {
			cin >> board[i][j];
			if (board[i][j] == 1)
				q.push({i, j, 0});
			else if(!board[i][j])
				cnt++;
		}
	cout << bfs() << '\n';
	return (0);
}