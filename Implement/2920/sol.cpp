#include <iostream>
using namespace std;

int	arr[8];
int	span[7];

int		main(void) {
	int max=-1, min=1;
	for(int i=0;i<8;i++)
		cin >> arr[i];
	for (int i=0;i<7;i++) {
		span[i] = arr[i] - arr[i+1];
		if (span[i] > max)
			max = span[i];
		else if (span[i] < min)
			min = span[i];
	}
	if (max == min && max == -1)
		cout << "ascending" << endl;
	else if (max == min && max == 1)
		cout << "descending" << endl;
	else
		cout << "mixed" << endl;
}