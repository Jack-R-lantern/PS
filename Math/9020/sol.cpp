#include <iostream>
using namespace std;

#define MAX	10000 + 1
bool prime[MAX];
int	T;

int	main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> T;
	for (int i=2;i<MAX;i++) {
		if (prime[i] == false) {
			for (int j=2;i*j<MAX;j++)
				prime[i*j] = true;
		}
	}
	while (T--) {
		int N, left, right;
		cin >> N;
		left = right = N/2;
		for (;left>=2;left--,right++) {
			if (prime[left] == false && (prime[left] == prime[right])) {
				cout << left << " " << right << "\n";
				break;
			}
		}
	}
	return 0;
}