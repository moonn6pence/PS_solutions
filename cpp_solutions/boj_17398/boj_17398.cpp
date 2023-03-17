#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef long long ll;
int N, M, Q;
vector<ll> parent;
vector<pii> edge;
vector<bool> isQuery;
stack<int> queryStack;

int find(int x){
    if (parent[x] < 0) return x;
    return parent[x] = find(parent[x]);
}

void unionSet(int a, int b){
    a = find(a);
    b = find(b);

    if (a == b) return;

    parent[a] += parent[b];
    parent[b] = a;
}

void input(){
    cin >> N >> M >> Q;

    parent.assign(N + 1, -1);
    edge.assign(M + 1, pii());
    isQuery.assign(M + 1, false);

    int a, b;
    for (int i = 1; i <= M; i++) {
        cin >> a >> b;
        edge[i] = {a, b};
    }
}

ll solve(){
    int idx;
    ll ret = 0;
    for (int i = 0; i < Q; i++) {
        cin >> idx;
        isQuery[idx] = true;
        queryStack.push(idx);
    }

    for (int i = 1; i <= M; i++){
        if (isQuery[i]) continue;
        unionSet(edge[i].first, edge[i].second);
    }

    while (!queryStack.empty()){
        idx = queryStack.top();
        queryStack.pop();

        int a = edge[idx].first, b = edge[idx].second;
        int rootA = find(a), rootB = find(b);

        if (rootA == rootB) continue;

        ret += parent[rootA] * parent[rootB];
        unionSet(rootA, rootB);
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