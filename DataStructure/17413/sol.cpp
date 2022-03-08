#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack<char>	s;

int	main(void) {
	ios::sync_with_stdio(false);
	cout.tie(nullptr);

	string	str;
	bool	flag = false;
	getline(cin,str);
	for (auto ch : str) {
		if (ch == '<') {
			while (!s.empty()) {
				cout << s.top();
				s.pop();
			}
			flag = true;
			cout << ch;
		}
		else if (ch == '>') {
			flag = false;
			cout << ch;
		}
		else if (flag) {
			cout << ch;
		}
		else if (ch == ' ') {
			while (!s.empty()) {
				cout << s.top();
				s.pop();
			}
			cout << ch;			
		}
		else {
			s.push(ch);
		}
	}
	while (!s.empty()) {
		cout << s.top();
		s.pop();
	}
	cout << endl;
	return 0;
}