#include <iostream>
#include <unordered_map>
#include <cctype>
using namespace std;

int	main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	unordered_map<string, int>	strtoi;
	unordered_map<int, string>	itostr;
	int N, M;
	cin >> N >> M;
	for (int i=1;i<=N;i++) {
		string	temp;
		cin >> temp;
		strtoi[temp] = i;
		itostr[i] = temp;
	}
	for (int i=0;i<M;i++) {
		string temp;
		cin >> temp;
		if (isdigit(temp[0])) {
			cout << itostr[stoi(temp)] << "\n";
		}
		else
			cout << strtoi[temp] << "\n";
	}
	return 0;
}
