#include <iostream>
using	namespace	std;

int		main(void) {
	int		cnt;
	int		i, j;

	cin >> cnt;
	i = 0;
	while (i < cnt) {
		j = 0;
		while (j <= i) {
			cout << '*';
			j++;
		}
		cout << endl;
		i++;
	}
	return (0);
}
