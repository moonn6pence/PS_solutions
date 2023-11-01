#include <bits/stdc++.h>

using namespace std;
const int INF = 987654321;
int N, graph[20][20], dist[20][20];

int solve(){
    for (int src = 0; src < N; src++){
        for (int dest = src + 1; dest < N; dest++) {
            for (int via = 0; via < N; via++){
                if (via == src || via == dest) continue;
                if (dist[src][dest] != dist[src][via] + dist[via][dest]) continue;
                graph[src][dest] = graph[dest][src] = INF;
            }
        }
    }

    int ret = 0;

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (graph[i][j] != INF) ret += graph[i][j];
        }
    }

    for (int via = 0; via < N; via++){
        for (int src = 0; src < N; src++){
            for (int dest = src + 1; dest < N; dest++) {

                if (graph[src][via] == INF || graph[via][dest] == INF) continue;
                int cost = graph[src][via] + graph[via][dest];
                if (graph[src][dest] <= cost) continue;
                graph[src][dest] = graph[dest][src] = cost;
            }
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (graph[i][j] != dist[i][j]) return -1;
        }
    }

    return ret;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> dist[i][j];
            graph[i][j] = dist[i][j];
        }
    }

    cout << solve();
}