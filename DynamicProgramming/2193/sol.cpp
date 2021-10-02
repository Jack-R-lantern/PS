#include <iostream>
using namespace std;

long	dp[90];

int		main(void) {
	int N;
	cin >> N;
	if (N == 1 || N == 2) {
		cout << 1 << endl;
		return (0);
	}
	dp[0] = 1;
	dp[1] = 1;
	for (int i=2;i<N;++i)
		dp[i] = dp[i-1] + dp[i-2];
	cout << dp[N-1] << endl;
	return (0);
}