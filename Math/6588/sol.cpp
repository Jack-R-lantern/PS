#include <iostream>
using namespace std;

#define MAX	1000000 + 1

bool prime[MAX];

int	main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	for (int i=2;i<MAX;i++) {
		if (prime[i] == false) {
			for (int j=2;j*i<MAX;j++)
				prime[i*j] = true;
		}
	}

	int N;
	while (1) {
		cin >> N;
		if (N == 0)
			break;
		for (int i=3;i<MAX;i++) {
			if (prime[i] == 0 && prime[N-i] == 0) {
				cout << N << " = " << i << " + " << N-i << "\n";
				break;
			}
		}
	}
	return 0;
}