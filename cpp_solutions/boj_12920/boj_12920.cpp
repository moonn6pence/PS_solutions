#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
int N, M;
int cache[1401][10001];
vector<pii> vw;

void input() {
	cin >> N >> M;
    int v, c, k;

    for (int i = 0; i < N; i++) {
        cin >> v >> c >> k;

        for (int j = 0; k > 0; j++){
            int tmp = min(1 << j, k);
            vw.push_back({v * tmp, c * tmp});
            k -= tmp;
        }
    }
}

int solve(int n, int m) {
	if (n < 0 || m <= 0) return 0;

    int& ret = cache[n][m];

	if (ret != -1) return ret;

	ret = 0;

    if (vw[n].first <= m) ret = solve(n - 1, m - vw[n].first) + vw[n].second;
    ret = max(ret, solve(n - 1, m));

    return ret;
}

void solution() {
	input();
	fill(&cache[0][0], &cache[1400][10001], -1);
    cout << solve(vw.size() - 1, M);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);

	solution();
}