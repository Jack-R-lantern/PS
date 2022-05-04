#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int>	v, c;
int N, M;

int binarySearch(int left, int right, int find) {
	int mid = (left + right) / 2;
	if (left > right)
		return 0;
	if (v[mid] == find)
		return 1;
	else if (v[mid] > find)
		return binarySearch(left, mid-1, find);
	else
		return binarySearch(mid + 1, right, find);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	v = vector<int>(N);
	for (int i=0;i<N;i++)
		cin >> v[i];
	sort(v.begin(), v.end());
	cin >> M;
	c = vector<int>(M);
	for (int i=0;i<M;i++)
		cin >> c[i];
	for (int i=0;i<M;i++)
		c[i] = binarySearch(0, N-1, c[i]);
	for (auto j : c)
		cout << j << ' ';
	cout << endl;
	return 0;
}