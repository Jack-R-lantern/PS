#include <iostream>
using	namespace	std;
int		main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int		cnt;

	cin >> cnt;
	while (cnt)
		cout << cnt-- << '\n';
	return (0);
}