#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;

set<string>	name;
vector<string> result;

int	main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N, M;
	cin >> N >> M;
	for (int i=0;i<N;i++) {
		string temp;
		cin >> temp;
		name.insert(temp);
	}
	for (int i=0;i<M;i++) {
		string temp;
		cin >> temp;
		if (name.find(temp) != name.end())
			result.push_back(temp);
	}
	sort(result.begin(), result.end());
	cout << result.size() << endl;
	for (auto s : result)
		cout << s << '\n';
	return 0;
}