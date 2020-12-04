#include <cstdio>
#include <vector>
using namespace std;

char	alpha[26];

int		main(void) {
	int		N, K, S, i = 0;
	char	c;
	scanf("%d %d", &N, &K);
	vector<char>	v(N, '?');
	while (K--) {
		scanf("%d %c", &S, &c);
		if (alpha[c -'A'] != 0) {
			printf("!\n");
			return (0);
		}
		alpha[c - 'A']++;
		i += S;
		i = i >= 8 ? i - 8 : i;
		if (v[i] != '?' && v[i] != c) {
			printf("!\n");
			return (0);
		}
		v[i] = c;
	}
	while (N--) {
		printf("%c", v[i]);
		i--;
		if (i < 0)
			i += v.size();
	}
	printf("\n");
	return (0);
}