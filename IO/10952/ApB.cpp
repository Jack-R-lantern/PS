#include <iostream>
using	namespace	std;

int		main(void) {
	cin.sync_with_stdio(false);
	cin.tie(NULL);
	int		a, b;

	while ((cin >> a >> b) && (a | b)) {
		cout << a + b << endl;
	}
	return (0);
}