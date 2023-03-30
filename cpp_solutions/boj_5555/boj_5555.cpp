#include <bits/stdc++.h>

using namespace std;
string pattern;
int N;
string rings[100];

void input(){
    cin >> pattern;
    cin >> N;

    for (int i = 0; i < N; i++){
        cin >> rings[i];
        rings[i] += rings[i];
    }
}

int solve(){
    int ret = 0;
    regex re(pattern);

    for (int i = 0; i < N; i++){
        ret += regex_search(rings[i], re);
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