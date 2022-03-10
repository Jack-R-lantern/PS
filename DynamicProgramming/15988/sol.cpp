#include <iostream>
using namespace std;

int T, MAX;
unsigned long dp[1000001];

int	main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> T;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	MAX = 4;
	while (T--) {
		int input;
		cin >> input;
		for (int i=MAX;i<=input;i++)
			dp[i] = (dp[i-1] + dp[i-2] + dp[i-3]) % 1000000009;
		cout << dp[input] << "\n";
		if (input > MAX)
			MAX = input;
	}
	return 0;
}