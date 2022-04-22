#include <iostream>
#include <string>
using namespace std;

int cnt[26];

int	main(void) {
	string str;

	cin >> str;

	for (int i=0;i<str.size();i++)
		cnt[str[i]-'a']++;
	for (int i=0;i<26;i++)
		cout << cnt[i] << ' ';
	cout << endl;
	return 0;
}