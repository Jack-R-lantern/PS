#include <iostream>
using	namespace	std;

int		main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int		cnt;
	int		a, b;

	cin >> cnt;
	while (cnt--) {
		cin >> a;
		cin.ignore(1);
		cin >> b;
		cout << a + b << endl;
	}
	return (0);
}