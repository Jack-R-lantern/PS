#include <iostream>
#include <set>
using namespace std;

int T, K;

int	main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> T;
	while (T--) {
		multiset<int>	ms;
		char ch;
		int value;

		cin >> K;
		for (int i=0;i<K;i++) {
			cin >> ch >> value;
			if (ch == 'I')
				ms.insert(value);
			else {
				if (ms.empty())
					continue;
				if (value == 1)
					ms.erase(--ms.end());
				else {
					ms.erase(ms.begin());
				}
			}
		}
		if (ms.empty())
			cout << "EMPTY\n";
		else
			cout << *(--ms.end()) << " " << *ms.begin() << "\n";
	}
	return 0;
}