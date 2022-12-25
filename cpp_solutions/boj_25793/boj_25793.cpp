#include <iostream>

using namespace std;

typedef long long ll;

ll R, C, T;
ll dark, white;

void input(){
    cin >> R >> C;
}

void solve(){
    ll x = min(R, C), diff = abs(R - C);
    white = ll(x * (x + 1) * (x * 2 + 1) / 3) + x * (x + 1) * (diff - 1) - diff * x;
    dark = white + x;
}

void output(){
    cout << dark << ' ' <<white << '\n';
    
}

void solution(){
    cin >> T;

    while(T--){
        input();
        solve();
        output();
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    solution();

    return 0;
}