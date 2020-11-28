#include <cstdio>
#include <stack>
using namespace std;

char str[100001];

int main(void) {
	int N, valid;
	int idx;

	valid = 0;
	scanf("%d", &N);
	while (N--) {
		scanf("%s", str);
		idx = 0;
		stack<char> s;
		while (*(str + idx)) {
			if(!s.empty() && s.top() == str[idx])
				s.pop();
			else
				s.push(str[idx]);
			idx++;
		}
		if(s.empty())
			valid++;
	}
	printf("%d\n", valid);
	return (0);
}