#include <bits/stdc++.h>

using namespace std;
const int MOD = 10007;
int N;
int cache[53][53];

void input(){
    cin >> N;
}

int comb(int n, int r){
    if (n == r || r == 0) return 1;

    int &ret = cache[n][r];

    if (ret != -1) return ret;

    return ret = (comb(n - 1, r - 1) + comb(n - 1, r)) % MOD;
}

int solve(){
    int ret = 0;

    for (int i = 1; i * 4 <= N && i <= 13; i++){
        if (i & 1){
            ret += comb(13, i) * comb(52 - i * 4, N - i * 4) % MOD;
            ret %= MOD;
        } else {
            ret -= comb(13, i) * comb(52 - i * 4, N - i * 4) % MOD;
            ret = (ret + MOD) % MOD;
        }
    }

    return ret;
}

void solution(){
    memset(cache, -1, sizeof(cache));
    input();
    cout << solve() << '\n';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    solution();
}