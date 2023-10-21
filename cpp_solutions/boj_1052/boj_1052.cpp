#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N, K, bit = 0, tmp;
    cin >> N >> K;

    while (N >= (1 << bit)) bit++;

    while (K > 0 && bit > 0) {
        if (N & (1 << bit)) {
            N ^= tmp = 1 << bit;
            K--;
        }
        bit--;
    }

    if (N == 0) cout << 0;
    else cout << tmp - N;
}