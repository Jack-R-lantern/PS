#include <iostream>
#include <vector>
using namespace std;

int M, N;

int	dp[500][500];
int	grid[500][500];
int dx[]{0, 0, 1, -1};
int dy[]{1, -1, 0, 0};

bool range(int row, int col) {
	return (row >= 0 && row < M && col >= 0 && col < N);
}

int dfs(int x, int y) {
	if (x == M - 1 && y == N - 1)
		return 1;
	if (dp[x][y] != -1)
		return dp[x][y];
	dp[x][y] = 0;
	for (int i=0;i<4;i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (range(nx, ny)) {
			if (grid[nx][ny] < grid[x][y])
				dp[x][y] += dfs(nx, ny);
		}
	}
	return dp[x][y];
}

int	main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> M >> N;
	for (int i=0;i<M;i++)
		for (int j=0;j<N;j++) {
			cin >> grid[i][j];
			dp[i][j] = -1;
		}

	cout << dfs(0, 0) << endl;
}