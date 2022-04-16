#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>>	grid, dp;
int N, M;

int	main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;
	grid = vector<vector<int>>(N+1, vector<int>(N+1, 0));
	dp = vector<vector<int>>(N+1, vector<int>(N+1, 0));

	for (int i=1;i<=N;i++) {
		for (int j=1;j<=N;j++) {
			cin >> grid[i][j];
			dp[i][j] = dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + grid[i][j];
		}
	}

	while (M--) {
		int x1, x2, y1, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << dp[x2][y2] - dp[x2][y1-1] - dp[x1-1][y2] + dp[x1-1][y1-1] << '\n';
	}
	return 0;
}