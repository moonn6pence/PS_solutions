#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
typedef pair<bool, int> pbi;
int N;
int weight[10001], cache[10001][2];
vector<int> adj[10001];
vector<pbi> path[2][10001];

void input() {
	cin >> N;

	for (int i = 1; i <= N; i++) cin >> weight[i];
	
	int a, b;
	for (int i = 0; i < N - 1; i++) {
		cin >> a >> b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
}

int solve(int node, int parent, bool isSelected) {
	int& ret = cache[node][isSelected];

	if (ret != -1) return ret;

	int childSize = adj[node].size();
	int ans = 0;

	if (isSelected) {
		for (int i = 0; i < childSize; i++) {
			int child = adj[node][i];
			if (child == parent) continue;
			ans += solve(child, node, false);
			path[isSelected][node].push_back({ false, child });
		}
		ret = ans + weight[node];
	} else {
		for (int i = 0; i < childSize; i++) {
			int child = adj[node][i];
			if (child == parent) continue;

			int notSelect = solve(child, node, false);
			int select = solve(child, node, true);

			if (select > notSelect) {
				ans += select;
				path[isSelected][node].push_back({ true, child });
			} else {
				ans += notSelect;
				path[isSelected][node].push_back({ false, child });
			}
		}
		ret = ans;
	}

	return ret;
}

void output(bool c) {
	vector<int> result;

	queue<pbi> order;
	order.push({ c,1 });
	
	while (!order.empty()) {
		bool choice = order.front().first;
		int node = order.front().second;
		order.pop();

		if (choice) result.push_back(node);

		for (auto next : path[choice][node]) {
			if (next.second == 0) continue;
			order.push(next);
		}
	}

	sort(result.begin(), result.end());

	for (auto node : result) {
		cout << node << ' ';
	}
}

void solution() {
	input();

	fill(&cache[0][0], &cache[10000][2], -1);

	int notSelect = solve(1, 0, false);
	int select = solve(1, 0, true);

	cout << max(notSelect, select) << '\n';
	if (notSelect >= select) output(false);
	else output(true);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);

	solution();
}