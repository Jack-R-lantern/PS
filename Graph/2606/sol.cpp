#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

bool	visit[100];

int		dfs(vector<vector<int>> &v, int start) {
	int		total = 1;
	visit[start] = true;
	for (int i = 0; i < v[start].size(); i++) {
		if (!visit[v[start][i]]) {
			visit[v[start][i]] = 1;
			total += dfs(v, v[start][i]);
		}
	}
	return (total);
}

int		bfs(vector<vector<int>> &v) {
	queue<int>	q;
	int		total = 0;

	q.push(0);
	visit[0] = true;
	while (!q.empty()) {
		for(int i = 0; i < v[q.front()].size(); i++)
			if (!visit[v[q.front()][i]]) {
				visit[v[q.front()][i]] = true;
				q.push(v[q.front()][i]);
				total++;
			}
		q.pop();
	}
	return (total);
}

int		main(void) {
	pair<int, int>	i;
	int		V, E;

	scanf("%d%d", &V, &E);
	vector<vector<int>>	v(V);
	while (E--) {
		scanf("%d %d", &i.first, &i.second);
		v[i.first - 1].push_back(i.second - 1);
		v[i.second - 1].push_back(i.first - 1);
	}
	printf("%d\n", dfs(v , 0) - 1);
}