#include <bits/stdc++.h>

using namespace std;
int N, K;

void input(){
    cin >> N >> K;
}

int solve(){
    int ret = 0;
    for (int i = 1; i <= N; i++){
        ret = (ret + K) % i;
    }

    return ret + 1;
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