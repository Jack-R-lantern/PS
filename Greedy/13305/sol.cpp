#include <iostream>
#include <vector>
using namespace std;

vector<int>	road;
vector<int> cost;
long long total, MIN;
int N;

int	main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> N;
	road = vector<int>(N-1);
	cost = vector<int>(N);

	for (int i=0;i<N-1;i++)
		cin >> road[i];
	for (int i=0;i<N;i++)
		cin >> cost[i];

	total = (long long)cost[0] * (long long)road[0];
	MIN = cost[0];
	for (int i=1;i<N-1;i++) {
		MIN = MIN < cost[i] ? MIN : cost[i];
		total += MIN * (long long)road[i];
	}
	cout << total << endl;
	return 0;
}