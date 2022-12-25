#include <iostream>
#include <vector>
#include <algorithm>
#include <memory.h>

using namespace std;

int N, M;
int cache[22][10001];
vector<int> coin;

void input(){
    cin >> N;
    int tmp;
    for (int i = 0; i < N; i++){
        cin >> tmp;
        coin.push_back(tmp);
    }

    cin >> M;
}

int solve(int n,int m){
    if (n < 0 || m < 0)
        return 0;

    if (m == 0)
        return 1;

    int &ret = cache[n][m];

    if(ret != -1)
        return ret;

    return ret = solve(n - 1, m) + solve(n, m - coin[n]);
}

void solution(){
    int tc;
    cin >> tc;

    while(tc--){
        memset(cache, -1, sizeof(cache));
        coin.clear();
        input();
        cout << solve(N - 1, M) << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    solution();

    return 0;
}