#include <iostream>
#include <memory.h>

using namespace std;

const int MOD = 1000000007;

int n;
int cache[101];

void input(){
    cin >> n;
}

int tiling(int idx){
    if(idx <= 1)
        return 1;

    int &ret = cache[idx];

    if(ret != -1)
        return ret;

    return ret = (tiling(idx - 1) + tiling(idx - 2)) % MOD;
}

int asymTiling(int idx){
    int sym;
    if (idx & 1)
        sym = tiling(n / 2);
    else
        sym = (tiling(n / 2) + tiling(n / 2 - 1)) % MOD;

    return (tiling(n) - sym + MOD) % MOD;
}

void solution(){
    int tc;
    cin >> tc;

    while(tc--){
        memset(cache, -1, sizeof(cache));
        input();
        tiling(n);
        cout << asymTiling(n) << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    solution();
}