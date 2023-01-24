#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll N;

void input(){
    cin >> N;
}

ll pow(int n, int r){
    ll ret = 1;

    while (r){
        if (r & 1) ret *= n;

        n *= n;
        r = r >> 1;
    }

    return ret;
}

ll getEulersPhi(int a,int n){
    return pow(a, n - 1) * (a - 1);
}

ll solve(){
    ll ret = N;

    for (ll i = 2; i * i <= N; i++){
        if (N % i == 0){
            ret -= ret / i;
            while (N % i == 0) N /= i;
        }
    }

    if (N != 1) ret -= ret / N;

    return ret;
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