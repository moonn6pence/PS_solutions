#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;
int N;
ll p;

void solution() {
	cin >> N;

	int g = 0;

	for (int i = 0; i < N; i++) {
		cin >> p;
		g ^= p;
	}

	if (g) cout << "koosaga";
	else cout << "cubelover";
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);

	solution();
}