#include <iostream>
#include <vector>
using namespace std;

vector<int>	graph[50];
int			N, M, root;

int		dfs(int n) {
	int	ret = 1;
	int child = 0;
	for (auto ch : graph[n]) {
		if (ch == M) continue;
		child += dfs(ch);
	}

	if (child) return child;
	else return ret;
}

int		main(void) {
	cin >> N;
	for (int i=0;i<N;++i) {
		int		parent;
		cin >> parent;
		if (parent == -1) root = i;
		else graph[parent].push_back(i);
	}
	cin >> M;
	if (root != M) cout << dfs(root) << endl;
	else cout << 0 << '\n';
	return (0);
}