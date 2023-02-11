#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
ll cache[4000001];

ll fastPow(ll base, ll exp){
    int ret = 1;

    while (exp){
        if (exp & 1) ret = (ret * base) % MOD;

        base = (base * base) % MOD;
        exp >>= 1;
    }

    return ret;
}

void init(){
    cache[0] = cache[1] = 1;
    for (int i = 2; i <= 4000000; i++){
        cache[i] = cache[i - 1] * i % MOD;
    }
}

ll solve(int n, int k){
    ll q = cache[k] * cache[n - k] % MOD;

    return cache[n] * fastPow(q, MOD - 2) % MOD;
}

void solution(){
    int N, M, K;
    cin >> M;
    init();

    while (M--){
        cin >> N >> K;
        cout << solve(N, K) << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    solution();
}