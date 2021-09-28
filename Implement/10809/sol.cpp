#include <iostream>
#include <string>
using namespace std;

int		check[26];

int		main(void) {
	string	s;

	cin >> s;
	memset(check, -1, sizeof(int)*26);
	for (int i=0;i<s.size();++i) {
		if (check[s[i] - 'a'] < 0)
			check[s[i] - 'a'] = i;
	}
	for (int i=0;i<26;++i)
		cout << check[i] << ' ';
	cout << endl;
	return 0;
}