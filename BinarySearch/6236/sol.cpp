#include <iostream>
#include <vector>
using namespace std;

const int MAX = 100000;

vector<int>	v;
int N, M;

/*
 * 남은 금액 > 하루 소비량
 * 		-> 그대로
 * 남은 금액 < 하루 소비량
 * 		-> 남은 금액 입금 후 다시 K원 인출
 *
 */

bool valid(int mid) {
	int temp = mid;
	int cnt = 1;

	for (int i=0;i<N;i++) {
		if (mid >= v[i])
			mid -= v[i];
		else {
			mid = temp;
			cnt++;
			if (v[i] > mid)
				return false;
			else
				mid -= v[i];
		}
	}
	return cnt <= M;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int left = 0, right = 0;
	int result = 0;

	cin >> N >> M;
	v = vector<int>(N);
	for (int i=0;i<N;i++) {
		cin >> v[i];
		right += v[i];
	}
	while (left <= right) {
		int mid = (left + right) / 2;

		if (valid(mid)) {
			result = mid;
			right = mid - 1;
		}
		else
			left = mid + 1;
	}

	cout << result << endl;
	return 0;
}