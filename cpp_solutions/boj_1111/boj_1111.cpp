#include <bits/stdc++.h>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
    int N, arr[50];
    cin >> N;
	for (int i = 0; i < N; i++) cin >> arr[i];
	if (N == 1) cout << 'A';
	else if (N == 2 && arr[0] != arr[1]) cout << 'A';
	else {
		int a = arr[0] != arr[1] ? (arr[2] - arr[1]) / (arr[1] - arr[0]) : 0, b = arr[1] - a * arr[0];
		for (int i = 1; i < N; i++) {
			if (arr[i] == arr[i - 1] * a + b) continue;
			cout << 'B';
			return 0;
		}
		cout << arr[N - 1] * a + b;
	}
}