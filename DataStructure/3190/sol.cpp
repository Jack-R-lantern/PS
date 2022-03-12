#include <iostream>
#include <deque>
using namespace std;

deque<pair<int, int>>	dq;
char grid[100][100];
char ra[10001];
int N, K, L, total, dir = 0;
int dx[]{0, 1, 0, -1};
int dy[]{1, 0, -1, 0};

bool range(int x, int y) {
	return (0 <= x && x < N && 0 <= y && y < N);
}

void solve(int x, int y) {
	dq.push_back({x, y});
	grid[x][y] = 1;

	while(true) {
		x = dq.front().first;
		y = dq.front().second;
		
		int nx = x + dx[dir];
		int ny = y + dy[dir];

		total++;
		if (!range(nx, ny) || grid[nx][ny] == 1)
			break;
		dq.push_front({nx, ny});
		if (grid[nx][ny] != 'A') {
			x = dq.back().first;
			y = dq.back().second;
			grid[x][y] = 0;
			dq.pop_back();
		}
		grid[nx][ny] = 1;
		if (ra[total] == 'D') {
			dir++;
			dir %= 4;
		}
		else if (ra[total] == 'L') {
			dir--;
			dir = (4 + dir) % 4;
		}
	}
}

int	main(void) {
	cin >> N;
	cin >> K;
	for (int i=0;i<K;i++) {
		int x, y;
		cin >> x >> y;
		grid[x-1][y-1] = 'A';
	}
	cin >> L;
	for (int i=0;i<L;i++) {
		char d;
		int t;
		cin >> t >> d;
		ra[t] = d;
	}
	solve(0, 0);
	cout << total << endl;
	return 0;
}