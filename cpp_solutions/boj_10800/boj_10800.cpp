#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
const int MAX = 200000;
int N;
vector<pii> inputs;
vector<pii> cs;
vector<pii> sc;
int cspsum[200001], scpsum[200001];

void input(){
    cin >> N;

    int c, s;
    for (int i = 0; i < N; i++) {
        cin >> c >> s;
        inputs.push_back({c, s});
        cs.push_back({c, s});
        sc.push_back({s, c});
    }
}

void solve(){
    sort(cs.begin(), cs.end());
    sort(sc.begin(), sc.end());

    for (int i = 1; i <= cs.size(); i++){
        cspsum[i] = cspsum[i - 1] + cs[i - 1].second;
        scpsum[i] = scpsum[i - 1] + sc[i - 1].first;
    }
}

void output(){
    for(auto& [color, size] : inputs){
        int scUpperBound = upper_bound(cs.begin(), cs.end(), pii(color, size - 1)) - cs.begin();
        int scLowerBound = lower_bound(cs.begin(), cs.end(), pii(color, 1)) - cs.begin();
        int smallerSize = upper_bound(sc.begin(), sc.end(), pii(size - 1, MAX)) - sc.begin();

        int ret = scpsum[smallerSize] - cspsum[scUpperBound] + cspsum[scLowerBound];
        cout << ret << '\n';
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