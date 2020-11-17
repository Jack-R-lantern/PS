#include <iostream>
using	namespace	std;

int		main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string	str;
	int		i = 0;
	getline(cin, str);
	while(i < str.size()) {
		cout << str[i];
		if ((i + 1) % 10 == 0)
			cout << '\n';
		i++;
	}
	cout << '\n';
	return (0);
}