#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

vector<string>	v;

int	main(void) {
	string str;

	cin >> str;
	for (int i=0;i<str.size();i++)
		v.push_back(str.substr(i, str.length()));

	sort(v.begin(), v.end());
	for (auto s : v)
		cout << s << '\n';
}