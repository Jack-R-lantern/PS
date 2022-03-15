#include <iostream>
#include <queue>
#include <climits>
using namespace std;

#define MAX 100001
int cnt[MAX];
int N, K, MIN = INT_MAX;

long long bfs() {
	queue<pair<int, int>>	q;
	long long total = 0;

	cnt[N] = 0;
	q.push({0, N});
	while (!q.empty()) {
		int t = q.front().first;
		int p = q.front().second;
		q.pop();

		if (p == K) {
			if (MIN > t) {
				MIN = t;
				total = 0;
			}
			total++;
		}
		if (p+1 < MAX) {
			if (cnt[p+1] == -1 || cnt[p+1] >= t+1) {
				cnt[p+1] = t+1;
				q.push({t+1, p+1});
			}
		}
		if (0 <= p-1) {
			if (cnt[p-1] == -1 || cnt[p-1] >= t+1) {
				cnt[p-1] = t+1;
				q.push({t+1, p-1});
			}
		}
		if (p*2 < MAX) {
			if (cnt[p*2] == -1 || cnt[p*2] >= t+1) {
				cnt[p*2] = t+1;
				q.push({t+1, p*2});
			}
		}
	}
	cout << MIN << endl;
	return total;
}

int	main(void) {
	fill(cnt, cnt+100001, -1);
	cin >> N >> K;
	cout << bfs() << endl;
	return 0;
}