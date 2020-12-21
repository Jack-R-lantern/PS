#include <algorithm>
#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;

int		V, E, S;
char	visit[1000];

void	dfs(vector<vector<int>> &v, int start) {
	cout << start << ' ';
	visit[start - 1] = 1;
	for(int i = 0;i < v[start - 1].size();i++) {
		if (!visit[v[start - 1][i] - 1]) {
			dfs(v, v[start - 1][i]);
		}
	}
}

void	bfs(vector<vector<int>> &v, int start) {
	queue<int>	q;
	int			node;

	q.push(start);
	visit[start - 1] = 1;
	while (!q.empty()) {
		node = q.front();
		cout << node << ' ';
		for(int i = 0;i < v[node - 1].size();i++) {
			if (!visit[v[node - 1][i] - 1]) {
				visit[v[node - 1][i] - 1] = 1;
				q.push(v[node - 1][i]);
			}
		}
		q.pop();
	}
	cout << '\n';
}

int		main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int		v1, v2;

	cin >> V >> E >> S;
	vector<vector<int>>	v(V);
	while (E--) {
		cin >> v1 >> v2;
		v[v1 - 1].push_back(v2);
		v[v2 - 1].push_back(v1);
	}
	for (int i = 0;i < v.size();i++)
		sort(v[i].begin(), v[i].end());
	dfs(v, S);
	cout << '\n';
	memset(visit, 0, 1000);
	bfs(v, S);
	return (0);
}