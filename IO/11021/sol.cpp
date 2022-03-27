#include <iostream>
using namespace std;

int T;

int	main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> T;
	for (int i=1;i<=T;i++) {
		int a, b;
		cin >> a >> b;
		cout << "Case #"<<i<<": "<< a + b << "\n";
	}
	return 0;
}