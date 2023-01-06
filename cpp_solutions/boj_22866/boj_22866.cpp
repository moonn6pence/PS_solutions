#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
int N;
int H[100002];
vector<pii> cache(100002); // {count, index}
stack<pii> s; // {height, index}

void input(){
    cin >> N;
    for (int i = 1; i <= N; i++){
        cin >> H[i];
    }
    H[0] = 1e9;
    H[N + 1] = 1e9;
}

void solve(){
    s.push({H[0], 0});

    for (int i = 1; i <= N; i++){
        while (!s.empty() && s.top().first <= H[i]){
            s.pop();
        }

        if ( s.size() > 1){
            cache[i] = {s.size() - 1, s.top().second};
        } else {
            cache[i] = {0, -1e9};
        }

        s.push({H[i], i});
    }

    s = stack<pii>();
    s.push({H[N + 1], N + 1});

    for (int i = N; i > 0; i--){
        while (!s.empty() && s.top().first <= H[i]){
            s.pop();
        }

        cache[i].first += s.size() - 1;
        if (s.size() > 1 && i - cache[i].second > s.top().second - i){
            cache[i].second = s.top().second;
        }



        s.push({H[i], i});
    }
}

void output(){
    for (int i = 1; i <= N; i++){
        cout << cache[i].first;
        if(cache[i].first)
            cout << " " << cache[i].second;
        cout << '\n';
    }
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