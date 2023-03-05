#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, int> piii;
int R, C, K, W;
int room[21][21];
int dx[5] = {-1, 0, 1, 0};
int dy[5] = {0, 1, 0, -1};
vector<piii> heaters;
vector<pii> targets;
map<piii, int> wall;

void input(){
    cin >> R >> C >> K;
    int info;

    for (int i = 1; i <= R; i++){
        for (int j = 1; j <= C; j++){
            cin >> info;

            if (info == 5) targets.push_back({i, j});
            else if(info > 0) heaters.push_back({{i, j}, (info + (info >> 1)) & 3});
        }
    }

    cin >> W;
    int x, y, t;

    for (int i = 0; i < W; i++){
        cin >> x >> y >> t;
        wall[{{x, y}, t}] = true;
        wall[{{x + dx[t], y + dy[t]}, t + 2}] = true;
    }
}

void heatUp(int x, int y, int dir, int temp, bool visited[][21]){
    if (temp == 0 || x < 1 || y < 1 || x > R || y > C || visited[x][y]) return;
    if (wall[{{x, y}, (dir + 2) % 4}]) return;
    int nx, ny;

    room[x][y] += temp;
    visited[x][y] = true;

    nx = x + dx[(dir + 3) % 4];
    ny = y + dy[(dir + 3) % 4];
    if (0 < nx && 0 < ny && nx <= R && ny <= C && !wall[{{nx, ny}, (dir + 1) % 4}]){
        nx += dx[dir];
        ny += dy[dir];
        heatUp(nx, ny, dir, temp - 1, visited); // 대각선 윗 칸
    }

    nx = x + dx[dir];
    ny = y + dy[dir];
    heatUp(nx, ny, dir, temp - 1, visited); // 옆 칸

    nx = x + dx[(dir + 1) % 4];
    ny = y + dy[(dir + 1) % 4];
    if (0 < nx && 0 < ny && nx <= R && ny <= C && !wall[{{nx, ny}, (dir + 3) % 4}]){
        nx += dx[dir];
        ny += dy[dir];
        heatUp(nx, ny, dir, temp - 1, visited); // 대각선 아랫 칸
    }
}

void normalize(int result[][21]){
    for (int i = 1; i <= R; i++){
        for (int j = 1; j <= C; j++){
            for (int d = 1; d < 3; d++){
                int nx = i + dx[d], ny = j + dy[d];

                if (nx > R || ny > C || wall[{{i, j}, d}]) continue;

                int diff = (room[i][j] - room[nx][ny]) / 4;
                result[i][j] -= diff;
                result[nx][ny] += diff;
            }
        }
    }

    for (int i = 1; i <= R; i++){
        for (int j = 1; j <= C; j++){
            room[i][j] += result[i][j];
        }
    }
}

void decreaseSides(){
    for (int y = 1; y < C; y++) if (room[1][y]) room[1][y]--;
    for (int x = 1; x < R; x++) if (room[x][C]) room[x][C]--;
    for (int y = C; y > 1; y--) if (room[R][y]) room[R][y]--;
    for (int x = R; x > 1; x--) if (room[x][1]) room[x][1]--;
}

void simulate(){
    int after[21][21] = {0};
    bool visited[21][21];

    for (piii heater : heaters){
        fill(&visited[0][0], &visited[20][21], false);
        int x, y, dir;
        tie(x, y) = heater.first;
        dir = heater.second;
        x += dx[dir]; y += dy[dir];

        heatUp(x, y, dir, 5, visited);
    }

    normalize(after);
    decreaseSides();
}

bool research(){

    for(pii xy : targets){
        if (room[xy.first][xy.second] < K) return false;
    }

    return true;
}

void solution(){
    input();

    int t = 0;
    while (t++ < 100){
        simulate();
        if (research()) break;
    }

    cout << t;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    solution();
}