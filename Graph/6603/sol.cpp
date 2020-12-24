#include <cstdio>
#include <cctype>
using namespace std;

const int DEPTH = 5;
int		tab[12];
int		set[6];

void	combination(int s, int e, int depth) {
	if (depth < 0) {
		for (int i = 0;i <= DEPTH;i++) {
			if (i  != DEPTH)
				printf("%d ", set[i]);
			else
				printf("%d", set[i]);
		}
		printf("\n");
		return ;
	}
	for (int i = s;i <= e - depth; i++) {
		set[DEPTH - depth] = tab[i];
		combination(i + 1, e, depth - 1);
	}
}

int		main(void) {
	char	ch;
	int		k;

	while (1) {
		k = 0;
		while ((ch = getchar()) && isdigit(ch))
			k = k * 10 + ch - '0';
		if (k == 0)
			break;
		for (int i = 0;i < k;i++)
			scanf("%d", &tab[i]);
		getchar();
		combination(0, k - 1, DEPTH);
		printf("\n");
	}
	return (0);
}