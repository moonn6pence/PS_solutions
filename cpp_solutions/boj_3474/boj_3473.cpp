#include <iostream>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T; cin >> T;

    while(T--){
        int cnt = 0, base = 5, N; cin >> N;

        while (base <= N){
            cnt += N/base;
            base *= 5;
        }

        cout << cnt << '\n';
    }
}