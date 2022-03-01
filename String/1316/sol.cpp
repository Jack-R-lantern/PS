#include <iostream>
#include <string>
#include <cstring>
using namespace std;

bool visited[26];

int	main(void) {
	string str;
	int N, idx, cnt = 0;
	cin >> N;
	while (N--) {
		cin >> str;
		idx = 0;
		for (;idx<str.length();idx++) {
			if (visited[str[idx] - 'a'])
				break;
			if (str[idx] != str[idx+1]) {
				visited[str[idx] - 'a'] = true;
			}
		}
		if (idx == str.length())
			cnt++;
		memset(visited, 0, sizeof(visited));
	}
	cout << cnt << endl;
	return 0;
}