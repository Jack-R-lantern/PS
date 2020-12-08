#include <cstdio>
#include <algorithm>
#include <deque>
using namespace std;

deque<pair<int, int>>	dq;

int		main(void) {
	int		N, total = 0;
	int		L, H, R, RH;
	int		max = 0;

	scanf("%d", &N);
	while (N--) {
		scanf("%d %d", &L, &H);
		max = H > max ? H : max;
		dq.push_back({L, H});
	}
	sort(dq.begin(), dq.end());
	L = dq.front().first;
	H = dq.front().second;
	if(H < max)
		dq.pop_front();
	while (H < max) {
		if (H < dq.front().second) {
			total += (dq.front().first - L) * H;
			H = dq.front().second;
			L = dq.front().first;
		}
		if(dq.front().second < max)
			dq.pop_front();
	}
	R = dq.back().first;
	RH = dq.back().second;
	if (RH < max)
		dq.pop_back();
	while (RH < max) {
		if (RH < dq.back().second) {
			total += abs(dq.back().first - R) * RH;
			RH = dq.back().second;
			R = dq.back().first;
		}
		if(dq.back().second < max)
			dq.pop_back();
	}
	total += (abs(dq.front().first - dq.back().first) + 1) * max;
	printf("%d\n", total);
	return (0);
}