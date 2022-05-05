#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> note;
int T, N, M;

bool binarySearch(int left, int right, int find) {
	int mid = (left + right) / 2;
	if (left > right)
		return 0;
	if (note[mid] == find)
		return true;
	else if (note[mid] > find)
		return binarySearch(left, mid-1, find);
	else
		return binarySearch(mid + 1, right, find);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> T;
	while (T--) {
		cin >> N;
		note = vector<int>(N);
		for (int i=0;i<N;++i) {
			cin >> note[i];
		}
		sort(note.begin(), note.end());
		cin >> M;
		for (int i=0;i<M;i++) {
			int temp;
			cin >> temp;
			cout << binarySearch(0, N-1, temp) << '\n';
		}
	}
	return 0;
}