#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<long long>	v, segtree;
int N, M, K;

long long range(int start, int end, int node) {
	if (start == end)
		return segtree[node] = v[start];
	int mid = (start + end) / 2;
	return segtree[node] = range(start, mid, node * 2) + range(mid + 1, end, node * 2 + 1);
}

long long sum(int start, int end, int left, int right, int node) {
	if (left > end || right < start)
		return 0;
	if (left <= start && end <= right)
		return segtree[node];
	int mid = (start + end) / 2;
	return sum(start, mid, left, right, node * 2) + sum(mid + 1, end, left, right, node * 2 + 1);
}

void update(int start, int end, int idx, long long diff, int node) {
	if (idx < start || idx > end)
		return;
	segtree[node] += diff;
	if (start == end)
		return;
	int mid = (start + end) / 2;
	update(start, mid, idx, diff, node * 2);
	update(mid + 1, end, idx, diff, node * 2 + 1);
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M >> K;
	v = vector<long long>(N+1);
	int height = ceil(log2(N));
	segtree = vector<long long>(1<<(height + 1));
	for (int i=1;i<=N;i++)
		cin >> v[i];
	range(1, N, 1);

	for (int i=0;i<M+K;i++) {
		int a, b;
		long long c;
		cin >> a >> b >> c;
		if (a == 1) {
			long long diff = c-v[b];
			v[b] = c;
			update(1, N, b, diff, 1);
		}
		else {
			cout << sum(1, N, b, c, 1) << '\n';
		}
	}
	return 0;
}