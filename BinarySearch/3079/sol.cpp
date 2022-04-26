#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
using namespace std;

vector<int>	v;
int N, M;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	long long left, right=LLONG_MAX, mid, ans;

	cin >> N >> M;
	v = vector<int>(N);
	for (int i=0;i<N;i++) {
		cin >> v[i];
		right = min(right, static_cast<long long>(v[i]));
	}

	left = 0;
	right *= M;
	while (left <= right) {
		mid = left + (right - left) / 2;

		long long sum = 0;
		for (int i=0;i<N;++i)
			sum += mid /v[i];

		if (sum < M) {
			left = mid + 1;
		}
		else {
			ans = mid;
			right = mid - 1;
		}
	}
	cout << ans << endl;
	return 0;
}