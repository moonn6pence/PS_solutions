#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
const int INF = 2e9;
int N, K;
int T[10][10], dist[10][10], cache[1 << 10][10];

void input(){
    cin >> N >> K;

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cin >> T[i][j];
        }
    }
}

void dijkstra(int src){
    priority_queue<pii, vector<pii>, greater<pii>> PQ;
    dist[src][src] = 0;
    PQ.push({0, src});

    while(!PQ.empty()){
        int cost = PQ.top().first, via = PQ.top().second;
        PQ.pop();

        if(dist[src][via] < cost) continue;

        for (int next = 0; next < N; next++){
            int newCost = cost + T[via][next];

            if (newCost < dist[src][next]){
                dist[src][next] = newCost;
                PQ.push({newCost, next});
            }
        }
    }
}

void dijkstraAll(){
    fill(&dist[0][0], &dist[N - 1][N], INF);

    for (int i = 0; i < N; i++) dijkstra(i);
}

int backtrack(int state, int node){
    if(state == (1 << N) - 1) return 0;

    int &ret = cache[state][node];

    if (ret != -1) return ret;

    ret = INF;

    for (int i = 0; i < N; i++){
        if (!(state & (1 << i))){
            ret = min(ret, backtrack(state | (1 << i), i) + dist[node][i]);
        }
    }

    return ret;
}

void solve(){
    dijkstraAll();
    fill(&cache[0][0], &cache[(1 << 10) - 1][10], -1);
    cout << backtrack((1 << K), K);
}

void solution(){
    input();
    solve();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    solution();
}