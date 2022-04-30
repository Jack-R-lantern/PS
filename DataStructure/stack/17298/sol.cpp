#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> v, result;
stack<pair<int, int>>	s;
int N, top = -1;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	v = vector<int>(N);
	result = vector<int>(N);
	for (int i=0;i<N;++i)
		cin >> v[i];

	for (int i=0;i<N;++i) {
		if (s.empty() || s.top().second > v[i])
			s.push({i, v[i]});
		else {
			while (!s.empty() && s.top().second < v[i]) {
				result[s.top().first] = v[i];
				s.pop();
			}
			s.push({i, v[i]});
		}
	}

	while (!s.empty()) {
		result[s.top().first] = -1;
		s.pop();
	}

	for (auto n : result)
		cout << n << ' ';
	cout << endl;
	return 0;
}