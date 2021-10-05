#include <iostream>
#include <cmath>
using namespace std;

bool	prime[1000001];

int		main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	prime[0] = 1;
	prime[1] = 1;

	int		M, N;
	cin >> M >> N;
	for (int i=2;i<=N;++i) {
		if (prime[i] == 0) {
			if (i >= M)
				cout << i << '\n';
			for (int j=2;i*j<=N;++j)
				prime[i * j] = 1;
		}
	}
	return (0);
}