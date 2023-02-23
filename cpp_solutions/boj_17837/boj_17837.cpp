#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, int> ppiii;
int N, K;
int color[13][13];
int dx[5] = { 0, 0, 0, -1, 1 };
int dy[5] = { 0, 1, -1, 0, 0 };
int anti[5] = { 0, 2, 1, 4, 3 };
vector<int> board[13][13];
map<int, ppiii> info;

void input() {
	cin >> N >> K;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> color[i][j];
		}
	}

	int r, c, dir;
	for (int k = 1; k <= K; k++) {
		cin >> r >> c >> dir;
		board[r][c].push_back(k);
		info[k] = { {r, c}, dir };
	}
}

void moveWhite(int k, int x, int y, int nx, int ny) {
	vector<int>& v = board[x][y];
	vector<int>& nv = board[nx][ny];

	auto iter = find(v.begin(), v.end(), k);
	auto tmp = iter;

	while (iter != v.end()) {
		nv.push_back(*iter);
		info[*iter].first = { nx, ny };
		iter++;
	}

	v.erase(tmp, v.end());
}

void moveRed(int k, int x, int y, int nx, int ny) {
	vector<int>& v = board[x][y];
	vector<int>& nv = board[nx][ny];

	int newK = *v.rbegin();
	auto iter = find(v.begin(), v.end(), k);
	reverse(iter, v.end());

	moveWhite(newK, x, y, nx, ny);
}

bool move() {
	for (int k = 1; k <= K; k++) {
		int x, y, dir = info[k].second;
		tie(x, y) = info[k].first;
		int nx = x + dx[dir];
		int ny = y + dy[dir];

		if (nx < 1 || ny < 1 || nx > N || ny > N || color[nx][ny] == 2) {
			dir = anti[dir];
			info[k].second = dir;
			nx = x + dx[dir];
			ny = y + dy[dir];
			if (nx < 1 || ny < 1 || nx > N || ny > N || color[nx][ny] == 2) {
				continue;
			}	
			if(color[nx][ny] == 1) moveRed(k, x, y, nx, ny);
			else moveWhite(k, x, y, nx, ny);
		}
		else if (color[nx][ny] == 1) moveRed(k, x, y, nx, ny);
		else moveWhite(k, x, y, nx, ny);

		if (board[nx][ny].size() > 3) return false;
	}

	return true;
}

int solve() {

	int cnt = 0;

	while (cnt++ < 1000) {
		if (!move()) return cnt;
	}

	return -1;
}

void solution() {
	input();
	cout << solve();
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solution();
}