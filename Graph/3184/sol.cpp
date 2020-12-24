#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
using namespace std;

int		dx[]{0, 0, 1, -1};
int		dy[]{1, -1, 0, 0};
int		R, C;
int		sheep, wolf;

bool	safe(int x, int y) {
	return (x >= 0 && y >= 0 && x < R && y < C);
}

void	bfs(vector<vector<char>> &v, int x, int y) {
	queue<tuple<int, int, char>>	q;
	char	d;
	int		curs = 0,  curw = 0;
	int		nx, ny;

	q.push({x, y, v[x][y]});
	v[x][y] = '#';
	while (!q.empty()) {
		tie(nx, ny, d) = q.front();
		q.pop();
		if (d == 'o')
			curs++;
		else if (d == 'v')
			curw++;
		for (int dir = 0;dir < 4;dir++) {
			int r = nx + dx[dir];
			int c = ny + dy[dir];
			if (safe(r, c) && (v[r][c] != '#')) {
				q.push({r, c, v[r][c]});
				v[r][c] = '#';
			}
		}
	}
	if (curs > curw)
		sheep += curs;
	else
		wolf += curw;
}

int		main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> R >> C;
	vector<vector<char>>	v;
	for (int i = 0;i < R;i++) {
		vector<char>	elm(C);
		v.push_back(elm);
	}
	for (int i = 0;i < R;i++)
		for (int j = 0; j < C;j++)
			cin >> v[i][j];
	for (int i = 0;i < R;i++)
		for (int j = 0; j < C;j++)
			if (v[i][j] == 'o' || v[i][j] == 'v')
				bfs(v, i, j);
	cout << sheep << ' ' << wolf << '\n';
	return (0);
}