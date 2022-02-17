#include <iostream>
using namespace std;

unsigned long dp[1001];

int		main(void) {
	int N;
	dp[1] = 1;
	dp[2] = 3;
	cin >> N;
	for (int i=3;i<=N;i++)
		dp[i] = (dp[i-1] + 2 * dp[i-2]) % 10007;
	cout << dp[N] << endl;
	return 0;
}