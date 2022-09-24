#include <iostream>
using namespace std;

int N;

void
print(int src, int dst)
{
	cout << src << ' ' << dst << '\n';
}

void
hanoi(int n, int src, int dst, int sub) {
	if (n == 1)
		print(src, dst);
	else {
		hanoi(n-1, src, sub, dst);
		print(src, dst);
		hanoi(n-1, sub, dst, src);
	}
}

int	main(void) {
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr);

	cin >> N;
	cout << (1<<N) - 1 << "\n";
	hanoi(N, 1, 3, 2);
	return 0;
}