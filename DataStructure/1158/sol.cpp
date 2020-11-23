#include <cstdio>
#include <queue>
using namespace std;

queue<int>	q;

int     main(void) {
	int		n, k;

	scanf("%d %d", &n, &k);
	for(int i=1;i<=n;i++)
		q.push(i);
	printf("<");
	while(!q.empty()) {
		for(int i=1;i<k;i++) {
			q.push(q.front());
			q.pop();
		}
		printf("%d", q.front());
		q.pop();
		if(q.size() >= 1)
			printf(", ");
	}
	printf(">\n");
	return (0);
}