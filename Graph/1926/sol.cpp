#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int		board[500][500];
int		dx[]{0, 0, 1, -1};
int		dy[]{1, -1, 0, 0};
int		N, M;

void	init(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
}

bool	safe(int x, int y) {
	return (x >= 0 && y >= 0 && x < N && y < M);
}

int		bfs(int x, int y) {
	queue<tuple<int, int>>	q;
	int		total = 1;

	q.push({x, y});
	board[x][y] = 0;
	while (!q.empty()) {
		tie(x, y) = q.front();
		q.pop();
		for (int i=0;i<4;i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (safe(nx, ny) && board[nx][ny]) {
				q.push({nx, ny});
				board[nx][ny] = 0;
				total++;
			}
		}
	}
	return (total);
}

int		main(void) {
	vector<int>		v;
	init();
	cin >> N >> M;
	for (int i=0;i<N;i++)
		for (int j=0;j<M;j++)
			cin>>board[i][j];
	for (int i=0;i<N;i++)
		for (int j=0;j<M;j++)
			if (board[i][j])
				v.push_back(bfs(i, j));
	sort(v.begin(), v.end(), greater<int>());
	cout << v.size() << '\n';
	if (v.empty())
		cout << "0\n";
	else
		cout << v[0] << '\n';
	return (0);
}