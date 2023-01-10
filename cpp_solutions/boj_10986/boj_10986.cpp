#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int N, M;
int R[1000];

void input(){
    cin >> N >> M;

    int cur,acc = 0;
    R[0]++;
    for (int i = 0; i < N; i++){
        cin >> cur;
        acc = (acc + cur) % M;
        R[acc]++;
    }
}

ll selectTwo(int n){
    return (ll) n * (n - 1) / 2;
}

void solve(){
    ll ret = 0;
    for (auto& iter : R){
        ret += selectTwo(iter);
    }

    cout << ret << '\n';
}

void solution(){
    input();
    solve();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    solution();
}