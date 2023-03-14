#include <bits/stdc++.h>

using namespace std;
int N;
int dist[3001];
vector<int> adj[3001];
bool visited[3001], isCycle[3001];

void input(){
    cin >> N;

    int a, b;
    for (int i = 0; i < N; i++){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
}

int DFS(int node, int from, stack<int> &stk){
    if(visited[node]) return node;

    visited[node] = true;
    stk.push(node);

    for (int i = 0; i < adj[node].size(); i++){
        if (adj[node][i] == from) continue;
        int ret = DFS(adj[node][i], node, stk);
        if (ret == -1){
            stk.pop();
            continue;
        }

        return ret;
    }

    return -1;
}

void findCycle(){
    stack<int> stk;

    int node = DFS(1, 0, stk);

    while (true){
        int top = stk.top();
        stk.pop();

        isCycle[top] = true;
        if(top == node) break;
    }
}

void findDist(int node, int from, int d){
    if (dist[node] != -1) return;

    if (isCycle[node]) dist[node] = d = 0;
    else dist[node] = d;

    for (int i = 0; i < adj[node].size(); i++){
        if (adj[node][i] == from) continue;
        findDist(adj[node][i], node, d + 1);
    }
}

void solution(){
    input();
    findCycle();
    fill(&dist[0], &dist[3001], -1);

    for (int i = 1; i <= N; i++){
        if(isCycle[i]){
            findDist(i, 0, 0);
            break;
        }
    }

    for (int i = 1; i <= N; i++) cout << dist[i] << ' ';

    cout << '\n';
    for (int i = 1; i <= N;i++)
        cout << isCycle[i] << ' ';
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    solution();
}