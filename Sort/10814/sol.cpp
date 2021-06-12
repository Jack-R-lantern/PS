#include <iostream>
#include <string>
#include <map>
using namespace std;

int		main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	multimap<int, string>	dir;
	string	temp;
	int		N, age;

	cin >> N;
	for (int i=0;i<N;i++) {
		cin >> age >> temp;
		dir.insert(make_pair(age, temp));
	}

	for (multimap<int, string>::iterator it = dir.begin();it != dir.end();++it)
		cout << (*it).first << " " << (*it).second << '\n';
}