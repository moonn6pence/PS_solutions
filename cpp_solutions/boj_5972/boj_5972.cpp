#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
typedef pair<int, int> pii;
const int INF = 1e9;
int N, M;
vector<vector<pii>> graph(50001);
vector<int> dist(500001, INF);

void input(){
    cin >> N >> M;
    int u, v, cost;

    for (int i = 0; i < M; i++){
        cin >> u >> v >> cost;
        graph[u].push_back({v, cost});
        graph[v].push_back({u, cost});
    }
}

void dijkstra(int src){
    dist[src] = 0;
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({0, src});

    while(!pq.empty()){
        int cost = pq.top().first, via = pq.top().second;
        pq.pop();

        if(dist[via] < cost) continue;

        for(auto &iter : graph[via]){
            int next = iter.first, newCost = iter.second + cost;
            if(newCost < dist[next]){
                dist[next] = newCost;
                pq.push({newCost, next});
            }
        }
    }
}

void solution(){
    input();
    dijkstra(1);
    cout << dist[N];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    solution();
}