#include <cstdio>
#include <algorithm>
#include <deque>
using namespace std;

deque<pair<int, int>>	dq;

int		main(void) {
	int		N;
	int		L, H;
	int		max = 0;

	scanf("%d", &N);
	while (N--) {
		scanf("%d %d", &L, &H);
		max = H > max ? H : max;
		dq.push_back({L, H});
	}
	sort(dq.begin(), dq.end());
	while (dq.front().second != max) {
		
	}
	return (0);
}