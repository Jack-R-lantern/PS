#include <iostream>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

class Compare {
	public:
		bool operator() (const string &a, const string &b) const {
			if (a.length() == b.length())
				return a < b;
			else
				return a.length() < b.length();
		}
};

int		main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int		N;

	cin >> N;
	set<string, Compare>	dir;
	for(int i=0;i<N;i++) {
		string	temp;
		cin >> temp;
		dir.insert(temp);
	}
	for(set<string, Compare>::iterator it = dir.begin();it != dir.end();++it) {
		cout << *it << '\n';
	}
}