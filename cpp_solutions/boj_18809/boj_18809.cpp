#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
int N, M, G, R;
int graph[50][50];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
vector<pii> cand, green, red;

void input(){
    cin >> N >> M >> G >> R;

    int x, y;

    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cin >> graph[i][j];
            if (graph[i][j] == 2) cand.push_back({i, j});
        }
    }
    green.assign(G, pii());
    red.assign(R, pii());
}

int simulate(){
    int ret = 0;
    queue<pii> order;
    int visited[50][50];
    int color[50][50]; // 1 : green, 2 : red, 3 : flower
    fill(&visited[0][0], &visited[49][50], 0);
    fill(&color[0][0], &color[49][50], 0);

    for(pii p : green){
        visited[p.first][p.second] = 1;
        color[p.first][p.second] = 1;
        order.push({p.first, p.second});
    }

    for(pii p : red){
        visited[p.first][p.second] = 1;
        color[p.first][p.second] = 2;
        order.push({p.first, p.second});
    }

    while (!order.empty()){
        int x, y;
        tie(x, y) = order.front();
        order.pop();
        if (color[x][y] == 3) continue;

        for (int i = 0; i < 4; i++){
            int nx = x + dx[i], ny = y + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (!graph[nx][ny] || color[nx][ny] == 3 || color[nx][ny] == color[x][y]) continue;
            
            if (!visited[nx][ny]){
                color[nx][ny] = color[x][y];
                visited[nx][ny] = visited[x][y] + 1;
                order.push({nx, ny});
            } else {
                if (visited[nx][ny] == visited[x][y] + 1){
                    color[nx][ny] = 3;
                    ret++;
                }
            }
        }
    }

    return ret;
}

int solve(int state, int gbegin, int rbegin ,int cnt){
    if (cnt == G + R) return simulate();

    int ret = -1;

    if (cnt < G){
        for (int i = gbegin; i < cand.size(); i++){
            if (state & (1 << i)) continue;

            green[cnt] = cand[i];
            ret = max(ret, solve(state | (1 << i), i + 1, 0, cnt + 1));
        }
    } else {
        for (int i = rbegin; i < cand.size(); i++){
            if (state & (1 << i)) continue;

            red[cnt - G] = cand[i];
            ret = max(ret, solve(state | (1 << i), cand.size(), i + 1, cnt + 1));
        }
    }

    return ret;
}

void solution(){
    input();
    cout << solve(0, 0, 0, 0);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    solution();
}