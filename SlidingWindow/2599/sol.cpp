#include <iostream>
#include <algorithm>
using namespace std;

int N, K, MAX;
int temperature[100001];

int	main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int front, back, temp;
	cin >> N >> K;
	for (int i=1;i<=N;i++)
		cin >> temperature[i];
	front = temperature[1];
	back = temperature[K];
	for (int i=1;i<=K;i++)
		MAX += temperature[i];
	temp = MAX;
	for (int i=K+1;i<=N;i++) {
		back = temperature[i];
		temp = temp - front + back;
		MAX = max(MAX, temp);
		front = temperature[i-K+1];
	}
	cout << MAX << endl;
	return 0;
}