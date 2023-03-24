#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int n, m;
string board[1000];
int cache[1000][1000];

void input() {
	cin >> n >> m;

	string s;
	for (int i = 0; i < n; i++) cin >> board[i];
}

int getMin(int a, int b, int c) {
	int ret = min(a, b);
	ret = min(c, ret);

	return ret;
}

void solve() {
	int ret = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
            if (i == 0 || j == 0 || board[i][j] == '0') cache[i][j] = (board[i][j] == '1');
			else cache[i][j] = getMin(cache[i - 1][j], cache[i][j - 1], cache[i - 1][j - 1]) + 1;

			ret = max(ret, cache[i][j]);
		}
	}

	cout << ret * ret;
}

void solution() {
	input();
	solve();
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	solution();
}