#include <iostream>
using namespace std;

int		GCD(int a, int b) {
	if (!(a % b))
		return b;
	return GCD(b, a%b);
}

int		lcm(int a, int b, int gcd) {
	return ((a * b) / gcd);
}

int		main(void) {
	int		a, b, gcd;

	cin >> a >> b;
	if (a < b) {
		a = a ^ b;
		b = a ^ b;
		a = a ^ b;
	}
	gcd = GCD(a, b);
	cout << gcd << endl;
	cout << lcm(a, b, gcd) << endl;
}