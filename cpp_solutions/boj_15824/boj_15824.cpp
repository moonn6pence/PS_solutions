#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
const int MOD = 1000000007;
typedef long long ll;
ll N;
vector<int> menu;

void input(){
    cin >> N;
    menu.resize(N);

    for (int i = 0; i < N; i++){
        cin >> menu[i];
    }

    sort(menu.begin(), menu.end());
}

ll pow(ll base, ll exp){
    ll ret = 1;

    while (exp){
        if (exp % 2){
            ret = ret * base % MOD;
        }
        base = base * base % MOD;
        exp /= 2;
    }

    return ret;
}

ll solve(){
    ll ret = 0;

    for (int i = 0; i < N; i++){
        ret += menu[i] * (pow(2, i) + MOD - pow(2, N - i - 1)) % MOD;
        ret %= MOD;
    }

    return ret;
}

void solution(){
    input();
    cout << solve() << '\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    solution();

    return 0;
}