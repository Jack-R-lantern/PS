#include <iostream>
using namespace std;

const int MAX = 1000000000;

long long X, Y;
int Z;

int main(void) {
	cin >> X >> Y;

	Z = (Y * 100) / X;
	if (Z >= 99) {
		cout << "-1" << endl;
		return 0;
	}

	int left = 0, right = MAX, mid, ans = -1;
	while (left <= right) {
		mid = (left + right) / 2;
		if (((Y+mid)*100/(X+mid)) <= Z) {
			ans = mid + 1;
			left = mid + 1;
		}
		else
			right = mid - 1;
	}

	cout << ans << endl;
	return 0;
}