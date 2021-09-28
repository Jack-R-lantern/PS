#include <iostream>
#include <string>
using namespace std;

int		check[26];

int		main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string	s;

	cin >> s;
	for (int i=0;i<s.size();++i)
		++check[toupper(s[i]) - 'A'];
	int max = 0, cnt = 0, pivot;
	for (int i=0;i<26;++i) {
		if (max < check[i]) {
			max = check[i];
			pivot = i;
			cnt = 0;
		}
		if (max == check[i])
			cnt++;
	}
	if (cnt > 1)
		cout << "?\n";
	else
		cout << (char)(pivot + 'A') << '\n';
	return (0);
}