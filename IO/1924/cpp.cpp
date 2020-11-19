#include <iostream>
using	namespace	std;

int		main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	const char	*day[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};
	int			month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int			x, y;
	int			i;
	int			sum;

	cin >> x >> y;
	sum = 0;
	i = 0;
	while (i < x - 1) {
		sum += month[i];
		i++;
	}
	sum += y;
	cout << day[sum % 7] << endl;
	return (0);
}