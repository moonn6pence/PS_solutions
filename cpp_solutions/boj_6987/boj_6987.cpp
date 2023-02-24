#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll result;
ll r[6] = {1'000'000'000'000'000, 1'000'000'000'000, 1'000'000'000, 1'000'000, 1'000, 1};
int matchup[15][15] = {{0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5}, {1, 2}, {1, 3}, {1, 4}, {1, 5}, {2, 3}, {2, 4}, {2, 5}, {3, 4}, {3, 5}, {4, 5}};

void input(){
    result = 0;
    for (int j = 0; j < 18; j++){
        int num;
        cin >> num;
        result = result * 10 + num;
    }
}

bool solve(int n, ll state){
    if (n == 15) return state == result;

    if (state > result) return false;

    int x = matchup[n][0], y = matchup[n][1];

    ll win = state + 100 * r[x] + r[y];
    ll draw = state + 10 * r[x] + 10 * r[y];
    ll lose = state + r[x] + 100 * r[y];

    return solve(n + 1, win) || solve(n + 1, draw) || solve(n + 1, lose);
}

void solution(){
    for (int i = 0; i < 4; i++){
        input();
        cout << solve(0, 0) << ' ';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    solution();
}