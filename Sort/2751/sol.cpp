#include <iostream>
#include <algorithm>
using namespace std;

int		main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int N;
	cin >> N;

	int		a[N];
	for(int i=0;i<N;i++)
		cin >> a[i];
	sort(a, a+N);
	for (int i=0;i<N;i++)
		cout <<a[i] << '\n';
}