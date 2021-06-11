#include <iostream>
#include <algorithm>
using namespace std;

int		main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int		N, M;
	cin >> N;

	int		a[N];
	for(int i=0;i<N;i++)
		cin >> a[i];
	sort(a, a+N);
	cin >> M;
	int		b[M];
	for(int i=0;i<M;i++)
		cin >> b[i];
	for(int i=0;i<M;i++) {
		if (binary_search(a, a+N, b[i]))
			cout << 1 << '\n';
		else
			cout << 0 << '\n';
	}
}