#include <iostream>
using namespace std;

unsigned long	dp[1000000];

int		main(void) {
	int		N;
	cin >> N;
	dp[0] = 1;
	dp[1] = 2;
	for (int i=2;i<1000000;++i)
		dp[i] = (dp[i-1] + dp[i-2]) % 15746;
	cout << dp[N-1] << endl;
	return (0);
}

/*
N = 1
1

N = 2
11
00

N = 3
끝에 1을 붙일수 있는 경우 N = 2
111
001
끝에 0을 붙일수 있는 경우 N = 1
100

N = 4
끝에 1을 붙일수 있는 경우 N = 3
0011
1001
1111
끝에 0을 붙일수 있는 경우 N = 2
0000
1100

N = 5
끝에 1을 붙일수 있는 경우 N = 4
11111
10011
00111
00001
끝에 00을 붙일수 있는 경우 N = 3
10000
00100
11100

*/