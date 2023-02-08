#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
typedef long long ll;
const int MAX = 1000000;
int N;
vector<ll> tree;

void query(int node, int start, int end, ll order) {
	tree[node]--;

	if (start == end) {
		cout << start << '\n';
		return;
	}

	int mid = (start + end) / 2;
	if (tree[node * 2] >= order) query(node * 2, start, mid, order);
	else query(node * 2 + 1, mid + 1, end, order - tree[node * 2]);
}

void update(int node, int start, int end, ll target, int diff) {
	if (target < start || end < target) return;
	
	tree[node] += diff;

	if (start == end) return;

	int mid = (start + end) / 2;

	update(node * 2, start, mid, target, diff);
	update(node * 2 + 1, mid + 1, end, target, diff);
}

void solution() {
	cin >> N;
	int A, C;
	ll B;
	tree.resize(1 << (int)ceil(log2(MAX + 1) + 1));

	while (N--) {
		cin >> A >> B;

		if (A & 1) {
			query(1, 1, MAX, B);
		} else {
			cin >> C;
			update(1, 1, MAX, B, C);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);

	solution();
}