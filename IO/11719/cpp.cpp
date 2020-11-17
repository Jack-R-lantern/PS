#include <iostream>
using	namespace	std;

int		main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string	str;
	while (getline(cin, str)) {
		cout << str << endl;
	}
	return (0);
}