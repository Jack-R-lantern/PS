#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int	V, MAX, P;
bool visited[100001];

void dfs(vector<vector<pair<int, int>>>	&v, int n, size_t total) {
	visited[n] = true;
	for (int i=0;i<v[n].size();i++) {
		if (!visited[v[n][i].first]) {
			if (MAX < total + v[n][i].second) {
				MAX = total + v[n][i].second;
				P = v[n][i].first;
			}
			dfs(v, v[n][i].first, total + v[n][i].second);
		}
	}
}

int		main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> V;
	vector<vector<pair<int, int>>>	v(V+1);
	for (int i=1;i<=V;i++) {
		int idx;
		
		cin >> idx;
		while (1) {
			int ver, adj;
			cin >> ver;
			if (ver == -1)
				break;
			cin >> adj;
			v[idx].push_back(make_pair(ver, adj));
		}
	}
	dfs(v, 1, 0);
	memset(visited, 0, sizeof(visited));
	dfs(v, P, 0);
	cout << MAX << endl;
	return 0;
}