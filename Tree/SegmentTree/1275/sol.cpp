#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<long long> segtree, v;
int N, Q;

long long init(int start, int end, int node) {
	int mid = (start + end) / 2;
	if (start == end)
		return segtree[node] = v[start];
	return segtree[node] = init(start, mid, node * 2) + init(mid + 1, end, node * 2 + 1);
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
	cin >> N >> Q;

	v = vector<long long>(N+1);
	for (int i=1;i<=N;++i)
		cin >> v[i];
	int height = ceil(log2(N));
	segtree = vector<long long>(1<<(height+1));
	segtree[0] = 0;
	init(1, N, 1);
	for (int i=0;i<Q;i++) {
		int x, y, a, b, temp;
		long long diff;
		cin >> x >> y >> a >> b;
		diff = b - v[a];
		v[a] = b;
		if (x > y) {
			temp = x;
			x = y;
			y = temp;
		}
		cout << sum(1, N, x, y, 1) << '\n';
		update(1, N, a, diff, 1);
	}
	return 0;
}