#include <iostream>
#include <cmath>
using namespace std;

int		N, M;
int		MAX;
int		card[100];
bool	visit[100];

void	dfs(int idx, int cnt) {
	if (cnt == 3) {
		int temp = 0;
		for (int i=0;i<N;++i) {
			if (visit[i]) {
				temp += card[i];
			}
		}
		if (temp <= M)
			MAX = max(MAX, temp);
		return;
	}

	if (idx == N)
		return;

	visit[idx] = true;
	dfs(idx + 1, cnt + 1);
	visit[idx] = false;
	dfs(idx + 1, cnt);
}

int		main(void) {
	cin >> N >> M;
	for (int i=0;i<N;++i)
		cin >> card[i];
	dfs(0, 0);
	cout << MAX << endl;
	return (0);
}