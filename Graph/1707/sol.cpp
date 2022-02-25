#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

bool flag;
bool visited[20001];
char set[20001];

void	dfs(vector<vector<int>> &v, int n, int s) {
	visited[n] = true;
	set[n] = s;
	for (int i=0;i<v[n].size();i++) {
		if (!visited[v[n][i]])
			dfs(v, v[n][i], s * -1);
		else {
			if (set[v[n][i]] == s) {
				flag = false;
				break;
			}
		}
	}
}

int		main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int K;

	cin >> K;
	while (K--) {
		int V, E;
		cin >> V >> E;
		vector<vector<int>>	v(V+1);
		flag = true;
		while(E--) {
			int a, b;
			cin >> a >> b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		for (int i=1;i<v.size();i++) {
			if (!visited[i])
				dfs(v, i, 1);
			if (!flag)
				break;
		}
		if (flag)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
		memset(visited, 0, sizeof(visited));
		memset(set, 0, sizeof(set));
	}
}