#include <iostream>
#include <vector>
#include <list>
using namespace std;

vector<pair<int, int>>	info;
vector<vector<int>>		tree;
list<int>				pa, pb;

void dfs(int a, list<int>& root) {
	root.push_back(a);
	if (tree[a].empty())
		return;
	dfs(tree[a].front(), root);
}

int		main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T, N;
	cin >> T;
	while (T) {
		int a, b;
		cin >> N;
		tree.assign(N+1, vector<int>());
		for (int i=0;i<N-1;i++) {
			cin >> a >> b;
			tree[b].push_back(a);
		}
		cin >> a >> b;
		dfs(a, pa);
		dfs(b, pb);
		while (pa.size() != pb.size()) {
			if (pa.size() > pb.size())
				pa.pop_front();
			else
				pb.pop_front();
		}
		while (pa.front() != pb.front()) {
			pa.pop_front();
			pb.pop_front();
		}
		cout << pa.front() << "\n";
		tree.clear();
		pa.clear();
		pb.clear();
		T--;
	}
	return 0;
}
/*
1
16
1 14
8 5
10 16
5 9
4 6
8 4
4 10
1 13
6 15
10 11
6 7
10 2
16 3
8 1
16 12
8 7
*/