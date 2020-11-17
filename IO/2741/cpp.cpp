#include <iostream>
using	namespace	std;

int		main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int		cnt;

	cin >> cnt;
	int	i = 1;
	while (cnt--)
		cout << i++ << '\n';
	return (0);
}