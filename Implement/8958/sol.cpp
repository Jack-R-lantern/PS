#include <iostream>
#include <string>
using namespace std;

int		main(void) {
	string	str;
	int		T, total, j;

	cin >> T;
	while (T--) {
		total ^= total;
		cin >> str;
		j = 1;
		for (int i=0;i<str.length();i++) {
			if (str[i] == 'O')
				total += j++;
			else
				j = 1;
		}
		cout << total << endl;
	}
}