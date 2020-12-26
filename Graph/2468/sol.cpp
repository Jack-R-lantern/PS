#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;

pair<int, int>	dir[]{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
bool	visit[100][100];
int		N, land;
int		MAX;

bool	safe(int x, int y) {
	return (min(x, y) >= 0 && max(x, y) < N);
}

void	dfs(vector<vector<int>> &v, int &hight, int x, int y) {
	visit[x][y] = true;
	for (int i = 0;i < 4;i++) {
		int nx = x + dir[i].first;
		int ny = y + dir[i].second;
		if (safe(nx, ny) && !visit[nx][ny] && v[nx][ny] > hight)
			dfs(v, hight, nx, ny);
	}
	return ;
}
int		main(void) {
	vector<vector<int>>	v;
	vector<int>			result;

	scanf("%d", &N);
	for (int i = 0;i < N;i++) {
		vector<int>		elm(N);
		v.push_back(elm);
	}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			scanf("%d", &v[i][j]);
			MAX = v[i][j] > MAX ? v[i][j] : MAX;
		}
	for (int hight = 0;hight <= MAX;hight++) {
		for (int i = 0;i < N;i++)
			for (int j = 0;j < N;j++)
				if (v[i][j] > hight && !visit[i][j]) {
					dfs(v, hight, i, j);
					land++;
				}
		memset(visit, 0, sizeof(visit));
		result.push_back(land);
		land = 0;
	}
	sort(result.begin(), result.end(), greater<int>());
	printf("%d\n", result[0]);
	return (0);
}