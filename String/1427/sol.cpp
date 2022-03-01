#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int	main(void) {
	string str;
	cin >> str;
	sort(str.begin(), str.end(), greater<char>());
	cout << str << endl;
	return 0;
}