#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int>	A, B;
int T, N, M;

int binarySearch(int find) {
	int left = 0, right = B.size() - 1;
	while (left <= right) {
		int mid = (left + right) / 2;
		if (find > B[mid])
			left = mid + 1;
		else
			right = mid - 1;
	}
	return left;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> T;
	while (T--) {
		long long sum = 0;
		cin >> N >> M;

		A = vector<int>(N);
		B = vector<int>(M);
		for (int i=0;i<N;i++)
			cin >> A[i];
		sort(A.begin(), A.end());
		for (int i=0;i<M;i++)
			cin >> B[i];
		sort(B.begin(), B.end());
		for (int i=0;i<N;i++)
			sum += binarySearch(A[i]);
		cout << sum << '\n';
	}
	return 0;
}