#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int>	v;
long long total, cnt;
int N;

int	main(void) {
	cin >> N;

	v = vector<int>(N);
	for (int i=0;i<N;i++)
		cin >> v[i];

	sort(v.begin(), v.end());

	for (auto a : v) {
		cnt += a;
		total += cnt;
	}

	cout << total << endl;
	return 0;
}