#include <algorithm>
#include <cstdio>
#include <string>
using namespace std;

char	black[8][8];
int		MIN = 32;

void	init(char (*board)[8]) {
	for (int i=0;i<8;i++) {
		for (int j=0;j<8;j++) {
			if ((i+j) % 2 == 0)
				board[i][j] = 'B';
			else
				board[i][j] = 'W';
			}
		}
}

int		main(void) {
	int		M, N, b;
	scanf("%d%d", &N, &M);
	char	v[N][M];
	for (int i=0;i<N;i++)
		scanf("%s", v[i]);
	init(black);
	for (int i=0;i<=N-8;i++)
		for (int j=0;j<=M-8;j++) {
			b = 0;
			for (int x=i;x<i+8;x++)
				for (int y=j;y<j+8;y++) {
					if (v[x][y] != black[x-i][y-j])
						b++;
				}
			MIN = min(min(64 - b, b), MIN);
		}
	printf("%d\n", MIN);
	return (0);
}