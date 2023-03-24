#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
int N, T;
vector<pll> carrot;

void input(){
    cin >> N >> T;

    ll w, p;

    for (int i = 0; i < N; i++){
        cin >> w >> p;
        carrot.push_back({p, w});
    }

    sort(carrot.begin(), carrot.end(), greater<>());
}

ll solve(){
    ll t = T, ret = 0;

    for (int i = 0; i < N; i++){
        ret += carrot[i].first * (t - 1) + carrot[i].second;
        t--;
    }

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