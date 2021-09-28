#include <iostream>
#include <string>
using namespace std;

int		main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string	s;
	bool	flag = true;
	int		cnt = 0;
	getline(cin, s);
	for (int i=0;i<s.size();++i) {
		if (isspace(s[i]))
			flag = true;
		else if (!isspace(s[i]) && flag) {
			++cnt;
			flag = false;
		}
		else
			continue;
	}
	cout << cnt << '\n';
	return (0);
}