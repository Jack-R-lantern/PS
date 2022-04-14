#include <iostream>
#include <vector>
using namespace std;

int N, M;

int	main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;
	vector<int> A(N);
	vector<int> B(M);
	vector<int>	R(N+M);

	for (int i=0;i<N;i++)
		cin >> A[i];
	for (int i=0;i<M;i++)
		cin >> B[i];

	vector<int>::iterator	iterA, iterB, iterR;
	iterA = A.begin();
	iterB = B.begin();
	iterR = R.begin();
	while (iterA != A.end() && iterB != B.end()) {
		if (*iterA > *iterB)
			*iterR++ = *iterB++;
		else
			*iterR++ = *iterA++;
	}

	if (iterA != A.end()) {
		while (iterA != A.end()) {
			*iterR = *iterA++;
			++iterR;
		}
	}
	else {
		while (iterB != B.end())
			*iterR++ = *iterB++;
	}

	for (auto v : R)
		cout << v << ' ';
	cout << endl;
	return 0;
}