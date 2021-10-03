#include <iostream>
#include <algorithm>
using namespace std;

int		N;
int		stair[300];
int		dp[300];
int		main(void) {
	cin >> N;
	for (int i=0;i<N;++i)
		cin >> stair[i];
	dp[0] = stair[0];
	dp[1] = stair[0] + stair[1];
	dp[2] = max(stair[0] + stair[2], stair[1] + stair[2]);

	for (int i=3;i<N;i++) {
		dp[i] = max(dp[i-2]+stair[i], dp[i-3] + stair[i-1] + stair[i]);
	}
	cout << dp[N-1] << endl;
	return (0);
}

/*
N = 1
1

N = 2
1 1
0 1

N = 3
1  0 1
0  1 1

N = 4
1 1  0 1
0 1  0 1
1 0  1 1

N = 5
1 0 1  0 1
0 1 1  0 1
1 1 0  1 1
*/