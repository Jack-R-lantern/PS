#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int>	dp[501];
int N;

int	main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	for (int i=1;i<=N;i++) {
		for (int j=1;j<=i;j++) {
			int input;
			cin >> input;
			dp[i].push_back(input);
		}
	}

	for (int i=N;i>=2;i--) {
		for (int j=0;j<dp[i].size()-1;j++) {
			dp[i-1][j] = max(dp[i-1][j] + dp[i][j], dp[i-1][j] + dp[i][j+1]);
		}
	}
	cout << dp[1][0] << endl;
	return 0;
}