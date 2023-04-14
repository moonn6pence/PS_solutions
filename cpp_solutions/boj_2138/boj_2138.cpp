#include <bits/stdc++.h>

using namespace std;
int N;
string a, b, tmp;
map<char, char> change = { {'1','0'},{'0','1'} };

void input() {
	cin >> N >> a >> b;
	tmp = a;
}

int solve(int idx, int cnt) {
	if (idx == N) {
		if (a[idx - 1] == b[idx - 1]) return cnt;
		return -1;
	}

	if (a[idx - 1] == b[idx - 1]) return solve(idx + 1, cnt);

	a[idx - 1] = change[a[idx - 1]];
	a[idx] = change[a[idx]];
	if (idx + 1 < N) a[idx + 1] = change[a[idx + 1]];
	return solve(idx + 1, cnt + 1);
}

void solution() {
	input();
	int ret = solve(1, 0);
	a = tmp;

	if (ret != -1) {
		cout << ret;
		return;
	}

	a[0] = change[a[0]];
	a[1] = change[a[1]];
	cout << solve(1, 1);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solution();
}