#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

char	s[8];
int		N, num;

int		main(void) {
	int total = 0;

	scanf("%s", s);
	N = strlen(s);
	num = atoi(s);
	for (int i=num-9*N;i<=num;i++) {
		total = i;
		sprintf(s, "%d", i);
		for (int j=0;j<strlen(s);j++)
			total += s[j] - '0';
		if (total == num) {
			printf("%d\n", i);
			return (0);
		}
	}
	printf("%d\n", 0);
	return (0);
}