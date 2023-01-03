#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

string gear[5];
int K;
vector<pii> spin;
vector<pii> LR = {{-1, -1}, {6, 2}, {6, 2}, {6, 2}, {6, 2}};

void input(){
    int order, dir;

    for (int i = 1; i < 5; i++) cin >> gear[i];

    cin >> K;

    for (int i = 0; i < K; i++){
        cin >> order >> dir;
        spin.push_back({order, dir});
    }
}

void rotate(int cur, int dir, int from){
    int before = cur - 1, next = cur + 1;

    if (before != from && before > 0 && gear[before][LR[before].second] != gear[cur][LR[cur].first]){
        rotate(before, -dir, cur);
    }

    if (next != from && next < 5 && gear[cur][LR[cur].second] != gear[next][LR[next].first]){
        rotate(next, -dir, cur);
    }

    if (dir > 0){
        LR[cur].first = (LR[cur].first + 7) % 8;
        LR[cur].second = (LR[cur].second + 7) % 8;
    } else {
        LR[cur].first = (LR[cur].first + 9) % 8;
        LR[cur].second = (LR[cur].second + 9) % 8;
    }
}

void solve(){
    for (int i = 0; i < K; i++){
        rotate(spin[i].first, spin[i].second, 0);
    }
}

void output(){
    int ans = 0;

    for (int score = 1, i = 1; i < 5; i++){
        ans += score * (gear[i][(LR[i].first + 2) % 8] == '1');
        score = score << 1;
    }

    cout << ans << '\n';
}

void solution(){
    input();
    solve();
    output();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    solution();
}