#include <iostream>
using namespace std;

long	recur(int N) {
	if (N == 0)
		return (1);
	return (N * recur(N-1));
}

int		main(void) {
	int		N;
	long	result;

	cin >> N;
	cout << recur(N) << endl;
	return (0);
}