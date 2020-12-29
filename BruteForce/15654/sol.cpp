#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

vector<pair<int, bool>>	v;
int		a[8];
int		M, N;

void	permutation(int depth) {
	if (depth == 0) {
		for (int i=0;i<M;i++)
			printf("%d ",a[i]);
		printf("\n");
		return ;
	}
	for (int i=0;i<v.size();i++) {
		if (v[i].second) continue;
		a[M - depth] = v[i].first;
		v[i].second = true;
		permutation(depth - 1);
		v[i].second = false;
	}
}

int		main(void) {
	int val;

	scanf("%d%d", &N, &M);
	for (int i=0;i<N;i++) {
		scanf("%d", &val);
		v.push_back({val, false});
	}
	sort(v.begin(), v.end());
	permutation(M);
	return (0);
}