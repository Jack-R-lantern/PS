#include <iostream>
#include <cmath>
using namespace std;

int		N, total;
int		temp[100];


int		main(void) {
	cin >> N;
	total = N;
	for (int i=0;i<N;++i) {
		cin >> temp[i];
		if (temp[i] == 1)
			total--;
		for (int j=2;j<=sqrt(temp[i]);++j) {
			if (temp[i] % j == 0) {
				total--;
				break;
			}
		}
	}
	cout << total << endl;
	return (0);
}