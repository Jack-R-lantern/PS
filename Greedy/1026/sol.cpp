#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

int	N;
list<int>	a, b;

int 	main(void) {
	int sum = 0;
	cin >> N;
	for (int i=0;i<N;i++) {
		int temp;
		cin >> temp;
		a.push_back(temp);
	}
	for (int i=0;i<N;i++) {
		int temp;
		cin >> temp;
		b.push_back(temp);
	}
	for (int i=0;i<N;i++) {
		list<int>::iterator min_it, max_it;
		min_it = min_element(a.begin(), a.end());
		max_it = max_element(b.begin(), b.end());
		sum += *min_it * *max_it;
		a.erase(min_it);
		b.erase(max_it);
	}
	cout << sum << endl;
}