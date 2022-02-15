#include <iostream>
#include <cmath>
using namespace std;

int N, r, c;

int	recur(int x, int y, int size) {
	int total = 0;
	if (x == r && y == c)
		return 0;
	int section[4];

	section[0] = 0;
	section[1] = pow(4, N-1);
	section[2] = pow(4, N-1) * 2;
	section[3] = pow(4, N-1) * 3;
	N--;

	if (x <= r && r < x + size / 2 && y <= c && c < y + size/2)
		return total += section[0] + recur(x, y, size/2);
	else if (x <= r && r < x + size / 2 && y <= c && c < y + size)
		return total += section[1] + recur(x, y+size/2, size/2);
	else if (x <= r && r < x + size && y <= c && c < y + size/2)
		return total += section[2] + recur(x+size/2, y, size/2);
	else
		return total += section[3] + recur(x+size/2, y+size/2, size/2);
}

int	main(void) {
	cin >> N >> r >> c;
	cout << recur(0, 0, (1<<N)) << endl;
	return 0;
}