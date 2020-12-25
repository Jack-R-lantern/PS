#include <algorithm>
#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

vector<int>	v(1);
int		N, M, K;
int		dx[]{0, 0, 1, -1};
int		dy[]{1, -1, 0, 0};

bool	safe(int x, int y) {
	return (min(x, y) >= 0 && x < N && y < M);
}

int		bfs(vector<vector<int>> &adj, int x, int y) {
	queue<pair<int, int>>	q;
	int 	total = 1;
	int		nx, ny;

	q.push({x, y});
	adj[x][y] = 0;
	while (!q.empty()) {
		nx = q.front().first;
		ny = q.front().second;
		q.pop();
		for (int dir = 0;dir < 4;dir++) {
			int	kx = nx + dx[dir];
			int ky = ny + dy[dir];
			if (safe(kx, ky) && adj[kx][ky]) {
				q.push({kx, ky});
				adj[kx][ky] = 0;
				total++;
			}
		}
	}
	return (total);
}

int		main(void) {
	vector<vector<int>>	adj;
	int	f, s;

	scanf("%d%d%d", &N, &M, &K);
	for(int i = 0;i < N;i++) {
		vector<int>		elm(M);
		adj.push_back(elm);
	}
	while (K--) {
		scanf("%d%d", &f, &s);
		adj[f - 1][s - 1] = 1;
	}
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (adj[i][j])
				v.push_back(bfs(adj, i, j));
	sort(v.begin(), v.end(), greater<int>());
	printf("%d\n", v[0]);
	return (0);
}