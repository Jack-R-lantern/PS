#include <iostream>
#include <vector>
using namespace std;

vector<int>	v;

void postorder(int start, int end) {
	int idx;
	if (start >= end)
		return;
	for (idx=start+1;idx<end;idx++)
		if (v[start] < v[idx])
			break;

	postorder(start+1, idx);
	postorder(idx, end);
	cout << v[start] << '\n';
}

int	main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int num;
	while (cin >> num) {
		if (num == cin.eof())
			break;
		v.push_back(num);
	}
	postorder(0, v.size());
	return 0;
}