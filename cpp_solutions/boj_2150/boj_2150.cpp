#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;
const int MAX = 10001;
int V, E;
vector<int> graph[MAX];
int d[MAX],id;
bool finished[MAX];
stack<int> stk;
vector<vector<int>> SCC;

void input() {
	cin >> V >> E;

	int a, b;
	for (int i = 0; i < E; i++) {
		cin >> a >> b;
		graph[a].push_back(b);
	}
}

int dfs(int x) {
	d[x] = ++id;
	stk.push(x);

	int parent = d[x];

	for (auto node : graph[x]) {
		if (d[node] == 0) parent = min(parent, dfs(node));
		else if (!finished[node]) parent = min(parent, d[node]);
	}

	if (parent == d[x]) {
		vector<int> comp;

		while (1) {
			int node = stk.top();
			stk.pop();

			comp.push_back(node);
			finished[node] = true;

			if (x == node) break;
		}
		sort(comp.begin(), comp.end());
		SCC.push_back(comp);
	}

	return parent;
}

void solve() {
	for (int i = 1; i <= V; i++) {
		if (!d[i]) dfs(i);
	}

	cout << SCC.size() << '\n';
	sort(SCC.begin(), SCC.end());
	for (vector<int> scc : SCC) {
		for (int node : scc) {
			cout << node << ' ';
		}
		cout << -1 << '\n';
	}
}

void solution() {
	input();
	solve();
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solution();
}