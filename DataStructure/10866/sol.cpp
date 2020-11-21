#include <cstdio>
#include <cstring>
#include <deque>
using namespace std;

char    cmd[11];

int     main(void) {
    deque<int>  dq;
    int         cnt, val;

    scanf("%d", &cnt);
    while (cnt--) {
        scanf("%s", cmd);
        if (!strcmp(cmd, "push_front")) {
            scanf("%d", &val);
            dq.push_front(val);
        }
        else if (!strcmp(cmd, "push_back")) {
            scanf("%d", &val);
            dq.push_back(val);
        }
        else if (!strcmp(cmd, "pop_front")) {
            if (dq.empty())
                printf("-1\n");
            else {
                printf("%d\n",dq.front());
                dq.pop_front();
            }
        }
        else if (!strcmp(cmd, "pop_back")) {
            if (dq.empty())
                printf("-1\n");
            else {
                printf("%d\n",dq.back());
                dq.pop_back();
            }
        }
        else if (!strcmp(cmd, "size"))
            printf("%lu\n", dq.size());
        else if (!strcmp(cmd, "empty"))
            printf("%d\n", dq.empty());
        else if (!strcmp(cmd, "front")) {
            if (dq.empty())
                printf("-1\n");
            else
                printf("%d\n",dq.front());
        }
        else if (!strcmp(cmd, "back")) {
           if (dq.empty())
                printf("-1\n");
            else
                printf("%d\n",dq.back()); 
        }
    }
    return (0);
}