#include <iostream>
#include <string>
using namespace std;

int M, mask;

int	main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> M;
	while (M--) {
		string	cmd;
		int		input;
		cin >> cmd;
		switch(cmd[1]) {
			case 'd':
				cin >> input;
				mask |= 1 << input;
				break;
			case 'e':
				cin >> input;
				mask &= ~(1 << input);
				break;
			case 'h':
				cin >> input;
				if (mask & (1 << input))
					cout << "1\n";
				else
					cout << "0\n";
				break;
			case 'o':
				cin >> input;
				mask ^= (1 << input);
				break;
			case 'l':
				mask = 2097151;
				break;
			default:
				mask ^= mask;
		}
	}
	return 0;
}