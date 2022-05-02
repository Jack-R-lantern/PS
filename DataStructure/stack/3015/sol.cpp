#include <iostream>
#include <stack>
using namespace std;

/*
 *	1. stack.top < input
 *		pop한 갯수만큼 +;
 *	2. stack.top == input
 *
 *	3. stack.top > input
 *		push 하면서 +;
 */

stack<pair<int, int>>	s;
long long				result;
int N;

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N;

	for (int i=0;i<N;i++) {
		int height, cnt = 1;

		cin >> height;
		while (!s.empty() && s.top().first < height) {
			result += s.top().second;
			s.pop();
		}

		if (!s.empty()) {
			if (s.top().first == height) {
				result += s.top().second;
				cnt = s.top().second + 1;
				if (s.size() > 1)
					++result;
				s.pop();
			} else {
				++result;
			}
		}
		s.push({height, cnt});
	}
	cout << result << endl;
	return 0;
}