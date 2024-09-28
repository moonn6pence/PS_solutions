#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int,int> pii;

int N,M,safe_zone = 0;
int node[8][8];
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
vector<pii> virus;

void input(){
    cin >> N >> M;

    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            cin >> node[i][j];
            if (node[i][j] == 2) virus.push_back({i,j});
            else if (node[i][j] == 0) safe_zone++;
        }
    }
}

int simulate(){

    int ret = safe_zone - 3;

    bool visited[8][8];
    fill(&visited[0][0], &visited[7][8], false);

    queue<pii> order;
    for(pii it : virus) {
        order.push(it);
        visited[it.first][it.second] = true;
    }

    while(!order.empty()){
        int x, y;
        tie(x,y) = order.front();
        order.pop();

        for(int i=0;i<4;i++){
            int nx = x + dx[i], ny = y + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (node[nx][ny] != 0 || visited[nx][ny]) continue;

            order.push({nx,ny});
            visited[nx][ny] = true;
            ret--;
        }
    }

    return ret;
}

int solve(int wall_cnt, int x, int y){
    if (wall_cnt == 3) return simulate();

    int  ret = 0;

    for(int i = x; i < N; i++) {
        for(int j = 0; j < M; j++){
            if (i == x && j < y) continue;

            if (node[i][j] == 0) {
                node[i][j] = 1;
                ret = max(ret, solve(wall_cnt + 1, i, j));
                node[i][j] = 0;
            }
        }
    }

    return ret;
}

void solution(){
    input();
    cout << solve(0,0,-1);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solution();
}