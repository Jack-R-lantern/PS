#include <cstdio>
#include <deque>
using namespace std;

deque<pair<int, int> >		dq;

int		main(void) {
	int		N, num;
	int		i = 1;
	scanf("%d", &N);
	while (N--) {
		scanf("%d", &num);
		dq.push_back(make_pair(i++, num));
	}
	while (!dq.empty()) {
		printf("%d ", dq.front().first);
		num = dq.front().second;
		dq.pop_front();
		if (num > 0) {
			while (num-- > 1) {
				dq.push_back(dq.front());
				dq.pop_front();
			}
		}
		else {
			num *= -1;
			while (num--) {
				dq.push_front(dq.back());
				dq.pop_back();
			}
		}
	}
	printf("\n");
	return (0);
}