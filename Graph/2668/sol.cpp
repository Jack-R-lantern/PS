#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

vector<int>	v;
int		arry[101];
bool 	visit[101];

void 	dfs(int start, int cur) {
	if (visit[cur] == false) {
		visit[cur] = true;
		dfs(start, arry[cur]);
	}
	else if (start == cur) {
		v.push_back(start);
		return;
	}
}

int 	main(void) {
	int N;
	cin >> N;
	for (int i=1;i<=N;i++) {
		cin >> arry[i];
	}

	for (int i=1;i<=N;i++) {
		memset(visit, 0, 101);
		dfs(i, i);
	}

	cout << v.size() << endl;
	for (auto a : v)
		cout << a << endl;
}