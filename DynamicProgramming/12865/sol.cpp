#include <iostream>
#include <algorithm>
using namespace std;

int	weight[101];
int value[101];
int	dp[101][100001];

int		main(void) {
	int N, W;
	
	cin >> N >> W;
	for (int i=1;i<=N;i++) {
		cin >> weight[i] >> value[i];
	}
	for (int i=1;i<=N;i++) {
		for (int j=1;j<=W;j++) {
			if (j - weight[i] >= 0) {
				dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight[i]] + value[i]);
			}
			else {
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	cout << dp[N][W] << endl;
	return 0;
}