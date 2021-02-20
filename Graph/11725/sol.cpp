#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int		visit[100001];
int		N;

void	bfs(vector<vector<int>>&v) {
	queue<int>	q;
	int			val;

	visit[1] = 1;
	for (int i=0;i<v[1].size();i++) {
		visit[v[1][i]] = 1;
		q.push(v[1][i]);
	}
	while (!q.empty()) {
		val = q.front();
		q.pop();
		for(int i=0;i<v[val].size();i++)
			if (!visit[v[val][i]]) {
				visit[v[val][i]] = val;
				q.push(v[val][i]);
			}
	}
}

int		main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	vector<vector<int>>	v(N+1);

	for (int i=1;i<N;i++) {
		int	v1, v2;
		cin >> v1 >> v2;
		v[v1].push_back(v2);
		v[v2].push_back(v1);
	}
	bfs(v);
	for (int i=2;i<=N;i++)
		cout << visit[i] << "\n";
}