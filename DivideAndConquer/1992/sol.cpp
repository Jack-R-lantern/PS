#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string>	v;
int N;

void recur(int x, int y, int size) {
	int check;
	check = v[x][y] - '0';
	for (int i=x;i<x+size;i++) {
		for (int j=y;j<y+size;j++) {
			if (check != v[i][j] - '0') {
				check = -1;
				cout << '(';
				recur(x, y, size/2);
				recur(x, y + size/2, size/2);
				recur(x + size/2, y, size/2);
				recur(x + size/2, y + size/2, size/2);
				cout << ')';
				return;
			}
		}
	}
	if (check != -1)
		cout << check;
}

int	main(void) {
	cin >> N;
	v = vector<string>(N);
	for (int i=0;i<N;i++) {
		cin >> v[i];
	}
	recur(0, 0, N);
	return 0;
}