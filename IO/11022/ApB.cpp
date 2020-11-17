#include <iostream>
using	namespace	std;

int		main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int		cnt, i;
	int		a, b;

	cin >> cnt;
	i = cnt;
	while (cnt--) {
		cin >> a >> b;
		cout << "Case #" << i - cnt << ": " << a << " + " << b << " = " << a + b << endl;
	}
	return (0);
}