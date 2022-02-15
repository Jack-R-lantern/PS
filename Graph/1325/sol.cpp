#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

int 					N, M;
vector<vector<int>>		v(10001);
vector<int>				result;
queue<int>				q;
bool 					visit[10001];

int		bfs(int idx) {
	int sum = 1;
	visit[idx] = true;
	q.push(idx);
	while (!q.empty()) {
		idx = q.front();
		q.pop();
		for (int i=0;i<v[idx].size();i++) {
			if (visit[v[idx][i]])
				continue;
			q.push(v[idx][i]);
			visit[v[idx][i]] = true;
			sum++;
		}
	}
	return sum;
}

int		dfs(int idx) {
	int sum = 1;
	visit[idx] = true;
	for (int i=0;i<v[idx].size();i++) {
		if (visit[v[idx][i]] == false) {
			visit[v[idx][i]] = true;
			sum += dfs(v[idx][i]);
		}
	}
	return sum;
}


int 	main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;
	while (M) {
		int a, b;
		cin >> a >> b;
		v[b].push_back(a);
		M--;
	}

	int MAX = 0;
	for (int i=1;i<=N;i++) {
		int temp;
		memset(visit, 0, sizeof(visit));
		temp = dfs(i);
		if (MAX < temp) {
			result.clear();
			result.push_back(i);
			MAX = temp;
		}
		else if (MAX == temp) {
			result.push_back(i);
		}
	}
	for (auto a : result)
		cout << a << " ";
}