#include <iostream>
#include <algorithm>
#include <queue>
#include <string>

using namespace std;

typedef pair<int,int> pii;
typedef pair<pii,bool> elem;
int R,C;
vector<string> maze;

void input(){
    cin >> R >> C;
    maze.resize(R);
    for(int i=0;i<R;i++) cin >> maze[i];
}

void scan(queue<elem> &order, int visited[][1000]){
    for(int i=0;i<R;i++) {
        for(int j=0;j<C;j++){
            if(maze[i][j]=='F') {
                order.push({{i,j},false});
                visited[i][j] = 1;
            }
        }
    }

    for(int i=0;i<R;i++) {
        for(int j=0;j<C;j++){
            if (maze[i][j]=='J') {
                order.push({{i,j},true});
                visited[i][j] = 1;
                return;
            }
        }
    }
}

void bfs(queue<elem> &order, int visited[][1000]){
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,-1,0,1};

    while(!order.empty()){
        int x,y; tie(x,y) = order.front().first;
        bool isJ = order.front().second;
        order.pop();

        if (isJ && (x == 0 || x == R-1 || y == 0 || y == C-1)) {
            cout << visited[x][y];
            return;
        }

        for(int d=0;d<4;d++){
            int nx=x+dx[d],ny=y+dy[d];
            if (nx<0||nx>=R||ny<0||ny>=C) continue;
            if (maze[nx][ny]=='#' || maze[nx][ny]=='F') continue;
            if (visited[nx][ny]) continue;

            if (isJ && (nx == 0 || nx == R-1 || ny == 0 || ny == C-1)) {
                cout << visited[x][y]+1;
                return;
            }

            order.push({{nx,ny},isJ});
            visited[nx][ny]=visited[x][y]+1;
        }
    }

    cout << "IMPOSSIBLE";
}

void solution(){

    queue<elem> order;
    int visited[1000][1000];
    fill(&visited[0][0],&visited[999][1000],0);

    input();
    scan(order,visited);
    bfs(order,visited);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    solution();
}