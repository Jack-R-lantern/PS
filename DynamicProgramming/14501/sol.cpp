#include <iostream>
#include <algorithm>
using namespace std;

int	dp[17];
int	t[16];
int	v[16];

int	main(void) {
	int N;
	cin >> N;

	for (int i=1;i<=N;i++)
		cin >> t[i] >> v[i];
	for (int i=N;i>0;i--) {
		if (t[i] > N - i + 1)
			dp[i] = dp[i+1];
		else
			dp[i] = max(dp[i+1], dp[i+t[i]] + v[i]);
	}
	cout << dp[1] << endl;
	return 0;
}