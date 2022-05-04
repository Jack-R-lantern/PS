#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int>	v;
int N, M;

int main(void) {
	int left, right,result, MAX = 0;

	cin >> N;
	v = vector<int>(N);
	for (int i=0;i<N;i++)
		cin >> v[i];
	cin >> M;
	left = 0;
	right = *max_element(v.begin(), v.end());
	while (left <= right) {
		int mid = (left + right) / 2, sum = 0;
		for (int i=0;i<N;i++) {
				sum += min(v[i], mid);
		}
		if (sum > M)
			right = mid - 1;
		else {
			result = mid;
			left = mid + 1;
		}
	}
	cout << result << endl;
	return 0;
}