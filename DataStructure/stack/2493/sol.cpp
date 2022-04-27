#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int>	v;
stack<pair<int, int>>	s;
int N;

int	main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	v = vector<int>(N);

	int temp;
	cin >> temp;
	s.push({1,temp});
	v[0] = 0;

	for (int i=1;i<N;i++) {
		cin >> temp;
		if (s.top().second > temp) {
			v[i] = s.top().first;
		}
		else {
			while (!s.empty() && s.top().second < temp)
				s.pop();
			if (s.empty())
				v[i] = 0;
			else
				v[i] = s.top().first;
		}
		s.push({i+1, temp});
	}

	for (auto r : v)
		cout << r << ' ';
	cout << endl;
	return 0;
}