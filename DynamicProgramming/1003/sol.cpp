#include <iostream>
#include <vector>
using namespace std;

vector<pair<long, long>>	dp(41);

int		main(void) {
	int		T;
	dp[0] = make_pair(1, 0);
	dp[1] = make_pair(0, 1);
	for (int i=2;i<dp.size();++i) {
		dp[i] = make_pair(dp[i-1].first + dp[i-2].first, dp[i-1].second + dp[i-2].second);
	}
	cin >> T;
	while (T--) {
		int	N;
		cin >> N;
		cout << dp[N].first << " " << dp[N].second << endl;
	}
	return (0);
}

/*
N = 0
0
zero = 1, one = 0;

N = 1;
1
zero = 0, one = 1;

N = 2;
1, 0
zero = 1, one = 1;

N = 3;
2, 1
1, 0, 1
zero = 1, one = 2;

N = 4;
zero = 2, one = 3;

N = 5;
4, 3
3, 2, 2, 1
2, 1, 1, 0, 1, 0, 1
1, 0, 1, 1, 0, 1, 0, 1
zero = 3, one = 5;
*/