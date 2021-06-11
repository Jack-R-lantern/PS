#include <iostream>
#include <string>
using namespace std;

int		main(void) {
	int		T, N;

	cin >> T;
	for(int i=0;i<T;i++) {
		string	str;
		cin >> N >> str;
		for(int j=0;j<str.length();j++)
			for(int k=0;k<N;k++)
				cout<<str[j];
		cout << endl;
	}
}