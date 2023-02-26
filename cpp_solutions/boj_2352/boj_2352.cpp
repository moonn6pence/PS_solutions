#include <bits/stdc++.h>

using namespace std;
int N;
int port[40001], cache[40001];

void input(){
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> port[i];
    }
}

int solve(){
    cache[0] = port[0];

    int idx = 1;
    for (int i = 1; i < N; i++){
        if (cache[idx - 1] < port[i]) cache[idx++] = port[i];
        else cache[lower_bound(cache, cache + idx, port[i]) - cache] = port[i];
    }

    return idx;
}

void solution(){
    input();
    cout << solve();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    solution();
}