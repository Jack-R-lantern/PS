#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int, int>>	v;
int N;

int	main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	while (N--) {
		int start, end;
		
		cin >> start >> end;
		v.push_back({end, start});
	}

	sort(v.begin(), v.end());

	int end = v[0].first;
	int cnt = 1;
	for (int i=1;i<v.size();i++) {
		if (end <= v[i].second) {
			cnt++;
			end = v[i].first;
		}
	}
	cout << cnt << endl;
	return 0;
}