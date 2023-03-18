#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
bool isPrime[1000001];
ll MN, MX;

void input() {
	cin >> MN >> MX;
}

void Eratos() {
	fill(&isPrime[0], &isPrime[1000001], true);

	for (ll i = 2; i*i <= MX; i++) {
		ll sq = i * i;
		ll start = sq - MN % sq;
		if (start == sq) start = 0;

		for (ll num = start; num <= MX-MN; num += sq) {
			isPrime[num] = false;
		}
	}
}

int solve() {
	ll cnt = 0;
	for (ll i = 0; i <= MX - MN; i++) {
		if (isPrime[i]) cnt++;
	}

	return cnt;
}

void solution() {
	input();
	Eratos();
	cout << solve();
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	solution();
}