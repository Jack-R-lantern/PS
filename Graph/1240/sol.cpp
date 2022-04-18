#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<vector<pair<int, int>>>	adj;
bool visited[1001];
int N, M;

int dfs(int to, int from, int len) {
	int total = 0;
	if (to == from)
		return len;
	visited[to] = true;

	for (auto p : adj[to]) {
		if(visited[p.first] == true)
			continue;
		total = dfs(p.first, from, p.second);
		if (total != 0)
			return len + total;
	}
	return total;
}

int	main(void) {
	int to, from;

	cin >> N >> M;
	adj = vector<vector<pair<int, int>>>(N+1);
	for (int i=1;i<N;i++) {
		int len;
		cin >> to >> from >> len;

		adj[to].push_back({from, len});
		adj[from].push_back({to, len});
	}
	while(M--) {
		cin >> to >> from;
		cout << dfs(to, from, 0) << '\n';
		memset(visited, 0, sizeof(visited));
	}

	return 0;
}