#include <algorithm>
#include <cstdio>
using namespace std;

int		line[14];
int		total, N;

void	BackTracking(int s) {
	bool	flag;
	if (s == N) {
		total++;
		return ;
	}
	for (int i = 0;i < N;i++) {
		flag = true;
		for (int j = 0;j < s;j++) {
			if (line[j] == i || abs(line[j] - i) == abs(s - j)) {
				flag = false;
				break;
			}
		}
		if (flag) {
			line[s] = i;
			BackTracking(s + 1);
		}
	}
}

int		main(void) {
	scanf("%d", &N);
	BackTracking(0);
	printf("%d\n", total);
	return (0);
}