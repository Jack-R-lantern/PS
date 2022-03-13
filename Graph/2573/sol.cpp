#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

bool visited[300][300];
int grid[300][300];
int N, M, total;
int dx[]{0, 0, 1, -1};
int dy[]{1, -1, 0, 0};

bool range(int x, int y) {
	return (0 <= x && x < N && 0 <= y && y < M);
}

void bfs(int x, int y) {
	queue<pair<int, int>>	q;

	visited[x][y] = true;
	q.push({x,y});
	while(!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i=0;i<4;i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (range(nx, ny) && !visited[nx][ny]) {
				if (grid[nx][ny] != 0) {
					visited[nx][ny] = true;
					q.push({nx, ny});
				}
				else {
					if (grid[x][y] > 0)
						grid[x][y]--;
				}
			}
		}
	}
}

int	main(void) {
	int iceberg = 0;
	cin >> N >> M;
	for (int i=0;i<N;i++)
		for (int j=0;j<M;j++)
			cin >> grid[i][j];
	
	while (true) {
		iceberg = 0;
		for (int i=0;i<N;i++) {
			for (int j=0;j<M;j++) {
				if (!visited[i][j] && grid[i][j] != 0) {
					bfs(i, j);
					iceberg++;
				}
			}
		}
		if (iceberg >= 2 || iceberg == 0)
			break;
		total++;
		memset(visited, false, sizeof(visited));
	}
	total = iceberg >= 2 ? total : 0;
	cout << total << endl;
	return 0;
}