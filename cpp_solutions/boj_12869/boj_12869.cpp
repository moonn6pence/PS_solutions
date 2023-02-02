#include <iostream>
#include <algorithm>

using namespace std;
const int INF = 2e9;
int N;
int scv[3];
int cache[61][61][61];
int da[6] = { 9,9,3,3,1,1 }, db[6] = { 3,1,9,1,9,3 }, dc[6] = { 1,3,1,9,3,9 };

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> scv[i];
}

int solve(int a, int b, int c) {
	if (!a && !b && !c) return 0;

	int& ret = cache[a][b][c];

	if (ret != -1) return ret;

	ret = INF;

	for (int i = 0; i < 6; i++) {
		int na = a - da[i], nb = b - db[i], nc = c - dc[i];
		na = na < 0 ? 0 : na;
		nb = nb < 0 ? 0 : nb;
		nc = nc < 0 ? 0 : nc;
		
		ret = min(ret, solve(na, nb, nc) + 1);
	}

	return ret;
}

void solution() {
	input();
	fill(&cache[0][0][0], &cache[60][60][61], -1);
	cout << solve(scv[0],scv[1],scv[2]);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);

	solution();
}