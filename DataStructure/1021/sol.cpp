#include <cstdio>
#include <deque>
using namespace std;

deque<int>  dq;

int     main(void) {
	int     N, M;
	int		num, total;
	scanf("%d %d", &N, &M);
	for (int i=1;i<=N;i++)
		dq.push_back(i);
	total = 0;
	while (M--) {
		int		idx = 0;
		scanf("%d", &num);
		while (dq[idx] != num)
			idx++;
		if (dq.size() - idx + 1 >= idx + 1) {
			while (dq.front() != num) {
				dq.push_back(dq.front());
				dq.pop_front();
				total++;
			}
			dq.pop_front();
		}
		else {
			while (dq.back() != num) {
				dq.push_front(dq.back());
				dq.pop_back();
				total++;
			}
			dq.pop_back();
			total++;
		}
	}
	printf("%d\n", total);
	return (0);
}