#include <iostream>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int, int> pii;
int N,M;
string graph[100];
int visited[100][100];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

int bfs(){
    queue<pii> order;
    order.push({0,0});
    visited[0][0] = 1;

    while(!order.empty()){
        int x, y;
        tie(x, y) = order.front();
        order.pop();

        for(int i=0;i<4;i++){
            int nx = x + dx[i], ny = y + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (graph[nx][ny] == '0') continue;
            if (visited[nx][ny]) continue;

            order.push({nx, ny});
            visited[nx][ny] = visited[x][y] + 1;
        }
    }

    return visited[N-1][M-1];

}

int main(){
    cin >> N >> M;

    for(int i=0;i<N;i++) cin >> graph[i];

    cout << bfs();
}