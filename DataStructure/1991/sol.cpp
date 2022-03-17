#include <iostream>
#include <vector>
using namespace std;

vector<pair<char, char>>	t[26];
int T;

void preorder(char ch) {
	cout << ch;
	if (t[ch-'A'][0].first != '.')
		preorder(t[ch-'A'][0].first);
	if (t[ch-'A'][0].second != '.')
		preorder(t[ch-'A'][0].second);
}

void inorder(char ch) {
	if (t[ch-'A'][0].first != '.')
		inorder(t[ch-'A'][0].first);
	cout << ch;
	if (t[ch-'A'][0].second != '.')
		inorder(t[ch-'A'][0].second);
}

void postorder(char ch) {
	if (t[ch-'A'][0].first != '.')
		postorder(t[ch-'A'][0].first);
	if (t[ch-'A'][0].second != '.')
		postorder(t[ch-'A'][0].second);
	cout <<  ch;
}

int	main(void) {
	cin >> T;
	for (int i=0;i<T;i++) {
		char node, left, right;
		cin >> node >> left >> right;
		t[node-'A'].push_back({left, right});
	}
	preorder('A');
	cout << endl;
	inorder('A');
	cout << endl;
	postorder('A');
	cout << endl;
	return 0;
}