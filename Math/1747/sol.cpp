#include <iostream>
#include <string>
using namespace std;

#define MAX	1004000

bool prime[MAX], flag;
int N;

int	main(void) {
	prime[1] = true;
	cin >> N;

	for(int i=2;i<MAX;i++) {
		if (prime[i] == false) {
			for (int j=2;i*j<MAX;j++) {
				prime[i*j] = true;
			}
		}
	}

	for (int i=N;i<MAX;i++) {
		flag = true;
		if (prime[i] == false) {
			string str = to_string(i);
			for (int j=0;j<str.size()/2;j++) {
				if (str[j] != str[str.size() - j -1])
					flag = false;
			}
			if (flag) {
				cout << i << endl;
				break;
			}
		}
	}
	return 0;
}