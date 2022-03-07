#include <iostream>
#include <string>
#include <stack>
using namespace std;

stack<int>	s;
int N, num;

int	main(void) {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	string str;
	int top = 1;
	cin >> N;
	for (int i=0;i<N;i++) {
		cin >> num;
		while (top <= num)
		{
			s.push(top++);
			str += "+\n";
		}
		if (s.top() == num) {
			s.pop();
			str += "-\n";
		}
		else {
			str = "NO\n";
			break;
		}
	}
	cout << str;
	return 0;
}