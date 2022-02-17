#include <iostream>
using namespace std;

int		N;
int		dp[10001];

int		find(int idx) {
	if(((dp[idx - 1] + dp[1]) %  2) == 1 || 
	   ((dp[idx - 3] + dp[3]) %  2) == 1 ||
	   ((dp[idx - 4] + dp[4]) %  2) == 1)
	   return 1;
	else
		return 0;
}

int		main(void) {
	cin >> N;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 1;
	dp[4] = 1;
	for (int i=5;i<=N;i++) {
		dp[i] = find(i);
	}

	if (dp[N] == 1)
		cout << "SK" << endl;
	else
		cout << "CY" << endl;
	return 0;
}