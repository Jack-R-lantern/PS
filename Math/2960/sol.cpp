#include <iostream>
#include <vector>
using namespace std;

vector<bool>	prime;
int N, K;

int	main(void) {
	cin >> N >> K;

	prime = vector<bool>(N+1, false);
	for (int i=2;i<=N;++i) {
		for (int j=1;i*j<=N;++j) {
			if (prime[i*j] == false) {
				prime[i * j] = true;
				K--;
				if (K == 0) {
					cout << i*j << endl;
					return 0;
				}
			}
		}
	}
	return 0;
}