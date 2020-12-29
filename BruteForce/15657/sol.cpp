#include <algorithm>
#include <iostream>
using namespace std;

int		a[8], r[8];
int		N, M;

void	monoinc(int s, int depth) {
	if (depth == 0) {
		for (int i=0;i<M;i++)
			cout << r[i] << ' ';
		cout << '\n';
		return ;
	}
	for (int i=s;i<N;i++) {
		r[M-depth] = a[i];
		monoinc(i, depth - 1); 
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
	monoinc(0, M);
	return (0);
}
