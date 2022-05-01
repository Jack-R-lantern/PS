#include <iostream>
#include <vector>
#include <stack>
using namespace std;

#define MAX 1000000
vector<pair<int, int>>	v;
vector<int>	cnt, result;
stack<pair<int, int>>	s;
int N;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	v = vector<pair<int, int>>(N);
	result = vector<int>(N, -1);
	cnt = vector<int>(MAX+1);
	for (int i=0;i<N;i++) {
		v[i].first = i;
		cin >> v[i].second;
		cnt[v[i].second]++;
	}

	for (int i=0;i<N;i++) {
		while (!s.empty() && cnt[s.top().second] < cnt[v[i].second]) {
			result[s.top().first] = v[i].second;
			s.pop();
		}
		s.push(v[i]);
	}

	for (auto ngf : result)
		cout << ngf << ' ';
	cout << endl;
	return 0;
}