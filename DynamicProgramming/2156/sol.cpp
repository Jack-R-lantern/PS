#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 10000 + 1

int arr[MAX];
int dp[MAX];

int N;

int	main(void) {
	cin >> N;
	for (int i=1;i<=N;i++)
		cin >> arr[i];
	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];
	for (int i=3;i<=N;i++) {
		dp[i] = max(dp[i-3] + arr[i-1] + arr[i], max(dp[i-2] + arr[i], dp[i-1]));
	}
	cout << dp[N] << endl;
	return 0;
}