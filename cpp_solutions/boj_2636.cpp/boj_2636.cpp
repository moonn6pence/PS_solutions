#include <iostream>
#include <algorithm>
#include <vector>
#include <memory.h>
#include <queue>

using namespace std;

typedef pair<int, int> pii;

int map[100][100], changed[100][100];
bool visited[100][100];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {1, 0, -1, 0};
int N, M, cnt = 0, hour = 0;

void input(){
    cin >> N >> M;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cin >> map[i][j];
            if(map[i][j])
                cnt++;
        }
    }
}

int countCheeseAround(int x, int y){
    int ret = 0;
    for (int i = 0; i < 4; i++){
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || nx >= N) continue;
        if (ny < 0 || ny >= M) continue;
        if (visited[nx][ny]) continue;
        if (map[nx][ny] == 1){
            changed[nx][ny] = 0;
            visited[nx][ny] = true;
            ret++;
        }
    }

    return ret;
}

int meltByBfs(){
    int tmpCnt = 0;

    queue<pii> order;
    order.push({0, 0});
    visited[0][0] = true;

    while (!order.empty()){
        pii cur = order.front();
        order.pop();
        int curx = cur.first, cury = cur.second;

        for (int i = 0; i < 4; i++){
            int nx = curx + dx[i], ny = cury + dy[i];
            if (nx < 0 || nx >= N) continue;
            if (ny < 0 || ny >= M) continue;
            if(visited[nx][ny] || map[nx][ny] == 1) continue;

            tmpCnt += countCheeseAround(nx, ny);

            visited[nx][ny] = true;
            order.push({nx, ny});
        }
    }

    return tmpCnt;
}

void solve(){
    int tmpCnt = cnt;

    while (tmpCnt != 0){
        hour++;
        cnt = tmpCnt;
        memset(visited, false, sizeof(visited));
        memcpy(changed, map, sizeof(map));

        tmpCnt -= meltByBfs();

        memcpy(map, changed, sizeof(changed));
    }
}

void output(){
    cout << hour << '\n' << cnt << '\n';
}

void solution(){
    input();
    solve();
    output();
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    solution();

    return 0;
}