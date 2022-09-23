#include <algorithm>
#include <vector>
#include <queue>
#define INF 1e9
using namespace std;

typedef pair<int,int> pii;
typedef vector<vector<int>> vvi;

int dist[3][201];
vector<pii> graph[201];

void init(int n,vvi fares){
    for (int i = 0; i < fares.size();i++){
        graph[fares[i][0]].push_back({fares[i][1], fares[i][2]});
        graph[fares[i][1]].push_back({fares[i][0], fares[i][2]});
    }

    for (int type = 0; type < 3; type++){
        for (int i = 1; i <= n; i++){
            dist[type][i] = INF;
        }
    }
    return;
}

void dijkstra(int start,int type){
    priority_queue<pii> pq;
    pq.push(make_pair(0, start));
    dist[type][start] = 0;

    while(pq.empty() == 0){
        int viaCost = -pq.top().first;
        int via = pq.top().second;
        pq.pop();

        if(dist[type][via] < viaCost)
            continue;

        for (int i = 0; i < graph[via].size(); i++){
            int next = graph[via][i].first;
            int newCost = viaCost + graph[via][i].second;

            if(dist[type][next] > newCost){
                dist[type][next] = newCost;
                pq.push(make_pair(-newCost, next));
            }
        }
    }
}

void solve(int s,int a,int b){
    dijkstra(s, 0);
    dijkstra(a, 1);
    dijkstra(b, 2);

    return;
}

int findMinSum(int n){
    int ret = INF;
    for (int i = 1; i <= n; i++){
        if(dist[0][i]==INF||dist[1][i]==INF||dist[2][i]==INF)
            continue;
        ret = min(ret, dist[0][i]+dist[1][i]+dist[2][i]);
    }
    return ret;
}

int solution(int n, int s, int a, int b, vvi fares) {
    int answer = INF;

    init(n, fares);
    solve(s, a, b);
    answer = findMinSum(n);
    return answer;
}