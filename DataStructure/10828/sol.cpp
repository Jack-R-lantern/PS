#include <cstdio>
#include <cstring>
using namespace std;

int		stack[10000];
int		idx = -1;
char	cmd[6];

int     main(void) {

	int     cnt, val;

	scanf("%d", &cnt);
	while (cnt--) {
		scanf("%s", cmd);
		if (!strcmp(cmd, "push")) {
			scanf("%d", &val);
			stack[++idx] = val;
		}
		else if (!strcmp(cmd, "pop")) {
			if (idx == -1)
				printf("-1\n");
			else {
				printf("%d\n",stack[idx--]);
			}
		}
		else if (!strcmp(cmd, "size"))
			printf("%d\n", idx + 1);
		else if (!strcmp(cmd, "empty"))
			printf("%d\n", (idx == -1 ? 1 : 0));
		else if (!strcmp(cmd, "top"))
			printf("%d\n", (idx == -1 ? -1 : stack[idx]));
	}
	return (0);
}
