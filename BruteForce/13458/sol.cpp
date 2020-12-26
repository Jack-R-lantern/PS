#include <iostream>
#include <vector>
using namespace std;

int		N, B, C;

void	init(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
}

int		main(void) {
	init();

	unsigned long long	total = 0;
	cin >> N;
	vector<int>	v(N);
	for (int i = 0;i<N;i++)
		cin >> v[i];
	cin >> B >> C;
	total = N;
	for (int i = 0;i<N;i++) {
		v[i] -= B;
		if (v[i] > 0) {
			if ((v[i] % C))
				total += (v[i] / C) + 1;
			else
				total += (v[i] / C);
		}
	}
	cout << total << '\n';
}