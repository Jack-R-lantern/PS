#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

vector<int>	top, bottom;
int N, H;

int	main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N >> H;
	top = vector<int>(N/2);
	bottom = vector<int>(N/2);

	for (int i=0;i<N/2;i++)
		cin >> bottom[i] >> top[i];

	sort(bottom.begin(), bottom.end());
	sort(top.begin(), top.end());

	int result = INT_MAX;
	int cnt = 1;

	for (int i=1;i<=H;i++) {
		int temp = bottom.size() - (lower_bound(bottom.begin(), bottom.end(), i) - bottom.begin());
		temp += top.size() - (upper_bound(top.begin(), top.end(), H-i) - top.begin());

		if (result == temp)
			cnt++;
		else if (result > temp) {
			result = temp;
			cnt = 1;
		}
	}
	cout << result << " " << cnt << endl;
	return 0;
}