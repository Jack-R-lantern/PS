#include <iostream>
#include <string>
using namespace std;

int		main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string	str;
	bool	flag;
	while (1) {
		int	left, right;
		flag = true;
		getline(cin, str);
		if (str[0] == '0')
			break;
		left = 0;
		right = str.size() - 1;
		while (left <= right) {
			if (str[left] == str[right]) {
				left++;
				right--;
			}
			else {
				flag = false;
				break;
			}
		}
		if (flag)
			cout << "yes" << '\n';
		else
			cout << "no" << '\n';
	}
	return (0);
}