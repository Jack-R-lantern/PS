#include <iostream>
#include <deque>
#include <string>
using namespace std;

int		main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	string	str, tc, toi;
	int		T, n, flag;
	int		i;

	cin >> T;
	while (T--) {
		cin >> str >> n;
		i = 0;
		flag = 1;
		cin >> tc;
		toi.clear();
		deque<int>	dq;
		while(tc[i]) {
			if (tc[i] != '[' && tc[i] != ',' && tc[i] != ']')
				toi += tc[i];
			else if (tc[i] == ',' || tc[i] == ']') {
				if (toi.size())
					dq.push_back(stoi(toi));
				toi.clear();
			}
			i++;
		}
		i = 0;
		while (str[i]) {
			if (str[i] == 'D') {
				if (dq.empty()) {
					cout << "error\n";
					flag = 2;
					break;
				}
				else {
					if (flag == 1)
						dq.pop_front();
					else
						dq.pop_back();
				}
			}
			else
				flag *= -1;
			i++;
		}
		if (flag != 2) {
			cout << '[';
			while (!dq.empty()) {
				if (flag == 1) {
					cout << dq.front();
					dq.pop_front();
				}
				else {
					cout << dq.back();
					dq.pop_back();
				}
				if (!dq.empty())
					cout << ',';
			}
			cout << "]\n";
		}
	}
	return (0);
}