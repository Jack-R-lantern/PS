#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

vector<int>	v(9);
vector<int>	result(7);
const int	DEPTH = 6;

void	combination(int s, int e, int depth) {
	if (depth < 0) {
		int total = 0;
		for(int i=0;i<7;i++)
			total += result[i];
		if (total == 100) {
			sort(result.begin(), result.end());
			for (auto &p : result)
				printf("%d\n", p);
			exit(0);
		}
		else
			return;
	}
	for (int i = s;i < e - depth;i++) {
		result[DEPTH - depth] = v[i];
		combination(i + 1, e, depth - 1);
	}
}

int		main(void) {
	for(int i=0;i<9;i++)
		scanf("%d", &v[i]);
	combination(0, v.size(), DEPTH);
	return (0);
}