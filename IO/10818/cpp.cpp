#include <iostream>
using	namespace	std;

int		main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int		cnt;
	int		max, min;
	int		temp;

	cin >> cnt;
	cin >> temp;
	max = temp;
	min = temp;
	while (--cnt) {
		cin >> temp;
		if (temp > max)
			max = temp;
		else if (temp < min)
			min = temp;
	}
	cout << min <<' ' << max << endl;
}