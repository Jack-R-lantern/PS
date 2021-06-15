#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int		main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int		N, temp;
	cin >> N;
	vector<int>	v(N);
	for (int i=0;i<N;i++)
		cin >> v[i];
	sort(v.begin(), v.end());
	cin >> N;
	for (int i=0;i<N;i++) {
		cin >> temp;
		cout << upper_bound(v.begin(), v.end(), temp) - lower_bound(v.begin(), v.end(), temp) << ' ';
	}
	cout << '\n';
	return (0);
}