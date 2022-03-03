#include <iostream>
using namespace std;

int	main(void) {
	int T;
	cin >> T;
	while (T--) {
		int N, M;
		cin >> N >> M;
		unsigned long ans = 1;

		int r = 1;
		for (int i=M;i>M-N;i--) {
			ans *= i;
			ans /= r++;
		}
		cout << ans << '\n';
	}	
	return 0;
}