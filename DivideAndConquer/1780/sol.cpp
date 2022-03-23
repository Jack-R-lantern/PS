#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>>	v;
int N, no, z, po;

void recur(int x, int y, int size) {
	int check = v[x][y];

	for (int i=x;i<x+size;i++) {
		for (int j=y;j<y+size;j++) {
			if (check != v[i][j]) {
				int next_size = size/3;
				for (int idx=0;idx<3;idx++) {
					for (int idy=0;idy<3;idy++) {
						recur(x + idx * next_size, y + idy * next_size, next_size);
					}
				}
				return;
			}
		}
	}
	if (check == -1)
		no++;
	else if (check == 1)
		po++;
	else
		z++;
}

int	main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	v = vector<vector<int>>(N, vector<int>(N));

	for (int i=0;i<N;i++) {
		for (int j=0;j<N;j++) {
			cin >> v[i][j];
		}
	}
	recur(0, 0, N);
	cout << no << "\n" << z << "\n" << po << endl;
	return 0;
}