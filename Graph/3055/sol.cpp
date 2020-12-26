#include <cstdio>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

queue<tuple<int, int, int, char>>	q;
pair<int, int>	s, t;
pair<int, int>	dir[]{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
bool	flag;
int		R, C;
int		cnt;

bool	safe(int x, int y) {
	return (x >= 0 && y >= 0 && x < R && y < C);
}

void	bfs(vector<vector<char>> &v) {
	char	c;
	int		x, y, d;

	while (!q.empty()) {
		tie(x, y, d, c) = q.front();
		q.pop();
		if (c == 'S' && x == t.first && y == t.second) {
			flag = true;
			cnt = d;
			return;
		}
		for(int i = 0;i<4;i++) {
			int nx = x + dir[i].first;
			int ny = y + dir[i].second;
			if (safe(nx, ny) && v[nx][ny] != '*') {
				if (c == '*' && v[nx][ny] != 'X' && v[nx][ny] != 'D') {
					q.push({nx, ny, d + 1, c});
					v[nx][ny] = '*';
				}
				else if (c == 'S' && v[nx][ny] != 'X' && v[nx][ny] != '*') {
					q.push({nx, ny, d + 1, c});
					v[nx][ny] = '*';
				}
			}
		}
	}
}

int		main(void) {
	vector<vector<char>>	v;
	
	scanf("%d%d", &R, &C);
	for (int i = 0;i < R;i++) {
		vector<char>	elm(C);
		v.push_back(elm);
	}
	for(int i = 0;i < R;i++) {
		for(int j = 0;j < C;j++) {
			scanf(" %c", &v[i][j]);
			if (v[i][j] == 'S') {
				s.first = i;
				s.second = j;
			}
			else if (v[i][j] == 'D') {
				t.first = i;
				t.second = j;
			}
			else if (v[i][j] == '*')
				q.push({i, j, 0,'*'});
		}
	}
	q.push({s.first, s.second, 0, 'S'});
	bfs(v);
	if (flag)
		printf("%d\n", cnt);
	else
		printf("%s\n", "KAKTUS");
	return (0);
}