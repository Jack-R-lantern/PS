#include <iostream>
using namespace std;

int		dp[11];
int		N, K;

int		main(void) {
	cin >> N >> K;
	dp[0] = 1;
	for (int i=1;i<11;++i)
		dp[i] = i * dp[i-1];
	cout << dp[N] / (dp[K] * dp[N-K]) << endl;
	return (0);
}