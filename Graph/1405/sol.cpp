#include <iostream>
using namespace std;

bool visit[29][29];
int N;
double dir[4];
int	dx[]{1, -1, 0, 0};
int dy[]{0, 0, 1, -1};

double dfs(int x, int y, int depth) {
	double result = 0.0;

	if (depth == N)
		return 1.0;

	visit[x][y] = true;
	for (int i=0;i<4;i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (visit[nx][ny])
			continue;
		result = result	+ dir[i] * dfs(nx, ny, depth+1);
	}
	visit[x][y] = false;
	return result;
}

int 	main(void) {
	double result;
	int v;
	cin >> N;

	for (int i=0;i<4;i++) {
		cin >> v;
		dir[i] = v / 100.0;
	}
	result = dfs(14, 14, 0);
	cout.precision(10);
	cout << result << endl;
	return 0;
}