#include <iostream>
#include <vector>
using namespace std;

int C;

int	main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> C;
	while (C--) {
		int N, avg = 0, cnt = 0;
		cin >> N;
		vector<int>	v(N);
		for (int i=0;i<N;i++) {
			cin >> v[i];
			avg += v[i];
		}
		avg = avg / N;
		for (int i=0;i<N;i++) {
			if (avg < v[i])
				cnt++;
		}
		float e = cnt / (float)N;
		cout << fixed;
		cout.precision(3);
		cout << e*100 << "%\n";
	}
	return 0;
}