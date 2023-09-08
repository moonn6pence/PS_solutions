#include <bits/stdc++.h>

using namespace std;
int N, M;
vector<int> v;
int selection[7];

void input(){
    cin >> N >> M;
    int x;

    for (int i = 0; i < N; i++) {
        cin >> x;
        v.push_back(x);
    }
}

void printSelection(){
    for (int i = 0; i < M; i++) {
        cout << selection[i] << ' ';
    }
    cout << '\n';
}

void solve(int cnt){

    if (cnt == M){
        printSelection();
        return;
    }

    for (int i = 0; i < N; i++){
        selection[cnt] = v[i];
        solve(cnt + 1);
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();
    sort(v.begin(), v.end());
    solve(0);
}