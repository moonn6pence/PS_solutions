#include <iostream>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, int> ppiii;
const int INF = 2e9;
int N, M, K;
char graph[1000][1000];
int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

void input() {
	cin >> N >> M >> K;
	
	string tmp;
	for (int i = 0; i < N; i++) {
		cin >> tmp;
		for (int j = 0; j < M; j++) {
			graph[i][j] = tmp[j];
		}

	}
}

int bfs() {
	int visited[11][1000][1000];
	fill_n(&visited[0][0][0], 11*1000*1000, INF);

	queue<ppiii> order;
	order.push({ {0, 0},0 });
	visited[0][0][0] = 1;

	while (!order.empty()) {
		int x = order.front().first.first, y = order.front().first.second;
		int cnt = order.front().second;
		int& cost = visited[cnt][x][y];
		order.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;

			if (graph[nx][ny] == '0') {
				if (cost + 1 >= visited[cnt][nx][ny]) continue;
				order.push({ { nx,ny }, cnt });
				visited[cnt][nx][ny] = cost + 1;
			}

			if (graph[nx][ny] == '1' && cnt < K) {
				if (cost % 2 == 0) {
					if (cost + 2 >= visited[cnt + 1][nx][ny]) continue;
					order.push({ {nx,ny},cnt + 1 });
					visited[cnt + 1][nx][ny] = cost + 2;
				} else {
					if (cost + 1 >= visited[cnt + 1][nx][ny]) continue;
					order.push({ {nx,ny},cnt + 1 });
					visited[cnt + 1][nx][ny] = cost + 1;
				}
			}
		}
	}

	int ret = INF;

	for (int i = 0; i <= K; i++) {
		if (visited[i][N-1][M-1] != -1) ret = min(ret, visited[i][N-1][M-1]);
	}

	return ret < INF ? ret : -1;
}


void solution() {
	input();
	cout << bfs();
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);

	solution();
}