#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

vector<vector<pair<int, int>>>	v;
bool visited[10001];
int V, E;
int set[10001];

int	prime() {
	int result = 0;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>	pq;
	pq.push({-0, 1});
	while(!pq.empty()) {
		int w = pq.top().first;
		int to = pq.top().second;
		pq.pop();
		if (visited[to])
			continue;

		result += w;
		visited[to] = true;
		for (int i=0;i<v[to].size();i++)
			pq.push({v[to][i].first, v[to][i].second});
	}
	return result;
}

int	main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int from, to, w;

	cin >> V >> E;
	v = vector<vector<pair<int, int>>>(V+1);
	for (int i=1;i<=E;i++) {
		cin >> from >> to >> w;
		v[from].push_back({w, to});
		v[to].push_back({w, from});
	}
	cout << prime() << endl;
}