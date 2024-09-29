#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <vector>

using namespace std;
typedef pair<int,int> pii;
vector<string> graph;
int N,M;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
pii src, dest;


void input(){
    cin >> N >> M;
    graph.resize(N);
    cin >> src.first >> src.second;
    cin >> dest.first >> dest.second;

    src.first--;src.second--;

    for(int i=0;i<N;i++) cin >> graph[i];
}

bool bfs(){
    bool visited[300][300];
    fill(&visited[0][0],&visited[299][300],false);

    queue<pii> order;
    order.push(src);
    visited[src.first][src.second] = true;

    while(!order.empty()){
        int x,y; tie(x,y) = order.front();
        order.pop();
        
        for(int i=0;i<4;i++){
            int nx=x+dx[i],ny=y+dy[i];

            if (nx<0||nx>=N||ny<0||ny>=M||visited[nx][ny]) continue;

            if (graph[nx][ny] == '1') {
                graph[nx][ny] = '0';
                visited[nx][ny] = true;
            } else if (graph[nx][ny] == '#'){
                return true;
            } else {
                order.push({nx,ny});
                visited[nx][ny] = true;
            }
        }
    }

    return false;
}

void solution(){
    int cnt=0;

    while(1){
        cnt++;
        if (bfs()) break;
    }

    cout << cnt;
}

int main(){
    input();
    solution();
}