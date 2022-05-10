#include <iostream>
#include <vector>
#include <climits>
using namespace std;

vector<int>	v;
long long result = LLONG_MAX;
int N, M;

bool distrbute(int mid) {
	long long num = 0;
	for (int i=0;i<M;i++) {
		num += (v[i] / mid);
		if (v[i] % mid)
			++num;
	}
	return N >= num;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	long long left = 1, right = 0;
	cin >> N >> M;

	v = vector<int>(M);
	for (int i=0;i<M;i++) {
		cin >> v[i];
		if (v[i] > right)
			right = v[i];
	}

	while (left <= right) {
		long long mid = (left + right) / 2;
		if (distrbute(mid)) {
			if (result > mid)
				result = mid;
			right = mid - 1;
		}
		else
			left = mid + 1;
	}
	cout << result << endl;
	return 0;
}