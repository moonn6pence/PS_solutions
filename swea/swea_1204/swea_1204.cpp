#include <bits/stdc++.h>

using namespace std;
int N;
int counter[101];

void input(){
    int tmp;
    for (int i = 0; i < 1000; i++){
        cin >> tmp;
        counter[tmp]++;
    }
}

int solve(){
    int ret = 1;

    for (int i = 2; i < 101; i++){
        if (counter[i] >= counter[ret]) ret = i;
        if (counter[i] > 500) return i;
    }

    return ret;
}

void solution(){
    int T, i;
    cin >> T;

    while(T--){
        cin >> i;
        fill(&counter[0], &counter[101], 0);
        input();
        solve();
        cout << '#' << i << ' ' << solve() << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    solution();
}