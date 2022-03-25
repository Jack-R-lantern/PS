#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef vector<vector<long long>>	matrix;
matrix v, r;
long long B;
int N;

matrix operator*(const matrix &a, const matrix &b) {
	matrix res = matrix(N, vector<long long>(N));
	for (int i=0;i<N;i++) {
		for (int j=0;j<N;j++) {
			for (int k=0;k<N;k++)
				res[i][j] += a[i][k] * b[k][j];
			res[i][j] %= 1000;
		}
	}
	return res;
}

int	main(void) {
	cin >> N >> B;

	v = matrix(N, vector<long long>(N));
	r = matrix(N, vector<long long>(N));
	for (int i=0;i<N*N;i++)
		cin >> v[i/N][i%N];
	for (int i=0;i<N;i++)
		r[i][i] = 1;
	while (B > 0) {
		if (B % 2 == 1) {
			r = r * v;
		}
		B /= 2;
		v = v * v;
	}
	for (int i=0;i<N;i++) {
		for (int j=0;j<N;j++) {
			cout << r[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}