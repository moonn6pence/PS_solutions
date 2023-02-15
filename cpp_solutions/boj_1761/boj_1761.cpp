#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
typedef pair<int, int> pii;
const int INF = 2e9;
int N, M, maxLv;
vector<pii> costs[40001];
int dist[40001], parent[40001][16], level[40001];

void input() {
	cin >> N;
	maxLv = (int)floor(log2(N + 1));
	int a, b, c;
	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b >> c;
		costs[a].push_back({ b,c });
		costs[b].push_back({ a,c });
	}
	
}

void setTree(int node, int pnode, int lv, int cost) {
	parent[node][0] = pnode;
	level[node] = lv;
	dist[node] = cost;
	
	for (int i = 1; i <= maxLv; i++) {
		parent[node][i] = parent[parent[node][i - 1]][i - 1];
	}

	for (int i = 0; i < costs[node].size(); i++) {
		int child = costs[node][i].first, newCost = costs[node][i].second;
		if (child == pnode) continue;

		setTree(child, node, lv + 1, cost + newCost);
	}
}

int LCA(int a, int b) {
	if (a == 1 || b == 1) return 1;

	if (level[a] < level[b]) swap(a, b);

	while (level[a] != level[b]) {
		for (int i = maxLv; i >= 0; i--) {
			if (level[parent[a][i]] >= level[b]) {
				a = parent[a][i];
			}
		}
	}

	int ret = a;

	if (a != b) {
		for (int i = maxLv; i >= 0; i--) {
			if (parent[a][i] != parent[b][i]) {
				a = parent[a][i];
				b = parent[b][i];
			}

			ret = parent[a][i];
		}
	}

	return ret;
}

void solve() {
	cin >> M;
	int a, b;
	while (M--) {
		cin >> a >> b;
		int ancestor = LCA(a, b);
		cout <<  dist[a] + dist[b] - dist[ancestor] * 2 << '\n';
	}
}


void solution() {
	input();
	setTree(1, 0, 1, 0);
	solve();
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);

	solution();
}