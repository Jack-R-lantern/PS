#include <iostream>
#include <vector>
using namespace std;

int		main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int		N, M;
	cin >> N >> M;
	vector<int>	v(N);
	for (int i=0;i<N;++i)
		cin >> v[i];
	for (int i=0;i<N;++i) {
		if (v[i] < M)
			cout << v[i] << ' ';
	}
	cout << endl;
	return (0);
}