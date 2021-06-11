#include <iostream>
#include <string>
using namespace std;

int	visit[10];
int	arr[3];

int	main(void) {
	string str;
	for(int i=0;i<3;i++)
		cin>>arr[i];
	str = to_string(arr[0] * arr[1] * arr[2]);
	for(int i=0;i<str.length();i++)
		visit[str[i] - '0']++;
	for(int i=0;i<10;i++)
		cout << visit[i] << endl;
}