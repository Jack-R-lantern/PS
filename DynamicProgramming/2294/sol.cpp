#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
int dp[100001];
int	coin[101];

int		main(void) {
	cin >> n >> k;
	dp[0] = 0;
	fill(dp+1, dp+100001, 100001);
	for (int i=1;i<=n;i++) {
		cin >> coin[i];

		for (int j=coin[i];j<=k;j++) {
			dp[j] = min(dp[j], dp[j - coin[i]] + 1);
		}
	}

	if (dp[k] == 100001)
		cout << "-1" << endl;
	else
		cout << dp[k] << endl;
	return 0;
}