#include <bits/stdc++.h>

using namespace std;
typedef tuple<int, int, int> tiii;
int N, M, K;
string graph[1000];
int visited[1000][1000][11];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

void input(){
    cin >> N >> M >> K;

    for (int i = 0; i < N; i++){
        cin >> graph[i];
    }
}

int BFS(){
    queue<tiii> order;
    visited[0][0][0] = 1;
    order.push({0, 0, 0});

    while (!order.empty()){
        tiii cur = order.front();
        int curx = get<0>(cur), cury = get<1>(cur), count = get<2>(cur);
        order.pop();

        if (curx == N - 1 && cury == M - 1) return  visited[curx][cury][count];

        for (int i = 0; i < 4; i++){
            int nx = curx + dx[i], ny = cury + dy[i];
            if (nx < 0 || nx >= N) continue;
            if (ny < 0 || ny >= M) continue;
            if (visited[nx][ny][count]) continue;

            if (graph[nx][ny] == '0'){
                order.push({nx, ny, count});
                visited[nx][ny][count] = visited[curx][cury][count] + 1;
            }

            if (!visited[nx][ny][count + 1] && graph[nx][ny] == '1' && count < K){
                order.push({nx, ny, count + 1});
                visited[nx][ny][count + 1] = visited[curx][cury][count] + 1;
            }
        }
    }

    return -1;
}

void solution(){
    input();
    cout << BFS();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    solution();
}