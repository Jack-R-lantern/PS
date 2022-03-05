#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

int	main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	map<string, int, greater<string>>	m;
	int N;
	cin >> N;
	while (N--) {
		string name, cmd;
		cin >> name >> cmd;
		m[name]++;
	}
	for (auto iter : m) {
		if (iter.second % 2)
			cout << iter.first << "\n";
	}
	return 0;
}