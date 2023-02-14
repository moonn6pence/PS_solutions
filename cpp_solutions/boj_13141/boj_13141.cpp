#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;
const int INF = 987654321;
int N, M;
int graph[201][201][2];
int selfGraph[201];
int dist[201][201];

void input(){
    cin >> N >> M;

    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= N; j++){
            if (i == j) continue;
            dist[i][j] = INF;
        }
    }

    int s, e, l;
    for (int i = 0; i < M; i++){
        cin >> s >> e >> l;

        if (s == e) {
            selfGraph[s] = max(selfGraph[s], l);
            continue;
        }

        dist[s][e] = dist[e][s] = min(dist[s][e], l);
        if(graph[s][e][0] < INF) graph[s][e][0] = graph[e][s][0] = min(graph[s][e][0], l);
        else graph[s][e][0] = graph[e][s][0] = l;
        graph[s][e][1] = graph[e][s][1] = max(graph[s][e][1], l);
    }
}

void floyd_warshall(){
    for (int via = 1; via <= N; via++){
        for (int src = 1; src <= N; src++){
            for (int dest = 1; dest <= N; dest++){
                dist[src][dest] = min(dist[src][dest], dist[src][via] + dist[via][dest]);
            }
        }
    }
}

void findMaxPath(){
    double ret = INF;

    for (int src = 1; src <= N; src++){
        double tmp = 0;
        for (int dest = 1; dest <= N; dest++){
            if(selfGraph[dest]) tmp = max(tmp, (double)dist[src][dest] + (double)selfGraph[dest] / 2);

            for (int dest2 = 1; dest2 <= N; dest2++){
                if(!graph[dest][dest2][1] || graph[dest][dest2][0] == graph[dest][dest2][1]) continue;

                double further = (double)max(dist[src][dest], dist[src][dest2]);
                double restTime = ((double)(graph[dest][dest2][1] - abs(dist[src][dest] - dist[src][dest2]))) / 2;
                tmp = max(tmp, further + restTime);
            }
        }
        ret = min(ret, tmp);
    }

    cout << ret;
}

void solution(){
    input();
    floyd_warshall();
    findMaxPath();
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cout << fixed;
    cout.precision(1);
    solution();
}