#include <cstdio>
#include <list>
using namespace std;

char	str[1000001];

int		main(void) {
	int		N;
	int		i, j;

	scanf("%d", &N);
	while (N--) {
		scanf("%s", str);
		i = 0;
		list<char>				lst;
		list<char>::iterator	iter = lst.begin();
		while (*(str + i)) {
			if (*(str + i) == '<') {
				if (iter != lst.begin())
					iter--;
			}
			else if (*(str + i) == '>') {
				if (iter != lst.end())
					iter++;
			}
			else if (*(str + i) == '-') {
				if (iter != lst.begin())
					lst.erase((--iter)++);
			}
			else
				lst.insert(iter, str[i]);
			i++;
		}
		for(auto c : lst)
			printf("%c", c);
		printf("\n");
	}
	return (0);
}