#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string>	v;
int R, C, result;
int dx[]{-1, 0, 1};
int dy[]{1, 1, 1};
int dp[10001][501];

bool range(int x, int y) {
	return (x >= 0 && x < R && y >= 0 && y < C);
}

bool dfs(int x, int y) {
	v[x][y] = 'x';
	if (y == C-1) {
		result++;
		return true;
	}
	for (int i=0;i<3;i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (range(nx, ny) && v[nx][ny] == '.')
			if (dfs(nx, ny))
				return true;
	}
	return false;
}

int	main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> R >> C;
	v = vector<string>(R);
	for(int i=0;i<R;i++)
		cin >> v[i];
	for (int i=0;i<v.size();i++)
		dfs(i, 0);
	cout << result << endl;
	return 0;
}