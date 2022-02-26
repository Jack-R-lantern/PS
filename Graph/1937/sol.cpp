#include <iostream>
using namespace std;

int	N, result;
int	grid[500][500];
int dp[500][500];
int dx[]{0, 0, 1, -1};
int dy[]{1, -1, 0, 0};

bool range(int x, int y) {
	return (x >= 0 && x < N && y >= 0 && y < N);
}

void	dfs(int x, int y) {
	int MAX = 0;
	
	for (size_t i=0;i<4;i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (range(nx, ny) && grid[x][y] < grid[nx][ny]) {
			if (!dp[nx][ny])
				dfs(nx, ny);
			MAX = MAX < dp[nx][ny] ? dp[nx][ny] : MAX;
		}
	}
	dp[x][y] = MAX;
	dp[x][y]++;
	result = result < dp[x][y] ? dp[x][y] : result;
}

int		main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N;

	for (int i=0;i<N*N;i++)
		cin >> grid[i/N][i%N];
	for (int i=0;i<N*N;i++) {
		if (!dp[i/N][i%N])
			dfs(i/N, i%N);
	}
	cout << result << endl;
	return 0;
}