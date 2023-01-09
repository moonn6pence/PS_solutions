#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
int N, M, K;
vector<ll> num;
vector<ll> tree;

void input() {
	cin >> N >> M >> K;

	int tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		num.push_back(tmp);
	}
}

ll makeSegmentTree(int node, int start, int end) {
	if (start == end) return tree[node] = num[start];

	int mid = (start + end) / 2;
	return tree[node] = makeSegmentTree(node * 2, start, mid) * makeSegmentTree(node * 2 + 1, mid + 1, end) % MOD;
}

ll updateTree(int node, int start, int end, int target, ll alt) {
	if (target < start || end < target) return tree[node];
	if (start == end) return tree[node] = alt;

	int mid = (start + end) / 2;
	return tree[node] = updateTree(node * 2, start, mid, target, alt) * updateTree(node * 2 + 1, mid + 1, end, target, alt) % MOD;
}

ll multiply(int node, int start, int end, int left, int right) {
	if (left > end || right < start) return 1;

	if (left <= start && end <= right) return tree[node];

	int mid = (start + end) / 2;
	return multiply(node * 2, start, mid, left, right) * multiply(node * 2 + 1, mid + 1, end, left, right) % MOD;
}

void solve() {
	tree.resize((1 << ((int)ceil(log2(N)) + 1)));

	makeSegmentTree(1, 0, N - 1);

	while (M + K) {
		int a, b, c;
		cin >> a >> b >> c;
		a--; b--;
		if (!a) {
			M--;
			updateTree(1, 0, N - 1, b, c);
		}
		else {
			K--;
			cout << multiply(1, 0, N - 1, b, --c) << '\n';
		}
	}
}

void solution() {
	input();
	solve();
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);

	solution();
}