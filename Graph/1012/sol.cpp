#include <algorithm>
#include <iostream>
#include <cstring>
using namespace std;

bool	matrix[50][50];
bool	visit[50][50];
int		dx[]{0, 0, -1, 1};
int		dy[]{1, -1, 0, 0};
int		M, N, K, X, Y;

bool	validate(int x, int y) {
	return (min(x,y) >= 0 && x < M && y < N);
}

void	search(int m, int n) {
	visit[m][n] = true;
	for (char dir = 0;dir < 4;dir++) {
		int	nm = m + dx[dir];
		int nn = n + dy[dir];
		if (validate(nm, nn) && !visit[nm][nn] && matrix[nm][nn])
			search(nm, nn);
	}
}

int		main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int		T;

	cin >> T;
	while (T--) {
		int total = 0;
		cin >> M >> N >> K;
		while (K--) {
			cin >> X >> Y;
			matrix[X][Y] = 1;
		}
		for (int i = 0;i < M;i++)
			for (int j = 0;j < N;j++)
				if(!visit[i][j] && matrix[i][j]) {
					search(i, j);
					total++;
				}
		cout << total << endl;
		memset(matrix, 0, sizeof(matrix));
		memset(visit, 0, sizeof(visit));
	}
	return (0);
}