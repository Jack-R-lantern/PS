#include <iostream>
#include <algorithm>
using namespace std;

int	dp[5001];

int		main(void) {
	int N;

	cin >> N;
	dp[1] = -1;
	dp[2] = -1;
	dp[3] = 1;
	dp[4] = -1;
	dp[5] = 1;
	for (int i=6;i<=N;i++) {
		if (dp[i-3] == -1 && dp[i-5] == -1)
			dp[i] = -1;
		else if (dp[i-3] == -1)
			dp[i] = dp[i-5] + 1;
		else if (dp[i-5] == -1)
			dp[i] = dp[i-3] + 1;
		else
			dp[i] = min(dp[i-3] + 1, dp[i-5] + 1);

	}
	cout << dp[N] << endl;
}