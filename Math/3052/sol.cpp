#include <iostream>
using namespace std;

bool	visit[42];
int		arr[10];

int		main(void) {
	int total = 0;
	for (int i=0;i<10;i++) {
		cin >> arr[i];
		if (!visit[arr[i]%42]) {
			total++;
			visit[arr[i]%42] = true;
		}
	}
	cout << total << endl;
}