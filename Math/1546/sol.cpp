#include <iostream>
#include <vector>
using namespace std;

int		main(void) {
	float	avg = 0, max = 0;
	int 	N;

	cin >> N;
	vector<int>		input(N);
	vector<float>	output(N);
	for(int i=0;i<N;i++) {
		cin >> input[i];
		if (input[i] > max)
			max = input[i];
	}
	for(int i=0;i<N;i++) {
		output[i] = (input[i] / max) * 100;
		avg += output[i];
	}
	cout << avg / N << endl;
}