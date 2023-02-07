#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, int> ppiii;
const int INF = 2e9;
int N, M;
vector<pii> cctvs;
int graph[8][8];
int nonWall;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
vector<int> dir[6] = { {}, {0},{0,2},{0,1},{0,1,2},{0,1,2,3} };
vector<int> rot[6] = { {}, {0,1,2,3},{0,1},{0,1,2,3},{0,1,2,3},{0} };

void input() {
	cin >> N >> M;
	nonWall = N * M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> graph[i][j];
			if (graph[i][j] == 6) nonWall--;
			if (graph[i][j] > 0 && graph[i][j] < 6) cctvs.push_back({ i,j });
		}
	}
}

int bfs(queue<ppiii> order) {
	int ret = 0;

	bool visited[8][8];
	bool visitedDir[4][8][8];
	fill_n(&visited[0][0], 8 * 8, false);
	fill_n(&visitedDir[0][0][0], 4* 8 * 8, false);

	while (!order.empty()) {
		int x = order.front().first.first;
		int y = order.front().first.second;
		int d = order.front().second;
		order.pop();

		if (!visited[x][y]) {
			visited[x][y] = true;
			ret++;
		}

		int nx = x + dx[d], ny = y + dy[d];

		if (nx < 0 || ny < 0 || nx >= N || ny >= M || graph[nx][ny] == 6) continue;
		if (visitedDir[d][nx][ny]) continue;
		order.push({ {nx,ny},d });
		visitedDir[d][nx][ny] = true;
	}

	return ret;
}

int solve(int begin, queue<ppiii> order) {
	if (begin == cctvs.size()) {
		int ans = nonWall - bfs(order);
		return ans;
	}

	int x = cctvs[begin].first;
	int y = cctvs[begin].second;
	int type = graph[x][y];

	int ret = INF;

	for (int i = 0; i < rot[type].size(); i++) {
		queue<ppiii> newOrder = order;
		for (int j = 0; j < dir[type].size(); j++) {
			int d = (dir[type][j] + rot[type][i]) % 4;
			newOrder.push({ {x,y},d });
		}

		ret = min(ret, solve(begin + 1, newOrder));
	}

	return ret;
}

void solution() {
	input();
	cout << solve(0,queue<ppiii>());
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);

	solution();
}