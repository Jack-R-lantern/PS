#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool	visit[1001];
int		N, M;

void	dfs(vector<vector<int>> &v, int start) {
	visit[start] = true;

	for(int i = 0;i < v[start].size();i++) {
		if (!visit[v[start][i]]) {
			dfs(v, v[start][i]);
		}
	}
}

int		main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;

	int	v1, v2;
	int cnt = 0;

	vector<vector<int>> v(N+1);
	for (int i=0;i<M;i++) {
		cin >> v1 >> v2;
		v[v1].push_back(v2);
		v[v2].push_back(v1);
	}
	for (int i=1;i<=N;i++)
		if(!visit[i]) {
			dfs(v, i);
			cnt++;
		}
	cout << cnt << endl;
	return (0);
}