#include <bits/stdc++.h>

using namespace std;
int N;
vector<vector<int>> adj;
vector<int> sup;
vector<vector<int>> cache;

void input(){
    cin >> N;

    adj.assign(N + 1, vector<int>());
    sup.assign(N + 1, 0);
    cache.assign(N + 1, vector<int>(2, -1));

    for (int i = 1; i <= N; i++) cin >> sup[i];

    int a, b;
    for (int i = 0; i < N - 1; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
}

int solve(int node, int from, bool isGreat){
    int &ret = cache[node][isGreat];

    if (ret != -1) return ret;

    int childSize = adj[node].size();

    int ans = 0;

    if (!isGreat){
        for (int i = 0; i < childSize; i++){
            int child = adj[node][i];
            if (child == from) continue;
            ans += max(solve(child, node, true), solve(child, node, false));
        }

        ret = ans;
    } else {
        for (int i = 0; i < childSize; i++){
            int child = adj[node][i];
            if (child == from) continue;
            ans += solve(child, node, false);
        }

        ret = ans + sup[node];
    }

    return ret;
}

void solution(){
    input();
    cout << max(solve(1, 0, true), solve(1, 0, false));
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    solution();
}