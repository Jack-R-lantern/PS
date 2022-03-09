#include <iostream>
using namespace std;

int K;
int	dp[2][46];
int	main(void) {
	cin >> K;
	dp[0][0] = 1;
	dp[1][0] = 0;
	for (int i=1;i<=K;i++) {
		dp[0][i] = dp[1][i-1];
		dp[1][i] = dp[1][i-1] + dp[0][i-1];
	}
	cout << dp[0][K] << " " << dp[1][K] << endl;
	return 0;
}