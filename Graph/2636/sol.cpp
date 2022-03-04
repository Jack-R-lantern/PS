#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

bool visited[100][100];
int grid[100][100];
int N, M, t, c;
int dx[]{0, 0, 1, -1};
int dy[]{1, -1, 0, 0};

bool range(int x, int y) {
	return (0 <= x && x < N && 0 <= y && y < M);
}

bool bfs() {
	queue<pair<int, int>>	q;
	int cnt = 0;

	visited[0][0] = true;
	q.push({0,0});
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i=0;i<4;i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (range(nx, ny) && !visited[nx][ny]) {
				if (grid[nx][ny] == 0)
					q.push({nx, ny});
				else {
					grid[nx][ny] = 0;
					cnt++;
				}
				visited[nx][ny] = true;
			}

		}
	}
	if (cnt == 0) {
		cout << t << '\n' << c << endl;
		return true;
	}
	else {
		c  = cnt;
		return false;
	}
}

int	main(void) {
	cin >> N >> M;
	for (int i=0;i<N;i++)
		for (int j=0;j<M;j++)
			cin >> grid[i][j];
	while (true) {
		if (bfs())
			break;
		t++;
		memset(visited, false, sizeof(visited));
	}
	return 0;
}