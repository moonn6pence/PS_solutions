#include <iostream>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;
typedef pair<int,int> pii;
typedef pair<int, pii> info;
const int INF = 2e9;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int N,graph[50][50];

void input(){
    cin >> N;
    for(int i=0;i<N;i++){
        string ss; cin >> ss;
        for(int j=0;j<N;j++) {
            graph[i][j] = (ss[j] == '0');
        }
    }
}

int dijkstra(){
    
    int dist[50][50];
    fill(&dist[0][0],&dist[49][50],INF);

    priority_queue<info> pq;

    dist[0][0] = 0;
    pq.push({0,{0,0}});

    while(!pq.empty()){
        int cost = -pq.top().first;
        int x,y; tie(x,y)= pq.top().second;
        pq.pop();

        if (dist[x][y] < cost) continue;

        for(int i=0;i<4;i++){
            int nx=x+dx[i],ny=y+dy[i];

            if(nx<0||nx>=N||ny<0||ny>=N) continue;

            int next_cost = cost + graph[nx][ny];
            if (next_cost >= dist[nx][ny]) continue;
            dist[nx][ny]=next_cost;
            pq.push({-next_cost,{nx,ny}});
        }
    }

    return dist[N-1][N-1];

}

void solution(){
    cout << dijkstra();
}

int main(){
    input();
    solution();
}