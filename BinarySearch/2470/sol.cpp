#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int>	v;
int N;

int main(void) {
	int left, right, ph, pA, pB;
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	v = vector<int>(N);
	for (int i=0;i<N;i++)
		cin >> v[i];

	sort(v.begin(), v.end());
	left = 0;
	right = N-1;
	pA = v[left];
	pB = v[right];
	ph = abs(v[left] + v[right]);

	while (left < right) {
		int temp = v[left] + v[right];
		if (abs(temp) < ph) {
			ph = abs(temp);
			pA = v[left];
			pB = v[right];
		}

		if (temp < 0)
			left++;
		else
			right--;
	}
	cout << pA << ' ' << pB << endl;
	return 0;
}