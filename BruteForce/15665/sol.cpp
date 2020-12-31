#include <algorithm>
#include <iostream>
using namespace std;

bool	b[7];
int		a[7], r[8];
int		N, M;

void	sol(int depth) {
	if (depth == 0) {
		for (int i=0;i<M;i++)
			cout << r[i] << ' ';
		cout << '\n';
		return ;
	}
	for (int i=0;i<N;i++) {
		if (r[M-depth] == a[i]) continue;
		r[M-depth] = a[i];
		sol(depth - 1);
		r[M- depth + 1] = 0;
	}
}

int		main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;
	for (int i=0;i<N;i++)
		cin >> a[i];
	sort(a, a+N);
	sol(M);
	return (0);
}