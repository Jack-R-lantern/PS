#include <iostream>
using namespace std;

bool prime[123456*2 + 1];
int N;

int	main(void) {
	for (int i=2;i<=123456*2 + 1;i++) {
		if (prime[i] == false) {
			for (int j=2;j*i<=123456*2 + 1;j++) {
				prime[j*i] = true;
			}
		}
	}
	while (1) {
		int total = 0;
		cin >> N;
		if (N == 0)
			break;
		for (int i=N+1;i<=2*N;i++) {
			if (prime[i] == false)
				total++;
		}
		cout << total << "\n";
	}
	return 0;
}