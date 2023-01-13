#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
int N;
int graph[100][100];
int visited[100][100];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void init(){
    fill(&visited[0][0], &visited[99][100], -1);
}

void input(){
    cin >> N;
    string tmp;
    for (int i = 0; i < N; i++){
        cin >> tmp;
        for (int j = 0; j < N; j++){
            graph[i][j] = tmp[j] - '0';
        }
    }
}

int bfs(){
    queue<pii> order;
    order.push({0, 0});
    visited[0][0] = 0;

    while (!order.empty()){
        int x = order.front().first, y = order.front().second;
        order.pop();

        for (int i = 0; i < 4; i++){
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
            if (visited[nx][ny] != -1 && visited[nx][ny] <= visited[x][y] + graph[nx][ny])
                continue;

            order.push({nx, ny});
            visited[nx][ny] = visited[x][y] + graph[nx][ny];
        }
    }

    return visited[N - 1][N - 1];
}

void solution(){
    int C;
    cin >> C;
    for (int i = 1; i <= C; i++){
        init();
        input();
        cout << '#' << i << ' ' << bfs() << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    solution();
}