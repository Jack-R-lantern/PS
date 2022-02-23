#include <iostream>
#include <string>
#include <stack>
#include <cctype>
using namespace std;

stack<char>	op;

int		main(void) {
	string input, result;
	cin >> input;

	for (auto c : input) {
		if (isalpha(c)) {
			result += c;
		}
		else if (c == '(')
			op. push(c);
		else if (c == ')') {
			while (op.top() != '(') {
				result += op.top();
				op.pop();
			}
			op.pop();
		}
		else if (c == '*' || c =='/') {
			while (!op.empty() && (op.top() == '*' || op.top() == '/')) {
				result += op.top();
				op.pop();
			}
			op.push(c);
		}
		else if (c == '+' || c == '-') {
			while (!op.empty() && op.top() != '(') {
				result += op.top();
				op.pop();
			}
			op.push(c);
		}
	}
	while (!op.empty()) {
		result += op.top();
		op.pop();
	}
	cout << result << endl;
	return 0;
}

// #include <cstdio>
// using namespace std;

// char input[101], result[101], op[101];

// int		main(void) {
// 	int i = 0, ri = 0, oi = -1;
// 	scanf("%s", input);

// 	while (input[i]) {
// 		if (input[i] >= 'A' && input[i] <= 'Z')
// 			result[ri++] = input[i];
// 		else if (input[i] == '(')
// 			op[++oi] = input[i];
// 		else if (input[i] == ')') {
// 			while (op[oi] != '(') {
// 				result[ri++] = op[oi];
// 				op[oi--] = 0;
// 			}
// 			op[oi--] = 0;
// 		}
// 		else if (input[i] == '*' || input[i] == '/') {
// 			while (oi != -1 && (op[oi] == '*' || op[oi] == '/')) {
// 				result[ri++] = op[oi];
// 				op[oi--] = 0;
// 			}
// 			op[++oi] = input[i];
// 		}
// 		else {
// 			while (oi != -1 && op[oi] != '(') {
// 				result[ri++] = op[oi];
// 				op[oi--] = 0;
// 			}
// 			op[++oi] = input[i];
// 		}
// 		i++;
// 	}
// 	while (oi != -1)
// 		result[ri++] = op[oi--];
// 	printf("%s\n", result);
// 	return 0;
// }