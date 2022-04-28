#include <iostream>
#include <string>
using namespace std;

string str, result;
int N, K;

int	main(void) {
	ios_base::sync_with_stdio(false);
	cout.tie(nullptr);

	cin >> N >> K;
	cin >> str;

	for (int i=0;i<str.length();i++) {
		while (K && !result.empty() && result.back() < str[i]) {
			result.pop_back();
			K--;
		}
		result.push_back(str[i]);
	}
	for (int i=0;i<result.size()-K;i++)
		cout << result[i];
	cout << endl;
	return 0;
}