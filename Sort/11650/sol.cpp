#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool	compare(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first)
		return a.second < b.second;
	else
		return a.first < b.first;
}

int		main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int		N;

	cin >> N;
	vector<pair<int, int>>	v(N);
	for(int i=0;i<N;i++)
		cin >> v[i].first >> v[i].second;
	sort(v.begin(), v.end(), compare);
	for(int i=0;i<N;i++)
		cout << v[i].first << " " << v[i].second << '\n';
}