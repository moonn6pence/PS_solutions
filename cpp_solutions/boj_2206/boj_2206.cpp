#include <algorithm>
#include <queue>
#include <iostream>
#include <tuple>

using namespace std;

typedef tuple<int, int, bool> tiib;

int N, M;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
string map[1000];
int visited[1000][1000][2];

void input(){
    cin >> N >> M;
    for (int i = 0; i < N; i++){
        cin >> map[i];
    }
}

int bfs(){
    queue<tiib> order;

    visited[0][0][0] = 1;
    order.push({0, 0, false});
    while (!order.empty()){
        tiib cur = order.front();
        order.pop();
        int curx = get<0>(cur), cury = get<1>(cur);
        bool isBroken = get<2>(cur);

        if(curx == N-1 && cury == M-1){
            return visited[curx][cury][isBroken];
        }

        for (int i = 0; i < 4; i++){
            int nx = curx + dx[i], ny = cury + dy[i];
            if (nx < 0 || nx >= N) continue;
            if (ny < 0 || ny >= M) continue;
            if (visited[nx][ny][isBroken] != 0) continue;

            if (map[nx][ny] == '0'){
                order.push({nx, ny, isBroken});
                visited[nx][ny][isBroken] = visited[curx][cury][isBroken] + 1;
            }else if (map[nx][ny] == '1' && !isBroken){
                order.push({nx, ny, true});
                visited[nx][ny][1] = visited[curx][cury][isBroken] + 1;
            }
        }
    }

    return -1;
}

void solution(){
    input();
    cout << bfs() << '\n';
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    solution();

    return 0;
}