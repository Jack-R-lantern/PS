#include <iostream>
#include <stack>
using namespace std;

char	p[31];

int		sol() {
	stack<char> s;
	int	i = 0, temp = 1, total = 0;

	while (p[i]) {
		if (p[i] == '(' || p[i] == '[') {
			s.push(p[i]);
			if (p[i] == '(')
				temp *= 2;
			else
				temp *= 3;
		}
		else {
			if (s.empty() || (p[i] == ')') && s.top() != '(')
				return 0;
			if (s.empty() || (p[i] == ']') && s.top() != '[')
				return 0;
			if (p[i] == ')') {
				if (p[i - 1] == '(')
					total += temp;
				temp /= 2;
			}
			else {
				if (p[i - 1] == '[')
					total += temp;
				temp /= 3;
			}
			s.pop();
		}
		i++;
	}
	return s.empty() ? total : 0;
}

int		main(void) {
	scanf("%s", p);
	printf("%d\n", sol());
	return 0;
}