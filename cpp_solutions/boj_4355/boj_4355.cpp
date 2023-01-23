#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int N;

int input(){
    cin >> N;

    return N;
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
    if (N == 1) return 0;

    ll ret = 1, base = 1;

    while (N > 1){
        int exp = 0;
        base++;
        if (N % base) continue;

        while (N % base == 0){
            N /= base;
            exp++;
        }

        ret *= getEulersPhi(base, exp);
    }

    return ret;
}

void solution(){
    while(input()){
        cout << solve() << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    solution();
}