#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int N;
int L[20], J[20];
int cache[21][100];

void input() {
    cin >> N;

    for (int i = 0; i < N; i++) cin >> L[i];
    for (int i = 0; i < N; i++) cin >> J[i];
}

int solve(int n, int m) {
    if (n < 0 || m <= 0) return 0;

    int& ret = cache[n][m];

    if (ret != -1) return ret;

    ret = 0;

    if (m - L[n] > 0) ret = solve(n - 1, m - L[n]) + J[n];
    return ret = max(ret, solve(n - 1, m));
}

void solution() {
    input();
    fill(&cache[0][0], &cache[20][100], -1);
    cout << solve(N - 1, 100);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    solution();
}