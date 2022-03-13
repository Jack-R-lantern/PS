#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
#include <cstring>
#include <cmath>
using namespace std;

bool visited[50][50];
bool flag;
int	grid[50][50];
int N, L, R, total;
int dx[]{0, 0, 1, -1};
int dy[]{1, -1, 0, 0};

bool range(int x, int y) {
	return (0 <= x && x < N && 0 <= y && y < N);
}

bool diff(int a, int b) {
	return (L <= abs(a-b) && abs(a-b) <= R);
}

void bfs(int x, int y) {
	queue<tuple<int, int, int>>	q;
	vector<pair<int, int>>		v;
	int cnt = 0, p = 0, temp;

	q.push({grid[x][y], x, y});
	visited[x][y] = true;
	while (!q.empty()) {
		tie(temp, x, y) = q.front();
		q.pop();
		v.push_back({x, y});
		p += temp;
		cnt++;

		for (int i=0;i<4;i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (range(nx, ny) && !visited[nx][ny] && diff(grid[x][y], grid[nx][ny])) {
				visited[nx][ny] = true;
				q.push({grid[nx][ny], nx, ny});
			}
		}
	}
	if (cnt != 1) {
		flag = true;
		p /= cnt;
		for (auto pr : v)
			grid[pr.first][pr.second] = p;
	}
}

int	main(void) {
	cin >> N >> L >> R;
	for (int i=0;i<N;i++)
		for (int j=0;j<N;j++)
			cin >> grid[i][j];
	
	while (true) {
		flag = false;
		for (int i=0;i<N;i++) {
			for (int j=0;j<N;j++) {
				if (!visited[i][j])
					bfs(i, j);
			}
		}
		if (flag == false)
			break;
		memset(visited, false, sizeof(visited));
		total++;
	}
	cout << total << endl;
	return 0;
}