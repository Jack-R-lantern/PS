#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

bool visited[100][100];
int	grid[100][100];
int expose[100][100];
int dx[]{0, 0, 1, -1};
int dy[]{1, -1, 0, 0};
int	N, M, t;

bool range(int x, int y) {
	return (0 <= x && x < N && 0 <= y && y < M);
}

bool bfs() {
	queue<pair<int, int>>	q;
	int cnt = 0;

	visited[0][0] = true;
	q.push({0, 0});
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i=0;i<4;i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (range(nx, ny) && !visited[nx][ny]) {
				if (grid[nx][ny] == 0) {
					q.push({nx, ny});
					visited[nx][ny] = true;
				}
				else {
					expose[nx][ny]++;
					if (expose[nx][ny] >= 2) {
						grid[nx][ny] = 0;
						visited[nx][ny] = true;
						cnt++;
					}
				}
			}
		}
	}
	if (cnt == 0)
		return true;
	else
		return false;
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
		memset(expose, 0, sizeof(expose));
	}
	cout << t << endl;
	return 0;
}