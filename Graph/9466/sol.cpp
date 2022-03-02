#include <iostream>
#include <cstring>
using namespace std;

#define MAX 100001

int	 arr[MAX], cnt;
bool visited[MAX], check[MAX];

void dfs(int idx) {
	visited[idx] = true;
	int next = arr[idx];
	if (visited[next] == false)
		dfs(next);
	else if (check[next] == false) {
		for (int i = next;i!=idx;i=arr[i])
			cnt++;
		cnt++;
	}
	check[idx] = true;
}

int	main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int n;
		cnt = 0;
		cin >> n;
		for (int i=1;i<=n;i++)
			cin >> arr[i];

		for (int i=1;i<=n;i++) {
			if (visited[i] == false)
				dfs(i);
		}
		cout << n - cnt << "\n";
		memset(check, 0, sizeof(check));
		memset(visited, 0, sizeof(visited));
	}
	return 0;
}