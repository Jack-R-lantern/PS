#include <iostream>
using	namespace	std;

int		main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int		n, i;

	i = 1;
	cin >> n;
	while (i <= 9)
		cout << n << " * " << i << " = " << n * i++ <<endl;
	return (0);
}