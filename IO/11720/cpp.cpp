#include <iostream>
using	namespace	std;

int		main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int		cnt, sum;

	sum = 0;
	cin >> cnt;
	cin.get();
	while (cnt--) {
		sum += cin.get() - '0';
	}
	cout << sum << endl;
	return (0);
}