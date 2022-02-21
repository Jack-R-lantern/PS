#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;

char	str[2001];

int		sol() {
	stack<char>		s;
	int i = 0, cnt = 0;

	while (str[i]) {
		if (str[i] == '{') {
			s.push(str[i]);
		}
		else {
			if (s.empty()) {
				s.push('{');
				cnt++;
			}
			else {
				s.pop();
			}
		}
		i++;
	}
	return cnt + s.size() / 2;
}

int		main(void) {
	int i=1;
	while(1) {
		scanf("%s", str);
		if (str[0] == '-')
			break;
		printf("%d. %d\n", i++, sol());
		memset(str, 0, sizeof(str));
	}
	return 0;
}