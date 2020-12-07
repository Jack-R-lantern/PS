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
		i = (i + S) % N;
		if (v[i] == '?' && !alpha[c - 'A']) {
			alpha[c - 'A']++;
			v[i] = c;
		}
		else if (v[i] == c && alpha[c - 'A'])
			continue;
		else{
			printf("!\n");
			return (0);
		}
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