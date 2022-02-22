#include <algorithm>
#include <cstdio>
using namespace std;

char grid[21][21];
bool alphabet[26];
int dx[]{0, 0, 1, -1};
int dy[]{1, -1, 0, 0};
int R, C, MAX;

bool range(int x, int y) {
	return (x >= 0 && x < R && y >= 0 && y < C);
}

void dfs(int x, int y, int depth) {
	MAX = max(MAX, depth);

	for (int i=0;i<4;i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (range(nx, ny)) {
			if (!alphabet[grid[nx][ny] - 'A']) {
				alphabet[grid[nx][ny] - 'A'] = true;
				dfs(nx, ny, depth + 1);
				alphabet[grid[nx][ny] - 'A'] = false;
			}
		}
	}
}

int	main(void) {
	scanf("%d%d", &R, &C);
	for (int i=0;i<R;i++)
		scanf("%s", grid[i]);
	alphabet[grid[0][0] - 'A'] = true;
	dfs(0, 0, 1);
	printf("%d\n", MAX);
	return 0;
}