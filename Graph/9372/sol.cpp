#include <iostream>
using namespace std;

int main(void) {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int T, N, M;

	cin >> T;
	while (T) {
		cin >> N >> M;
		for (int i=0;i<M;i++) {
			int a, b;
			cin >> a >> b;
		}
		cout << N - 1 << endl;
		T--;
	}
	return 0;
}
