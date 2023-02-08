#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int N, K;
string numStr[15];
int mods[15];
int sizes[15];
int tenMods[51];
ll cache[1 << 15][100];
ll total = 1;

void input(){
    cin >> N;

    for (int i = 0; i < N; i++){
        cin >> numStr[i];
    }
    cin >> K;
}

int getMod(string& num){
    int ret = 0;

    for (int i = 0; i < num.length(); i++){
        ret *= 10;
        ret += num[i] - '0';
        ret %= K;
    }

    return ret;
}

void init(){
    tenMods[0] = 1 % K;

    for (int i = 1; i < 51; i++){
        tenMods[i] = tenMods[i - 1] * 10 % K;
    }

    for (int i = 0; i < N; i++){
        mods[i] = getMod(numStr[i]);
        sizes[i] = numStr[i].length();
        total *= i + 1;
    }

    fill_n(&cache[0][0], (1 << 15) * 100, -1);
}

ll solve(int state, ll cur){
    if (state == (1 << N) - 1) return (cur % K == 0);

    ll &ret = cache[state][cur];

    if (ret != -1) return ret;

    ret = 0;

    for (int i = 0; i < N; i++){
        if (state & (1 << i)) continue;

        ll next = (cur * tenMods[sizes[i]] + mods[i]) % K;

        ret += solve(state | 1 << i, next);
    }

    return ret;
}

ll GCD(ll a, ll b){
    if (b == 0) return a;

    return GCD(b, a % b);
}

void solution(){
    input();
    init();

    ll p = solve(0, 0);
    ll gcd = GCD(total, p);
    cout << p / gcd << "/" << total / gcd;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    solution();
}