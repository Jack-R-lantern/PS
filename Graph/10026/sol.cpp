#include <cstdio>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

pair<int, int>	dir[]{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int		N;

bool	safe(int x, int y) {
	return (x >= 0 && y >= 0 && x < N && y < N);
}

void	o_bfs(vector<vector<pair<char, char>>> &v, int x, int y) {
	queue<tuple<int, int, char>>	q;
	char	c;

	q.push({x, y, v[x][y].first});
	v[x][y].first = 0;
	while (!q.empty()) {
		tie(x, y, c) = q.front();
		q.pop();
		for (int i = 0;i<4;i++) {
			int	nx = x + dir[i].first;
			int	ny = y + dir[i].second;
			if (safe(nx, ny) && v[nx][ny].first == c) {
				q.push({nx, ny, c});
				v[nx][ny].first = 0;
			}
		}
	}
}

void	w_bfs(vector<vector<pair<char, char>>> &v, int x, int y) {
	queue<tuple<int, int, char>>	q;
	char	c;

	q.push({x, y, v[x][y].second});
	v[x][y].second = 0;
	while (!q.empty()) {
		tie(x, y, c) = q.front();
		q.pop();
		for (int i = 0;i<4;i++) {
			int	nx = x + dir[i].first;
			int	ny = y + dir[i].second;
			if (safe(nx, ny) && v[nx][ny].second == c) {
				q.push({nx, ny, c});
				v[nx][ny].second = 0;
			}
		}
	}
}

int		main(void) {
	vector<vector<pair<char, char>>>	v;
	int	o = 0, w = 0;

	scanf("%d", &N);
	for (int i=0;i<N;i++) {
		vector<pair<char, char>>	elm(N);
		v.push_back(elm);
	}
	for (int i=0;i<N;i++)
		for (int j=0;j<N;j++) {
			scanf(" %c", &v[i][j].first);
			if (v[i][j].first == 'G')
				v[i][j].second = 'R';
			else
				v[i][j].second = v[i][j].first;
		}
	for (int i=0;i<N;i++)
		for (int j=0;j<N;j++)
			if (v[i][j].first) {
				o_bfs(v, i, j);
				o++;
			}
	for (int i=0;i<N;i++)
		for (int j=0;j<N;j++)
			if (v[i][j].second) {
				w_bfs(v, i, j);
				w++;
			}
	printf("%d %d\n", o, w);
	return (0);
}