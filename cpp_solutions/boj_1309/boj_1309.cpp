#include <iostream>
#include <algorithm>

using namespace std;
const int MOD = 9901;
int N, cache[100000][3];

int solve(int n, int x){
    int &ret = cache[n][x];

    if (ret != -1) return ret;

    if (n == N - 1) return 1;

    ret = solve(n + 1, 0);

    if (!(x & 2)) ret = (ret + solve(n + 1, 2)) % MOD;

    if (!(x & 1)) ret = (ret + solve(n + 1, 1)) % MOD;

    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;
    fill(&cache[0][0], &cache[99999][3], -1);
    cout << (solve(0, 0) + solve(0, 1) + solve(0, 2)) % MOD;
}