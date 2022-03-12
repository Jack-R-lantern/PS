#include <iostream>
using namespace std;

int	N;
int result[11];

int	main(void) {
	int temp;

	cin >> N;
	for (int i=1;i<=N;i++) {
		cin >> temp;
		for (int j=1;j<=N;j++) {
			if (temp == 0 && result[j] == 0) {
				result[j] = i;
				break;
			}
			else if (result[j] == 0)
				temp--;
		}
	}
	for (int i=1;i<=N;i++)
		cout << result[i] << " ";
	cout << endl;
	return 0;
}