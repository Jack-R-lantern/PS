#include <iostream>
using namespace std;

int		recur(int N) {
	if (N == 0)
		return (0);
	if (N == 1)
		return (1);
	return recur(N-1) + recur(N-2);
}

int		main(void) {
	int		N;

	cin >> N;
	cout << recur(N) << endl;
	return (0);
}