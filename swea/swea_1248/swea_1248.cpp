#include <bits/stdc++.h>
 
using namespace std;
int V, E;
vector<int> adj[10001];
int parent[10001][15], level[10001], dp[10001];
int q1, q2, maxLevel;
 
void init(){
    for (int i = 1; i <= V; i++){
        if (!adj[i].empty()) adj[i].clear();
    }
}
 
void input(){
    cin >> V >> E >> q1 >> q2;
    int p, c;
    maxLevel = (int)floor(log2(V));
 
    for (int i = 0; i < E; i++){
        cin >> p >> c;
        parent[c][0] = p;
        adj[p].push_back(c);
    }
}
 
void setTree(int node, int pnode, int lv){
    level[node] = lv;
 
    for (int i = 1; i <= maxLevel; i++){
        parent[node][i] = parent[parent[node][i - 1]][i - 1];
    }
 
    dp[node] = 1;
 
    for (int i = 0; i < (int)adj[node].size(); i++){
        int child = adj[node][i];
        setTree(child, node, lv + 1);
        dp[node] += dp[child];
    }
}
 
int LCA(int a, int b){
    if (a == 1 || b == 1) return 1;
 
    if (level[a] < level[b]) swap(a, b);
 
    while (level[a] != level[b]){
        for (int i = maxLevel; i >= 0; i--){
            if (level[parent[a][i]] >= level[b])
                a = parent[a][i];
        }
    }
 
    int ret = a;
 
    if (a != b){
        for (int i = maxLevel; i >= 0; i--){
            if (parent[a][i] != parent[b][i]){
                a = parent[a][i];
                b = parent[b][i];
            }
            ret = parent[a][i];
        }
    }
 
    return ret;
}
 
void solution(){
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++){
        input();
        setTree(1, 0, 1);
        int root = LCA(q1, q2);
        cout << '#' << i << ' ' << root << ' ' <<  dp[root] << '\n';
        if (i != T) init();
    }
}
 
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
 
    solution();
}