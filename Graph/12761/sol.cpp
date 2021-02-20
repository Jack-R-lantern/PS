#include <iostream>
#include <queue>
using namespace std;

int		visit[100001];
int		A, B, N, M;

int		bfs() {
	queue<int>	q;
	int			v;

	q.push(N);
	while (!q.empty()) {
		v = q.front();
		if (v == M)
			return visit[v];
		q.pop();
		if (v + 1 <= 100000 && !visit[v+1]) {
			q.push(v+1);
			visit[v+1] = visit[v] + 1;
		}
		if (v - 1 >= 0 && !visit[v-1]) {
			q.push(v-1);
			visit[v-1] = visit[v] + 1;
		}
		if (v + A <= 100000 && !visit[v + A]) {
			q.push(v + A);
			visit[v + A] = visit[v] + 1;
		}
		if (v + B <= 100000 && !visit[v + B]) {
			q.push(v + B);
			visit[v + B] = visit[v] + 1;
		}
		if (v - A >= 0 && !visit[v - A]) {
			q.push(v - A);
			visit[v - A] = visit[v] + 1;
		}
		if (v - B >= 0 && !visit[v - B]) {
			q.push(v - B);
			visit[v - B] = visit[v] + 1;
		}
		if (v * A <= 100000 && !visit[v * A]) {
			q.push(v * A);
			visit[v * A] = visit[v] + 1;
		}
		if (v * B <= 100000 && !visit[v * B]) {
			q.push(v * B);
			visit[v * B] = visit[v] + 1;
		}
	}
	return (0);
}

int		main(void) {
	cin >> A >> B >> N >> M;
	cout << bfs() << endl;
	return (0);
}