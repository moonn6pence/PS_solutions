#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
const int INF = 2e9;
typedef pair<int,int> pii;
typedef pair<int, pii> elem;

int N,D,dist[10001];
vector<pii> edge[10001];

void input(){
    cin >> N >> D;

    for(int i=0;i<N;i++){
        int s,e,c;
        cin >> s >> e >> c;
        edge[s].push_back({e,c});
    }

    for(int i=0;i<D;i++) edge[i].push_back({i+1,1});
}

int dijkstra(){
    priority_queue<pii> pq;
    pq.push({0,0});
    dist[0] = 0;

    while(!pq.empty()){
        int cur_cost = -pq.top().first;
        int via = pq.top().second;
        pq.pop();

        if (dist[via] < cur_cost) continue;

        for(pii it : edge[via]){
            int dest, cost; tie(dest,cost) = it;

            int next_cost = cur_cost + cost;
            if (next_cost < dist[dest]) {
                dist[dest] = next_cost;
                pq.push({-next_cost, dest});
            }
        }
    }

    return dist[D];
}

void solution(){
    input();
    fill(&dist[0],&dist[10001],INF);
    cout << dijkstra();
}

int main(){
    solution();
}