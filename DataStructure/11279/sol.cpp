#include <iostream>
#include <queue>
using namespace std;

int	main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;
	priority_queue<int>	pq;
	while (N--) {
		int cmd;
		cin >> cmd;
		if (cmd == 0) {
			if (pq.empty())
				cout << 0 << "\n";
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else
			pq.push(cmd);
	}
	return 0;
}