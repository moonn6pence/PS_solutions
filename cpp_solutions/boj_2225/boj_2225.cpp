#include <iostream>
#include <memory.h>

using namespace std;
const int MOD = 1e9;
int N, K;
int cache[401][201];

void input(){
    cin >> N >> K;
}

int solve(int n, int k){    
    if (k == 0 || n == k)
        return 1;

    int &ret = cache[n][k];
    if (ret != -1)
        return ret;

    return ret = (solve(n - 1, k) + solve(n - 1, k - 1)) % MOD;
}

void solution(){
    input();
    memset(cache, -1, sizeof(cache));
    cout << solve(N + K - 1, K - 1);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    solution();
}