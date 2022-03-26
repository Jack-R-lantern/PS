#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int>	v, temp;
int N;

int	main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	v = vector<int>(N);
	for (int i=0;i<N;i++)
		cin >> v[i];
	temp = v;
	sort(temp.begin(), temp.end());
	temp.erase(unique(temp.begin(), temp.end()), temp.end());

	for (int i=0;i<N;i++) {
		auto iter = lower_bound(temp.begin(), temp.end(), v[i]);
		cout << iter - temp.begin() << ' ';
	}
	cout << endl;
	return 0;
}