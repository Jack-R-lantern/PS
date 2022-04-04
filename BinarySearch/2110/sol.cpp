#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int>	v;
int N, C;

int	main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> C;
	v = vector<int>(N);

	for (int i=0;i<N;i++)
		cin >> v[i];
	sort(v.begin(), v.end());

	int left = 0, right = v[N-1];
	while (left <= right) {
		int cnt = 1;
		int pre = 0;
		int mid = (left + right)/2;
		for (int i=0;i<N;i++)  {
			if (v[i] - v[pre] >= mid) {
				pre = i;
				cnt++;
			}
		}
		if (cnt >= C)
			left = mid + 1;
		else right = mid - 1;
	}
	cout << right << endl;
	return 0;
}