#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int>	v;
int M, N;

bool slice(int len) {
	long long cnt = 0;
	for (int i=0;i<N;i++)
		cnt += v[i] / len;

	return cnt >= M;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int left = 1, right, result = 0;
	cin >> M >> N;

	v = vector<int>(N);
	for (int i=0;i<N;i++) {
		cin >> v[i];
		right = max(right, v[i]);
	}

	while (left <= right) {
		int mid = (left + right) / 2;

		if (slice(mid)) {
			result = mid;
			left = mid + 1;
		}
		else
			right = mid - 1;
	}
	cout << result << endl;
	return 0;
}