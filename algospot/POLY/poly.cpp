#include <iostream>
#include <memory.h>

using namespace std;
const int MOD = 10000000;
int N;
int cache[101][101];

void input(){
    cin >> N;
}

int poly(int n,int first){
    if(n == first)
        return 1;

    int &ret = cache[n][first];
    if(ret != -1)
        return ret;

    ret = 0;
    for (int second = 1; second <= n - first; second++)
    {
        ret += ((first + second - 1) * poly(n - first, second)) % MOD;
        ret %= MOD;
    }

    return ret;
}

void solution(){
    int tc, ans;
    cin >> tc;
    while(tc--){
        memset(cache, -1, sizeof(cache));
        ans = 0;
        input();
        for (int i = 1; i <= N; i++)
        {
            ans += poly(N, i);
            ans %= MOD;
        }
        cout << ans << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    solution();
}