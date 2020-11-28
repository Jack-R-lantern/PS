#include <cstdio>
#include <deque>
using namespace std;

deque<int>	dq;

int		main(void) {
	int		N;

	scanf("%d", &N);
	while (N)
		dq.push_front(N--);
	while (1) {
		if (dq.size() == 1)
			break;
		dq.pop_front();
		dq.push_back(dq.front());
		dq.pop_front();
	}
	printf("%d\n", dq.front());
	return (0);
}