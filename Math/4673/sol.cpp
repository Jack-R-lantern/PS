#include <stdio.h>
using namespace std;

bool	visit[10001];

void	recur(int i) {
	if (i > 10000)
		return;
	visit[i] = true;
	recur(i + i / 1000 + (i % 1000) / 100 + (i % 100) / 10 + i % 10);
}

int		main(void) {
	for(int i=1;i<=10000;i++)
		if (!visit[i]) {
			recur(i);
			printf("%d\n", i);
		}
}