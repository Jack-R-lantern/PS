#include<iostream>
using namespace std;

int N, white, blue;
int grid[128][128];

void recur(int x, int y, int size) {
	bool check = grid[x][y];
	bool flag = true;

	for (int i=x;i<x+size;i++) {
		for (int j=y;j<y+size;j++) {
			if (check && grid[i][j] == 0)
				flag = false;
			else if (!check && grid[i][j] == 1)
				flag = false;
			if (!flag) {
				recur(x, y, size / 2);
				recur(x, y + size / 2, size / 2);
				recur(x + size / 2, y, size / 2);
				recur(x + size / 2, y + size / 2, size / 2);
				return;
			}
		}
	}
	if (check)
		blue++;
	else
		white++;
}

int	main(void) {
	cin >> N;
	for (int i=0;i<N;i++) {
		for (int j=0;j<N;j++) {
			cin >> grid[i][j];
		}
	}
	recur(0, 0, N);
	cout << white << endl;
	cout << blue << endl;
	return 0;
}