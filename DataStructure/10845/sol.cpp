#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

char    cmd[6];

int     main(void) {
	queue<int> q;
	int     cnt, val;

	scanf("%d", &cnt);
	while (cnt--) {
		scanf("%s", cmd);
		if(!strcmp(cmd, "push")) {
			scanf("%d", &val);
			q.push(val);
		}
		else if(!strcmp(cmd, "pop")) {
			if (q.empty())
				printf("-1\n");
			else {
				printf("%d\n", q.front());
				q.pop();
			}
		} else if(!strcmp(cmd, "size"))
			printf("%lu\n", q.size());
		else if(!strcmp(cmd, "empty")) {
			if (q.empty())
				printf("1\n");
			else
				printf("0\n");
		}
		else if(!strcmp(cmd, "front")) {
			if (q.empty())
				printf("-1\n");
			else
				printf("%d\n", q.front());
		}
		else if(!strcmp(cmd, "back"))
			if (q.empty())
				printf("-1\n");
			else
				printf("%d\n", q.back());
	}
}