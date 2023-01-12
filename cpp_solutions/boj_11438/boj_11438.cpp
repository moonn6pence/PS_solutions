#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
int N, M, maxLevel;
int parent[100001][18], level[100001];
vector<int> adj[100001];

void input(){
    cin >> N;
    
    int a, b;
    
    for (int i = 1; i < N; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
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

void setTree(int node, int pnode, int lv){
    parent[node][0] = pnode;
    level[node] = lv;
    
    for (int i = 1; i <= maxLevel; i++){
        parent[node][i] = parent[parent[node][i - 1]][i - 1];
    }
    
    for (int i = 0; i < adj[node].size(); i++){
        int child = adj[node][i];
        if (child == pnode) continue;
        setTree(child, node, lv + 1);
    }
}

void solve(){
    cin >> M;
    
    int a, b;
    while (M--){
        cin >> a >> b;
        cout << LCA(a, b) << '\n';
    }
}

void solution(){
    input();
    maxLevel = (int)floor(log2(100001));
    setTree(1, 0, 1);
    solve();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    solution();
}
