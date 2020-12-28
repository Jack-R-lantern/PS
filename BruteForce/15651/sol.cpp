#include <iostream>
using namespace std;

int		N, M;
int		a[7];

void	rpermutation(int depth) {
	if (depth == 0) {
		for (int i=0;i<M;i++)
			cout << a[i] << ' ';
		cout<<'\n';
		return ;
	}
	for (int i=1;i<=N;i++) {
		a[M-depth] = i;
		rpermutation(depth - 1);
	}
}

int		main(void) {
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr);
	cin >> N >> M;
	rpermutation(M);
	return (0);
}