#include <cstdio>
#include <vector>
using namespace std;

int		main(void) {
	int		N, P;
	int		i, val;
	int		cnt = 0;
	scanf("%d %d", &N, &P);
	vector<vector<int>>	v(6);
	while (N--) {
		scanf("%d %d", &i, &val);
		if(v[i-1].empty()) {
			v[i-1].push_back(val);
			cnt++;
		}
		else {
			while (v[i-1].back() > val) {
				cnt++;
				v[i-1].pop_back();
			}
			if (v[i-1].back() < val) {
				v[i-1].push_back(val);
				cnt++;
			}
		}
	}
	printf("%d\n", cnt);
	return (0);
}