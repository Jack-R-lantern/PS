#include <iostream>
#include <vector>
using namespace std;

vector<long long>	v;
int N, M;

int	main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	long long sum = 0, low = -1, high;
	cin >> N >> M;
	v = vector<long long>(N);

	for (int i=0;i<N;i++) {
		cin >> v[i];
		sum += v[i];
		low = max(low, v[i]);
	}

	high = sum;

	while (low <= high) {
		long long cnt = 0, tempSum = 0;
		long long mid = (low + high) / 2;

		for (int i = 0; i < N; i++) {
			if (tempSum + v[i] > mid) {
				tempSum = 0;
				cnt += 1;
			}
			tempSum += v[i];
		}
		if (tempSum != 0)
			cnt += 1;
		if (cnt <= M) {
			high = mid - 1;
		}
		else {
			low = mid + 1;
		}
	}
	cout << low << endl;
	return 0;
}