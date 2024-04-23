#include <bits/stdc++.h>

using namespace std;
int N, new_score, P;
vector<int> leaderboard;

void input(){
    cin >> N >> new_score >> P;

    int tmp;

    for (int i = 0; i < N; i++){
        cin >> tmp;
        leaderboard.push_back(tmp);
    }
}

int solve(){

    if (N == 0) return 1;
    else if (N == P && new_score <= leaderboard[N - 1]) return -1;
    else {
        for (int i = 0; i < N; i++){
            if (leaderboard[i] <= new_score) return i + 1;
        }
    }

    return N + 1;
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