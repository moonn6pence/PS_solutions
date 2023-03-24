#include <iostream>
#include <string>
#include <map>

using namespace std;
string S;
map<char, int> cnt;
char answer[50];

void input() {
	cin >> S;
}

bool backtrack(int idx) {
	if (idx == S.length()) return true;

	if (cnt['B'] > cnt['A'] + cnt['C'] + 1) return false;
	if ((cnt['C'] - 1) * 2 > cnt['A'] + cnt['B']) return false;

	for (int i = 2; i >= 0; i--) {
		bool flag = true;
		char cur = 'A' + i;

		for (int j = 1; j <= i; j++) {
			if (idx >= j && answer[idx - j] == cur) {
				flag = false;
				break;
			}
		}

		if (!flag || cnt[cur] == 0) continue;

		cnt[cur]--;
		answer[idx] = cur;
		if(backtrack(idx + 1)) return true;
		cnt[cur]++;
	}

	return false;
}

void solve() {
	for (char c : S) cnt[c]++;
	if (backtrack(0)) cout << answer;
	else cout << -1;
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