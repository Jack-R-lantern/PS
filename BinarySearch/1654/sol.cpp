#include <iostream>
using namespace std;

int			K, N, ans;
int			line[10000];
long long	hi, lo, mid;

int		main(void) {
	cin >> K >> N;
	for (int i=0;i<K;++i) {
		cin >> line[i];
		if (hi < line[i])
			hi = line[i];
	}
	lo = 1;
	while (lo <= hi) {
		int cnt = 0;
		mid = lo + (hi - lo) / 2;

		for (int i=0;i<K;++i)
			cnt += line[i] / mid;
		if (cnt >= N) {
			lo = mid + 1;
			if (ans < mid)
				ans = mid;
		}
		else {
			hi = mid - 1;
		}
	}
	cout << ans << endl;
	return (0);
}