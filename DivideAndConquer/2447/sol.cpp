#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

vector<vector<char>>	v;

void recur(int n, int x, int y) {
	if (n == 1) {
		v[x][y] = '*';
		return;
	}
	else {
		n = n/3;
		for (int i=0;i<=2;i++) {
			for (int j=0;j<=2;j++) {
				if (i == 1 && j == 1)
					continue;
				recur(n, x + (i * n), y + (j * n));
			}
		}
	}
}

int	main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int N;

	cin >> N;
	v = vector<vector<char>>(N, vector<char>(N, ' '));

	recur(N, 0, 0);

	for (int i=0;i<N;i++) {
		for (int j=0;j<N;j++)
			cout << v[i][j];
		cout << '\n';
	}

	return 0;
}