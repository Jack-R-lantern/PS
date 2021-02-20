#include <cstdio>
#include <vector>
using namespace std;

int		main(void) {
	int		N;

	scanf("%d", &N);
	vector<int>		dp(N+1, 0);
	for (int i=1;i<=N;i++) {
		dp[i] = i;
	}
	return (0);
}