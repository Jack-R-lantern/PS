#include <iostream>
using namespace std;

int		N;
int		seq[100000];
int		MAX = 1;

int		main(void) {
	int		temp1 = 1, temp2 = 1;
	cin >> N;
	for (int i=0;i<N;++i)
		cin >> seq[i];
	for (int i=0;i<N-1;++i) {
		if (seq[i] <= seq[i+1]) temp1++;
		else temp1 = 1;
		if (seq[i] >= seq[i+1]) temp2++;
		else temp2 = 1;

		int result = max(temp1, temp2);
		MAX = max(MAX, result);
	}
	cout << MAX << endl;
	return (0);
}