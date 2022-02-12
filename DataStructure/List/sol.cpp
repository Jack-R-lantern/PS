#include <iostream>
#include <list>
using namespace std;

int 	main(void) {
	list<int>	student;
	int 		len, ord;

	cin >> len;
	for (int i=1;i<=len;i++) {
		cin >> ord;
		if (ord == 0)
			student.push_back(i);
		else {
			list<int>::reverse_iterator rit = student.rbegin();
			for(int j=0;j<ord;j++)
				rit++;
			student.insert(rit.base(), i);
		}
	}

	for (int i: student)
		cout << i << " ";
	cout << endl;
	return 0;
}