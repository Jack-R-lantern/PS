#include <iostream>
#include <vector>
using namespace std;

int N, M;

int	main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;
	vector<int>	v(N+1);
	for (int i=1;i<N+1;i++) {
		cin >> v[i];
		v[i] += v[i-1];
	}
	while (M--) {
		int i, j;
		cin >> i >> j;
		cout << v[j] - v[i-1] << "\n";
	}
	return 0;
}