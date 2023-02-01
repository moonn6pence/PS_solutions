#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
typedef pair<int, int> pii;
const int INF = 1e9;
int N, M;
int graph[50][50];
vector<pii> virus;
int visited[10][50][50];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

void input() {
    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> graph[i][j];
            if (graph[i][j] == 2) virus.push_back({i, j});
        }
    }
}

void BFS(int src){
    queue<pii> order;
    order.push(virus[src]);
    visited[src][virus[src].first][virus[src].second] = 0;

    while (!order.empty()){
        int x = order.front().first, y = order.front().second;
        order.pop();

        for (int i = 0; i < 4; i++){
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if (visited[src][nx][ny] != -1 || graph[nx][ny] == 1) continue;

            order.push({nx, ny});
            visited[src][nx][ny] = visited[src][x][y] + 1;
        }
    }
}

void unionTime(vector<vector<int>>& time, int cur){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if (time[i][j] > visited[cur][i][j] && visited[cur][i][j] != -1){
                time[i][j] = visited[cur][i][j];
            }
        }
    }
}


int overlapBFS(int state){
    vector<vector<int>> time(50, vector<int>(50, INF));
    int ret = 0;

    for (int i = 0; i < virus.size(); i++){
        if (state & (1 << i)){
            unionTime(time, i);
        }
    }

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){

            if (graph[i][j] == 0 && time[i][j] == INF){
                return INF;
            }

            if (graph[i][j] == 0) {
                ret = max(ret, time[i][j]);
            }
        }
    }

    return ret;
}

int solve(int state, int firstFree, int cnt) {

    if (cnt == M) {
        return overlapBFS(state);
    }

    int ret = INF;

    for (int i = firstFree; i < virus.size(); i++){
        if ((state & (1 << i))) continue;

        ret = min(ret, solve(state | (1 << i), i + 1, cnt + 1));
    }

    return ret;
}

void solution() {
    input();
    fill(&visited[0][0][0], &visited[virus.size() - 1][N - 1][N], -1);
    for (int i = 0; i < virus.size(); i++) BFS(i);
    int answer = solve(0, 0, 0);
    answer = (answer < INF) ? answer : -1;
    cout << answer;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    solution();
}