#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int N, M;
vector<int> v;

void input(){
    cin >> N >> M;
    int x;

    for (int i = 0; i < N; i++) {
        cin >> x;
        v.push_back(x);
    }
}

void solve(int state, int cnt, int begin){
    if (cnt == M) {
        for (int i = 0; i < N; i++){
            if (!((1 << i) & state)) continue;
            cout << v[i] << ' ';
        }
        cout << '\n';
    }

    if (N - begin < M - cnt) return;

    int latest = -1;

    for (int i = begin; i < N; i++){
        if (latest == v[i]) continue;

        solve(state | (1 << i), cnt + 1, i + 1);
        latest = v[i];
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    input();
    sort(v.begin(), v.end());
    solve(0, 0, 0);
}