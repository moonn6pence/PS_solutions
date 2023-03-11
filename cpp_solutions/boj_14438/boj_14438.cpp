#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;
int N;
vector<int> tree;
vector<int> A;

void input() {
	cin >> N;
	A.assign(N + 1, 0);
	tree.assign(1 <<((int)ceil(log2(N))+1), 0);

	for (int i = 1; i <= N; i++) cin >> A[i];
}

int make(int node, int start, int end) {
	if (start == end) return tree[node] = A[start];

	int mid = (start + end) / 2;

	return tree[node] = min(make(node * 2, start, mid), make(node * 2 + 1, mid + 1, end));
}

int update(int node, int start, int end, int target, int val) {
	if (target < start || end < target) return tree[node];
	if (start == end) return tree[node] = val;

	int mid = (start + end) / 2;

	return tree[node] = min(update(node * 2, start, mid, target, val), update(node * 2 + 1, mid + 1, end, target, val));
}

int query(int node, int start, int end, int left, int right) {
	if (right < start || end < left) return 2e9;
	if (start == end) return tree[node];

	int mid = (start + end) / 2;

	if (left <= start && end <= right) return tree[node];

	return min(query(node * 2, start, mid, left, right), query(node * 2 + 1, mid + 1, end, left, right));
}

void solution() {
	input();
	make(1, 1, N);
	
	int Q, t, i, j;
	cin >> Q;

	while (Q--) {
		cin >> t >> i >> j;
		if (t == 1) update(1, 1, N, i, j);
		else cout << query(1, 1, N, i, j) << '\n';
	}
	
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solution();
}