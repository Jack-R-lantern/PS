#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

pair<int, int>	dir[]{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int	M, N, K;

bool	safe(int x, int y) {
	return (min(x, y) >= 0 && x < M && y < N);
}

int		bfs(vector<vector<int>> &v, int x, int y) {
	queue<pair<int, int>>	q;
	int		d = 1;

	q.push({x, y});
	v[x][y] = 1;
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for (int i = 0; i < 4 ; i++) {
			int nx = x + dir[i].first;
			int ny = y + dir[i].second;
			if (safe(nx, ny) && !v[nx][ny]) {
				q.push({nx, ny});
				v[nx][ny] = 1;
				d++;
			}
		}
	}
	return (d);
}

int		main(void) {
	vector<vector<int>>	v;
	vector<int>			result;
	int	lx, ly, rx, ry;

	scanf("%d%d%d", &M, &N, &K);
	for (int i = 0;i < M;i++) {
		vector<int>		elm(N);
		v.push_back(elm);
	}
	while (K--) {
		scanf("%d%d%d%d", &lx, &ly, &rx, &ry);
		for (int i = ly;i < ry; i++)
			for (int j = lx;j < rx; j++)
				v[i][j] = 1;
	}
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			if (!v[i][j])
				result.push_back(bfs(v, i, j));
	sort(result.begin(), result.end());
	printf("%lu\n", result.size());
	for (int i = 0;i<result.size();i++)
		if(i == result.size() - 1)
			printf("%d\n",result[i]);
		else
			printf("%d ", result[i]);
	return (0);
}