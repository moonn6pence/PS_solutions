#include <iostream>
#include <vector>

using namespace std;
int N, M;
int parent[50001], level[50001];
vector<int> adj[50001];

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
    if (level[a] < level[b]) swap(a, b);
    
    while (level[a] != level[b]){
        a = parent[a];
    }
    
    while (a != b){
        a = parent[a];
        b = parent[b];
    }
    
    return a;
}

void setTree(int node, int pnode){
    parent[node] = pnode;
    level[node] = level[pnode] + 1;
    
    for (int i = 0; i < adj[node].size(); i++){
        int child = adj[node][i];
        if (child == pnode) continue;
        setTree(child, node);
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
    setTree(1,0);
    solve();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    solution();
}
