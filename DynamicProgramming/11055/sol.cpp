#include <iostream>
using namespace std;

int N, MAX;
int A[1001];
int dp[1001];

int	main(void) {
	cin >> N;
	for (int i=1;i<=N;i++)
		cin >> A[i];
	for (int i=1;i<=N;i++) {
		dp[i] = A[i];
		for (int j=1;j<i;j++) {
			if (A[i] > A[j] && dp[i] < dp[j] + A[i]) {
				dp[i] = dp[j] + A[i];
			}
		}
		if (MAX < dp[i])
			MAX = dp[i];
	}
	cout << MAX << endl;
	return 0;
}