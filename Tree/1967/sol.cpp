#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<vector<pair<int, int>>>	tree;
bool visited[10001];
int N, MAX, P;

void dfs(int node, int len) {
	if (visited[node])
		return;
	
	visited[node] = true;
	if (MAX < len) {
		MAX = len;
		P = node;
	}

	for (int i=0;i<tree[node].size();i++) {
		dfs(tree[node][i].first, len + tree[node][i].second);
	}
}

int	main(void) {
	cin >> N;

	tree = vector<vector<pair<int, int>>>(N+1);
	while (N-->1) {
		int parent, child, weight;
		cin >> parent >> child >> weight;
		tree[parent].push_back({child, weight});
		tree[child].push_back({parent, weight});
	}
	dfs(1, 0);
	MAX = 0;
	memset(visited, false, sizeof(visited));
	dfs(P, 0);
	cout << MAX << endl;
	return 0;
}