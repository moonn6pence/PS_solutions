#include <iostream>

using namespace std;
typedef long long ll;

int main(){
    ll ans = 1, base,idx,mod;
    cin >> base >> idx >> mod;

    while(idx) {
        if (idx & 1) ans = ans * base % mod;
        base = base * base % mod;
        idx >>= 1;
    }
    cout << ans;
}