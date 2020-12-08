#include <iostream>
#include <string>
#include <stack>
using namespace std;

stack<char>		st;

int		main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string		str;
	cin >> str;
	int M;
	char CMD;
	cin >> M;
	while (M--) {
		cin >> CMD;
		if (CMD == 'L' && str.size()) {
			st.push(str.back());
			str.pop_back();
		}
		else if (CMD == 'D' && st.size()) {
			str.push_back(st.top());
			st.pop();
		}
		else if (CMD == 'B' && str.size()) {
			str.pop_back();
		}
		else if (CMD == 'P') {
			char c;
			cin >> c;
			str.push_back(c);
		}
	}
	while (!st.empty()) {
		str.push_back(st.top());
		st.pop();
	}
	cout << str << '\n';
	return (0);
}