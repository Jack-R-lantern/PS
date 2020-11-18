#include <iostream>
using	namespace	std;

int		main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int		cnt;
	int		i, j;

	cin >> cnt;
	i = 0;
	while (i < cnt) {
		j = 0;
		while (j++ < cnt - i)
			cout << '*';
		cout << endl;
		i++;
	}
	return (0);
}
