#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int arry[100001];
int	dp[100001];

int		main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N, MAX;
	cin >> N;
	for (int i=1;i<=N;i++) {
		cin >> arry[i];
		dp[i] = arry[i];
	}
	MAX = dp[1];
	for (int i=2;i<=N;i++) {
		dp[i] = max(dp[i], dp[i-1] + arry[i]);
		if (dp[i] > MAX)
			MAX = dp[i];
	}
	cout << MAX << "\n";
	return 0;
}