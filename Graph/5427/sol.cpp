#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <cstring>
using namespace std;

vector<tuple<char, int, int, int>>	v;

char grid[1000][1000];
int T, w, h, total, px, py;
int dx[]{0, 0, 1, -1};
int dy[]{1, -1, 0, 0};

bool range(int x, int y) {
	return (0 <= x && x < h && 0 <= y && y < w);
}

bool bfs() {
	queue<tuple<char, int, int, int>>	q;
	char ch;
	int x, y;

	for (auto info : v)
		q.push(info);
	v.clear();
	while(!q.empty()) {
		tie(ch, x, y, total) = q.front();
		q.pop();

		for (int i=0;i<4;i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (range(nx, ny)) {
				if (ch == '*' && grid[nx][ny] != '*' && grid[nx][ny] != '#') {
					grid[nx][ny] = '*';
					q.push({ch, nx, ny, total});
				}
				else if (ch == '@' && grid[nx][ny] == '.') {
					grid[nx][ny] = '@';
					q.push({ch, nx, ny, total + 1});
				}
			}
			else if (ch == '@'){
				total++;
				return true;
			}
		}
	}
	return false;
}

int	main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;
	while (T--) {
		cin >> w >> h;
		for (int i=0;i<h;i++) {
			for (int j=0;j<w;j++) {
				cin >> grid[i][j];
				if (grid[i][j] == '*')
					v.push_back({'*', i, j, 0});
				else if (grid[i][j] == '@') {
					px = i;
					py = j;
				}
			}
		}
		v.push_back({'@', px, py, 0});
		if(bfs())
			cout << total << '\n';
		else
			cout << "IMPOSSIBLE" << '\n';
	}
	return 0;
}