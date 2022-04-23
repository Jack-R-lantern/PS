#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<int>	v;
int N;

int	main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int left, right, pA, pB, abs_max;
	cin >> N;

	v = vector<int>(N);
	for (int i=0;i<v.size();i++)
		cin >> v[i];

	left = 0;
	right = v.size()-1;

	int ph = abs(v[left] + v[right]);
	pA = v[left];
	pB = v[right];

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
	cout << pA << " " << pB << endl;
	return 0;
}