#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

bool	visit[101];

int		bfs(vector<int> *a, pair<int, int> &s) {
	queue<pair<int, int>>	q;
	int		t, d = 0;

	q.push({s.first, d});
	visit[s.first] = 1;
	while (!q.empty()) {
		t = q.front().first;
		d = q.front().second;
		if (t == s.second)
			return (d);
		q.pop();
		for (int i = 0; i < a[t].size(); i++)
			if (!visit[a[t][i]]) {
				q.push({a[t][i], d + 1});
				visit[a[t][i]] = 1;
			}
	}
	return (-1);
}

int		main(void) {
	pair<int, int>	t, in;
	int		T, M;

	scanf("%d", &T);
	vector<int>	adj[T + 1];
	scanf("%d %d", &t.first, &t.second);
	scanf("%d", &M);
	while (M--) {
		scanf("%d %d", &in.first, &in.second);
		adj[in.first].push_back(in.second);
		adj[in.second].push_back(in.first);
	}
	printf("%d\n", bfs(adj, t));
	return (0);
}