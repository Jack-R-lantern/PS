#include <iostream>
#include <cstring>
#include <queue>
#include <tuple>
using namespace std;

bool visited[50][50];
char grid[50][50];
int X, Y, MAX;
int dx[]{0, 0, 1, -1};
int dy[]{1, -1, 0, 0};

bool range(int x, int y) {
	return (0 <= x && x < X && 0 <= y && y <= Y);
}

void bfs(int x, int y) {
	queue<tuple<int, int, int>>	q;
	int temp = 0;

	visited[x][y] = true;
	q.push({0, x, y});

	while (!q.empty()) {
		tie(temp, x, y) = q.front();
		q.pop();
		for (int i=0;i<4;i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (range(nx, ny) && !visited[nx][ny] && grid[nx][ny] == 'L') {
				visited[nx][ny] = true;
				q.push({temp+1, nx, ny});
			}
		}
	}
	MAX = temp > MAX ? temp : MAX;
}

int	main(void) {
	cin >> X >> Y;
	for (int i=0;i<X;i++) {
		for (int j=0;j<Y;j++) {
			cin >> grid[i][j];
		}
	}
	for (int i=0;i<X;i++) {
		for (int j=0;j<Y;j++) {
			if (grid[i][j] == 'L') {
				bfs(i, j);
				memset(visited, false, sizeof(visited));
			}
		}
	}
	cout << MAX << endl;
	return 0;
}