#include <iostream>
#include <algorithm>
using namespace std;

long	dp[101][21];
int		N;

int	main(void) {
	cin >> N;
	fill(&dp[0][0], &dp[100][21], 0);
	int temp;
	cin >> temp;
	dp[1][temp] = 1;
	for (int i=2;i<N;i++) {
		cin >> temp;
		for(int j=0;j<=20;j++) {
			if (dp[i-1][j] != 0) {
				int p, m;
				p = j + temp;
				m = j - temp;
				if (0 <= p && p <= 20)
					dp[i][p] += dp[i-1][j];
				if (0 <= m && m <= 20)
					dp[i][m] += dp[i-1][j];
			}
		}
	}
	cin >> temp;
	cout << dp[N-1][temp] << endl;
	return 0;
}