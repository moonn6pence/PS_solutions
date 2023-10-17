#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;
const int MAX_N = 300001;
const int INF = 987654321;
typedef pair<int, int> pii;
int N, M, K, X;
int dist[MAX_N];
vector<int> graph[MAX_N];

void dijkstra(int src) {
    fill(&dist[0], &dist[MAX_N], INF);

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[src] = 0;
    pq.push({0, src});

    while(!pq.empty()) {
        int cost, via;
        tie(cost, via) = pq.top();
        pq.pop();

        if (dist[via] < cost) continue;

        for(int node : graph[via]) {
            int newCost = cost + 1;

            if (dist[node] > newCost) {
                dist[node] = newCost;
                pq.push({newCost, node});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M >> K >> X;

    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
    }

    dijkstra(X);

    vector<int> answers;

    for (int i = 1; i <= N; i++) {
        if (dist[i] == K) answers.push_back(i);
    }

    if (answers.size() == 0) cout << -1;
    else for(int node : answers) cout << node << '\n';
}