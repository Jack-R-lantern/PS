#include <cstdio>
#include <queue>
using namespace std;

int		main(void) {
	int		T, cnt;
	int		N, M;

	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &N, &M);
		queue<pair<int, int>>	q;
		priority_queue<int>		pq;
		for (int i=0;i < N;i++) {
			scanf("%d", &cnt);
			q.push({i, cnt});
			pq.push(cnt);
		}
		cnt = 0;
		while (!q.empty()) {
			if (q.front().second == pq.top()) {
				cnt++;
				pq.pop();
				if (q.front().first == M)
					printf("%d\n", cnt);
				q.pop();
			}
			else {
				q.push({q.front().first, q.front().second});
				q.pop();
			}
		}
	}
	return (0);
}