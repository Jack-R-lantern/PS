#include <iostream>
using namespace std;

int		main(void) {
	int	total = 0, N;
	for (int i=0;i<5;++i) {
		cin >> N;
		total += N * N;
	}
	cout <<  total % 10 << endl;
	return (0);
}