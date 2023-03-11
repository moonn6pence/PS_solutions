#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;
int score[3], sec[3], ans[3];

int MMSStoSec(string s) {
	istringstream iss(s);
	string buf;
	int ret = 0, i = 1;

	while (getline(iss, buf, ':')) {
		ret += stoi(buf);
		if (i--) ret *= 60;
	}
	return ret;
}

void SecToMMSS(int t) {
	printf("%02d:%02d\n", (int)t / 60, t % 60);
}

void solution() {
	int N; cin >> N;
	int lead = 0, team, t;
	string mmss;

	for (int i = 0; i < N; i++) {
		cin >> team >> mmss;
		t = MMSStoSec(mmss);
		score[team]++;

		if (!lead) {
			sec[lead = team] = t;
		} else if (lead && score[1] == score[2]) {
			ans[lead] += t - sec[lead];
			lead = 0;
		}
	}

	if (lead) ans[lead] += 60 * 48 - sec[lead];

	SecToMMSS(ans[1]); SecToMMSS(ans[2]);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solution();
}