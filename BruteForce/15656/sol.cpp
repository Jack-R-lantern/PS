#include <algorithm>
#include <iostream>
using namespace std;

int		a[7], r[7];
int		N, M;

void	rpermutation(int depth) {
	if (depth == 0) {
		for (int i=0;i<M;i++)
			cout << r[i] << ' ';
		cout << '\n';
		return ;
	}
	for (int i=0;i<N;i++) {
		r[M-depth] = a[i];
		rpermutation(depth - 1);
	}
}

int		main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin >> N >> M;
	for (int i=0;i<N;i++)
		cin >> a[i];
	std::sort(a, a+N);
	rpermutation(M);
	return (0);
}