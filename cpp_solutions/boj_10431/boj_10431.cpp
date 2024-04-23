#include <bits/stdc++.h>

using namespace std;
int P, h[20];

void input(){
    int T; cin >> T;
    for (int i = 0; i < 20; i++) cin >> h[i];
}

int solve(){
    int cnt = 0;

    for (int i = 1; i < 20; i++) {
        int idx = i;

        while (h[idx-1] > h[idx]) {
            h[idx-1] ^= h[idx];
            h[idx] ^= h[idx-1];
            h[idx-1] ^= h[idx];
            cnt++; idx--;
        }
    }

    return cnt;
}

void solution(){

    cin >> P;

    for (int i = 0; i < P; i++){
        input();
        cout << i + 1 << ' ' << solve() << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    solution();
}