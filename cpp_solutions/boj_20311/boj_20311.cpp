#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;
typedef pair<int, int> pii;
int N, K;
vector<pii> color;
vector<vector<int>> stk;

void input() {
	cin >> N >> K;

	int c;
	for (int i = 0; i < K; i++) {
		cin >> c;
		color.push_back({c, i});
	}

	sort(color.begin(), color.end(), greater<>());
}

void solve() {
	int std = color[0].first;

	if (N - std + 1 < std) {
		cout << -1;
		return;
	}

	stk.assign(std, vector<int>(1, color[0].second));

	int idx = 0;

	for (int i = 1; i < K; i++) {
		for (int j = 0; j < color[i].first; j++) {
			stk[idx++].push_back(color[i].second);
			idx %= std;
		}
	}

	for (auto st : stk) {
		for (auto c : st) {
			cout << c+1 << ' ';
		}
	}
}

void solution() {
	input();
	solve();
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solution();
}