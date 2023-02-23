#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, int> ppiii;
int N, total;
int sand[499][499];
int dx[4] = { 0, 1, 0, -1 };
int dy[4] = { -1, 0, 1, 0 };
int dir[499][499];
vector<ppiii> tornado[4] = { {{{0,-2},5},{{-1,0},7},{{1,0},7},{{-1,-1},10},{{1,-1},10},{{-1,1},1},{{1,1},1},{{-2,0},2},{{2,0},2}},
{{{2, 0},5},{{0,-1},7},{{0,1},7},{{1,-1},10},{{1,1},10},{{-1,-1},1},{{-1,1},1},{{0,-2},2},{{0,2},2}},
{{{0,2},5},{{-1,0},7},{{1,0},7},{{-1,-1},1},{{1,-1},1},{{-1,1},10},{{1,1},10},{{-2,0},2},{{2,0},2}},
{{{-2, 0},5},{{0,-1},7},{{0,1},7},{{1,-1},1},{{1,1},1},{{-1,-1},10},{{-1,1},10},{{0,-2},2},{{0,2},2}} };

void input() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> sand[i][j];
			total += sand[i][j];
		}
	}
}

void init() {
	fill(&dir[0][0], &dir[498][499], -1);
	
	int x = 0, y = 0;
	int nx = x, ny = y, curDir = 3;
	dir[x][y] = 0;

	while (x != N / 2 || y != N / 2) {
		nx = x + dx[curDir]; ny = y + dy[curDir];

		if (nx < 0 || ny < 0 || nx >= N || ny >= N || dir[nx][ny] != -1) {
			curDir = (curDir + 3) % 4;
			nx = x + dx[curDir]; ny = y + dy[curDir];
		}
		dir[nx][ny] = (curDir + 2) % 4;
		x = nx; y = ny;
	}
}

int solve() {

	int x = N / 2, y = N / 2;
	int nx, ny, ax, ay;

	while (x != 0 || y != 0) {
		nx = x + dx[dir[x][y]]; ny = y + dy[dir[x][y]];
		ax = nx + dx[dir[x][y]]; ay = ny + dy[dir[x][y]];
		int a = sand[nx][ny];

		for (auto it : tornado[dir[x][y]]) {
			pii d = it.first;
			int r = it.second;
			
			int mx = nx + d.first, my = ny + d.second;
			int scattered = sand[nx][ny] * r / 100;
			a -= scattered;

			if (mx < 0 || my < 0 || mx >= N || my >= N) continue;
			sand[mx][my] += scattered;
		}

		if (ax >= 0 && ay >= 0 && ax < N && ay < N) {
			sand[ax][ay] += a;
		}
		
		sand[nx][ny] = 0;
		x = nx; y = ny;
	}

	int sum = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			sum += sand[i][j];
		}
	}

	return total - sum;
}

void solution() {
	input();
	init();
	cout << solve();
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solution();
}