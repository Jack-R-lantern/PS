#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<char>	v;
string			s;
int		L, C;
int		vowels, consonats;

bool	isVowels(char c) {
	return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

void	dfs(int start, int cnt) {
	if (cnt == L) {
		if (vowels >= 1 && consonats >= 2)
			cout << s << endl;
		return;
	}
	for (int i=start;i<=v.size() - L + cnt;i++) {
		s.push_back(v[i]);
			if (isVowels(v[i])) vowels++;
			else consonats++;
		dfs(i+1, cnt+1);
			if (isVowels(v[i])) vowels--;
			else consonats--;
		s.pop_back();
	}
}

int		main(void) {
	char	temp;
	cin >> L >> C;
	for (int i=0;i<C;i++) {
		cin >> temp;
		v.push_back(temp);
	}
	sort(v.begin(), v.end());
	dfs(0, 0);
	return (0);
}