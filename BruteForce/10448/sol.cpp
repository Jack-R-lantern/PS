#include <cstdio>
#include <vector>
using namespace std;

int		main(void) {
	vector<int>	v;
	bool	flag = true;
	int		T = 0, K = 0;

	while (K < 45) {
		K++;
		T = (K * (K+1)) / 2;
		v.push_back(T);
	}
	scanf("%d", &T);
	while (T--) {
		flag = true;
		scanf("%d", &K);
		for (int i=0;i<v.size();i++) {
			for (int j=i;j<v.size();j++) {
				for (int k=j;k<v.size();k++) {
					if (K == v[i] + v[j] + v[k]) {
						flag = false;
						printf("1\n");
						break;
					}
				}
				if (!flag)
					break;
			}
			if (!flag)
				break;
		}
		if (flag)
			printf("0\n");
	}
	return (0);
}