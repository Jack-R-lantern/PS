#include <cstdio>
#include <stack>
using namespace std;

char		PS[51];

void	sol(void) {
	stack<int>	s;
	int		i = 0;

	while (*(PS + i)) {
		if (*(PS + i) == '(')
			s.push('(');
		else {
			if (s.empty()) {
				printf("NO\n");
				return ;
			}
			s.pop();
		}
		i++;
	}
	if (s.empty())
		printf("YES\n");
	else
		printf("NO\n");
}

int     main(void) {
	int     T;

	scanf("%d", &T);
	while (T--) {
		scanf("%s", PS);
		sol();
	}
	return (0);
}