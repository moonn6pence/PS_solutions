#include <algorithm>
#include <queue>
#include <iostream>
#include <vector>

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, pii> edge;
int N, parent[301];
priority_queue<edge, vector<edge>, greater<edge>> edges;

int find(int x){
    if (x == parent[x]) return x;

    return parent[x] = find(parent[x]);
}

void _union(int a, int b){
    a = find(a);
    b = find(b);

    if (a < b) parent[b] = a;
    else parent[a] = b;
}

int kruskal(){
    int cost, a, b, ret = 0;

    while(!edges.empty()) {
        cost = edges.top().first;
        tie(a, b) = edges.top().second;
        edges.pop();

        if (find(a) == find(b)) continue;

        ret += cost;
        _union(a, b);
    }

    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int cost;
    cin >> N;

    for (int i = 0; i <= N; i++) {
        parent[i] = i;
    }

    for (int i = 1; i <= N; i++) {
        cin >> cost;
        edges.push({cost, {0, i}});
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> cost;
            edges.push({cost, {i, j}});
        }
    }

    cout << kruskal();
}