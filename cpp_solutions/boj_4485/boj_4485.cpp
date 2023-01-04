#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, pii> pipii;
const int INF = 1e9;
int N;
int graph[125][125], dist[125][125];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void init(){
    fill(&dist[0][0], &dist[124][125], INF);
}

void input(){
    cin >> N;

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cin >> graph[i][j];
        }
    }
}

int dijkstra(int srcx, int srcy){
    dist[srcx][srcy] = graph[srcx][srcy];
    priority_queue<pipii, vector<pipii>, greater<pipii>> pq;
    pq.push({dist[srcx][srcy], {srcx, srcy}});

    while(!pq.empty()){
        int cost = pq.top().first;
        int curx = pq.top().second.first, cury = pq.top().second.second;
        pq.pop();

        if (dist[curx][cury] < cost) continue;

        for (int i = 0; i < 4; i++){
            int nx = curx + dx[i], ny = cury + dy[i];
            if (nx < 0 || nx >= N) continue;
            if (ny < 0 || ny >= N) continue;

            int newCost = graph[nx][ny] + cost;
            if (dist[nx][ny] > newCost){
                dist[nx][ny] = newCost;
                pq.push({newCost, {nx, ny}});
            }
        }
    }

    return dist[N - 1][N - 1];
}

void solution(){
    int tc = 0;

    while(++tc){
        init();
        input();
        if (N == 0) break;
        cout << "Problem " << tc << ": " << dijkstra(0, 0) << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    solution();
}