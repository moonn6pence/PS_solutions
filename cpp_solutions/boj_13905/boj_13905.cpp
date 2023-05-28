#include <bits/stdc++.h>

using namespace std;
const int MAX = 100000;
typedef pair<int, int> pii;
typedef pair<int, pii> edge;
int N, M, s, e;
vector<pii> W[MAX + 1];
int parent[MAX + 1];
priority_queue<edge> edges;

int find(int x){
    if (parent[x] == x) return x;

    return parent[x] = find(parent[x]);
}

void union_set(int a, int b){
    a = find(a);
    b = find(b);

    if (a < b) parent[b] = a;
    else parent[a] = b;
}

void input(){
    int h1, h2, k;

    cin >> N >> M >> s >> e;
    for (int i = 0; i < M; i++){
        cin >> h1 >> h2 >> k;
        edges.push({k, {h1, h2}});
    }
}

int kruskal(){
    int cost, a, b;
    int ret = 1000000;

    while(!edges.empty()){
        cost = edges.top().first;
        tie(a, b) = edges.top().second;
        edges.pop();

        if (find(a) == find(b)) continue;

        union_set(a, b);
        ret = min(ret, cost);

        if (find(s) == find(e)) return ret;
    }

    return 0;
}

void solution(){    
    input();
    for (int i = 1; i <= MAX; i++){
        parent[i] = i;
    }

    cout << kruskal();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    solution();
}