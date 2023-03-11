#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
#include <string>

using namespace std;
typedef pair<int, int> pii;
typedef tuple<int, int, int> tiii;
int W, H;
char graph[100][100];
int visited[100][100][4];
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };
int rot[3] = { 3,0,1 };
vector<pii> trgt;

void input() {
	cin >> W >> H;
	string s;
	for (int i = 0; i < H; i++) {
		cin >> s;
		for (int j = 0; j < W; j++) {
			graph[i][j] = s[j];
			if (graph[i][j] == 'C') trgt.push_back({ i,j });
		}
	}
}

int bfs() {
	queue<tiii> order;
	int x, y, endx, endy;
	tie(x, y) = trgt[0];
	tie(endx, endy) = trgt[1];

	for (int i = 0; i < 4; i++) {
		visited[x][y][i] = 0;
		order.push({ x, y, i });
	}

	while (!order.empty()) {
		int x, y, dir;
		tie(x, y, dir) = order.front();
		order.pop();

		for (int i = 0; i < 3; i++) {
			int d = (dir + rot[i]) & 3;
			int nx = x + dx[d], ny = y + dy[d];
			if (nx < 0 || ny < 0 || nx >= H || ny >= W || graph[nx][ny] == '*') continue;
			if (visited[nx][ny][d] != -1 && visited[nx][ny][d] <= visited[x][y][dir] + (i != 1)) continue;

			visited[nx][ny][d] = visited[x][y][dir] + (i != 1);
			order.push({ nx,ny,d });
		}
	}

	int ret = 2e9;
	for (int i = 0; i < 4; i++) {
		if (visited[endx][endy][i] != -1)
			ret = min(ret, visited[endx][endy][i]);
	}

	return ret;
}

void solution() {
	input();
	fill(&visited[0][0][0], &visited[99][99][4], -1);
	cout << bfs();
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solution();
}