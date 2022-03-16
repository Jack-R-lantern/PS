#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;

int	main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	priority_queue<int, vector<int>, greater<int>>	pq;
	
	cin >> N;
	while (N--) {
		int value;

		cin >> value;
		if (value == 0) {
			if (pq.empty())
				cout << "0\n";
			else {
				cout << pq.top() << "\n";
				pq.pop();
			}
		}
		else
			pq.push(value);
	}
	return 0;
}
