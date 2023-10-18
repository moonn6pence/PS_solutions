#include <bits/stdc++.h>
using namespace std;
int main(){
    long long N, L, S;
    cin >> N >> L;

    for (int l = L; l <= 100; l++) {
        S = N / l - (l - 1) / 2;

        if (S < 0) break;

        if (N == (S * 2 + l - 1) * l / 2) {
            for (int i = S; i < S + l; i++) cout << i << ' ';
            return 0;
        }
    }

    cout << -1;
    return 0;
}