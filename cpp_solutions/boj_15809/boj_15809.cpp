#include <bits/stdc++.h>

using namespace std;
int N, M;
int parent[100001];
int army[100001];

void input(){
    cin >> N >> M;

    for (int i = 1; i <= N; i++){
        cin >> army[i];
    }
}

int find(int x){
    if (parent[x] == x) return x;

    return parent[x] = find(parent[x]);
}

void Union(int a, int b){
    a = find(a);
    b = find(b);

    if (army[a] < army[b]) {
        parent[a] = b;
        army[b] += army[a];
        army[a] = 0;
    }
    else {
        parent[b] = a;
        army[a] += army[b];
        army[b] = 0;
    }
}

void fight(int p, int q){
    p = find(p);
    q = find(q);

    if (army[p] == army[q]){
        parent[p] = 0;
        parent[q] = 0;
    } else if (army[p] >= army[q]){
        army[p] -= army[q];
        army[q] = 0;
        Union(p, q);
    } else {
        army[q] -= army[p];
        army[p] = 0;
        Union(p, q);
    }
}

void solve(){
    for (int i = 1; i <= N; i++){
        parent[i] = i;
    }

    for (int i = 0; i < M; i++){
        int O, P, Q;

        cin >> O >> P >> Q;

        if (O == 1) Union(P,Q);
        else fight(P,Q);

        for (int i = 1; i <= 5;i++){
            cout << army[i] << " ";
        }
        cout << '\n';
    }

    int ret = 0;

    vector<int> nations;

    for (int i = 1; i <= N; i++){
        if (i == find(i)){
            ret++;
            nations.push_back(army[i]);
        }
    }

    sort(nations.begin(), nations.end());
    cout << ret << '\n';
    for (auto iter : nations) cout << iter << " ";
}

void solution(){
    input();
    solve();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    solution();
}