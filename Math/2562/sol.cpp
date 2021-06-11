#include <iostream>
using namespace std;

unsigned int	arr[9];

int		main(void) {
	int max=0, idx;
	for(int i=0;i<9;i++) {
		cin >> arr[i];
		if (arr[i] > max) {
			max = arr[i];
			idx = i+1;
		}
	}
	cout << max << '\n' << idx << endl;
}