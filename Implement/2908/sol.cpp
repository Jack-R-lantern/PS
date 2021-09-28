#include <iostream>
#include <cmath>
using namespace std;

int		main(void) {
	int		N1, N2;
	int		temp1 = 0, temp2 = 0;
	cin >> N1 >> N2;
	for (int i=0;i<3;++i) {
		temp1 += (N1 / (int)pow(10, 2-i)) * (int)pow(10, i);
		temp2 += (N2 / (int)pow(10, 2-i)) * (int)pow(10, i);
		N1 %= (int)pow(10, 2-i);
		N2 %= (int)pow(10, 2-i);
	}
	if (temp1 > temp2)
		cout << temp1 << endl;
	else
		cout << temp2 << endl;
	return (0);
}