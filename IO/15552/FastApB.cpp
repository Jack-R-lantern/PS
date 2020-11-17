#include <iostream>
using	namespace	std;

int		main(void) {
	cin.sync_with_stdio(false);
	cin.tie(NULL);

	int		cnt;
	int		a, b;

	cin >> cnt;
	while (cnt--) {
		cin >> a >> b;
		cout << a + b << "\n";
	}
	return (0);
}