#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct compare_pair {
	bool operator()(const pair<int, int> &__x, const pair<int, int> &__y) {
		if (__x.first > __y.first)
			return true;
		else if (__x.first == __y.first)
			return __x.second > __y.second;
		else
			return false;
	};
};

priority_queue<pair<int, int>, vector<pair<int, int>>, compare_pair>	pq;
int N;

int	main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	while (N--) {
		int input, num, sign;
		
		cin >> input;
		if (input == 0) {
			if (pq.empty())
				cout << "0\n";
			else {
				num = pq.top().first;
				sign = pq.top().second;
				cout << num * sign << "\n";
				pq.pop();
			}
		}
		else {
			if (input < 0)
				pq.push({input * -1, -1});
			else
				pq.push({input, 1});
		}
	}
	return 0;
}