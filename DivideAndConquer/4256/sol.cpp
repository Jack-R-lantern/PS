#include <iostream>
#include <vector>
using namespace std;

vector<int>	pre, in;
int T, N, root;

void post(int start, int end, int pos) {
	for (int i=start;i<end;i++) {
		if (pre[pos] == in[i]) {
			post(start, i, pos + 1);
			post(i+1, end, pos + 1 + i - start);
			cout << pre[pos] << ' ';
		}
	}
}

int	main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> T;
	while (T--) {
		cin >> N;
		pre = vector<int>(N);
		in = vector<int>(N);

		for (int i=0;i<N;i++)
			cin >> pre[i];
		for (int i=0;i<N;i++)
			cin >> in[i];
		post(0, N, 0);
		cout << endl;
	}
	return 0;
}