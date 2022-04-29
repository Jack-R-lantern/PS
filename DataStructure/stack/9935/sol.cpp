#include <iostream>
#include <string>
using namespace std;

string str, ans, bomb;

int main(void) {
	int top = -1, bomb_size;

	cin >> str;
	cin >> bomb;

	bomb_size = bomb.size();
	for (int i=0;i<str.size();++i) {
		ans.push_back(str[i]);

		if (ans.size() >= bomb_size &&
			ans.compare(ans.size() - bomb_size, bomb_size, bomb) == 0) {
			for (int i=0;i<bomb_size;i++)
				ans.pop_back();
		}
	}

	if (ans.size() == 0)
		cout << "FRULA" << endl;
	else
		cout << ans << endl;
	return 0;
}