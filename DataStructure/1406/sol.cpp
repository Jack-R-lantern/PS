#include <cstdio>
#include <list>
using namespace std;

char	str[100001];

list<char>				dq;
list<char>::iterator	iter;
int		main(void) {
	char	CMD, c;
	int		M, i = 0;

	scanf("%s", str);
	while (*(str + i)) {
		dq.push_back(*(str + i));
		i++;
	}
	scanf ("%d", &M);
	iter = dq.end();
	while (M--) {
		scanf(" %c", &CMD);
		if (CMD == 'L') {
			if (iter != dq.begin())
				iter--;
		}
		else if (CMD == 'D') {
			if (iter != dq.end())
				iter++;
		}
		else if (CMD == 'B') {
			if (iter != dq.begin())
				dq.erase((--iter)++);
		}
		else if (CMD == 'P') {
			scanf(" %c", &c);
			dq.insert(iter, c);
		}
	}
	for (auto ch : dq)
		printf("%c", ch);
	printf("\n");
	return (0);
}