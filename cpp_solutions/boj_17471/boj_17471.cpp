#include <iostream>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;
const int INF = 2e9;
int N, total;
int popl[10];
bool adj[10][10];
int fullState;

void input() {
	cin >> N;
	fullState = (1 << N) - 1;
	for (int i = 0; i < N; i++) {
		cin >> popl[i];
		total += popl[i];
	}

	int num, v;
	for (int u = 0; u < N; u++) {
		cin >> num;
		while (num--) {
			cin >> v;
			adj[u][v - 1] = true;
		}
	}
}

int bfs(int state) {
	int tmp = state, src = 0;
	while (!(tmp & 1)) {
		tmp = tmp >> 1;
		src++;
	}

	bool visited[10];
	fill(&visited[0], &visited[10], false);
	int sum = popl[src];

	queue<int> order;
	order.push(src);
	visited[src] = true;

	while (!order.empty()) {
		int cur = order.front();
		order.pop();

		for (int i = 0; i < N; i++) {
			if (!adj[cur][i]) continue;
			if (visited[i]) continue;
			if (!(state & (1 << i))) continue;

			order.push(i);
			visited[i] = true;
			sum += popl[i];
		}
	}

	return sum;
}

int solve(int state, int cur) {

	if (cur == N) {
		if (state == 0 || state == (1 << N) - 1) return INF;
		int a = bfs(state), b = bfs(fullState ^ state);

		if (a + b != total) return INF;

		return abs(a-b);
	}

	return min(solve(state, cur + 1), solve(state | (1 << cur), cur + 1));
}


void solution() {
	input();
	int answer = solve(0,0);

	cout << (answer < INF ? answer : -1);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);

	solution();
}