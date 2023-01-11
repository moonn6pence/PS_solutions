#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, root;
vector<int> adj[10001];
int parent[10001], level[10001];

void init() {
	fill(&parent[0], &parent[10001], 0);
	fill(&level[0], &level[10001], 0);
	for (int i = 0; i < 10001; i++) {
		adj[i].clear();
	}
}

void input() {
	cin >> N;

	int a, b;
	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
		parent[b] = a;
	}
}

void findRoot() {
	for (int i = 1; i <= N; i++) {
		if (parent[i] == 0) {
			root = i;
			return;
		}
	}
}

void solve() {
	int a, b;
	cin >> a >> b;

	if (level[a] < level[b]) swap(a, b);

	while (level[a] != level[b]) {
		a = parent[a];
	}

	while (a != b) {
		a = parent[a];
		b = parent[b];
	}

	cout << a << '\n';
}

void setTree(int node, int pnode) {
	level[node] = level[pnode] + 1;

	for (int i = 0; i < adj[node].size(); i++) {
		int child = adj[node][i];
		if (pnode == child) continue;
		setTree(child, node);
	}
}

void solution() {
	int tc;
	cin >> tc;

	while (tc--) {
		init();
		input();
		findRoot();
		setTree(root, 0);
		solve();
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);

	solution();
}