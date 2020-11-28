#include <cstdio>
#include <cctype>
#include <stack>
using namespace std;

stack<double>	s;
char			str[101];
int				map[26];

int		main(void) {
	int		N, i = 0;
	double	a = 0, b = 0;
	scanf("%d", &N);
	scanf("%s", str);
	while (i < N)
		scanf("%d", &map[i++]);
	i = 0;
	while (str[i]) {
		if(isalpha(str[i])) {
			s.push(map[str[i] - 'A']);
		}
		else {
			b = s.top();
			s.pop();
			a = s.top();
			s.pop();
			if(str[i] == '+')
				a += b;
			else if(str[i] == '*')
				a *= b;
			else if(str[i] == '-')
				a -= b;
			else if(str[i] == '/')
				a /= b;
			s.push(a);
		}
		i++;
	}
	printf("%.2f\n", s.top());
	return (0);
}