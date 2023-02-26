#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
int R, C, T;
int dust[50][50];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
vector<pii> cleaner;

void input(){
    cin >> R >> C >> T;

    for (int i = 0; i < R; i++){
        for (int j = 0; j < C; j++){
            cin >> dust[i][j];
            if(dust[i][j] == -1) cleaner.push_back({i, j});
        }
    }
}

void spread_air(){
    int tmp[50][50];
    fill(&tmp[0][0], &tmp[49][50], 0);

    for (int i = 0; i < R; i++){
        for (int j = 0; j < C; j++){
            if(dust[i][j] < 0) {
                tmp[i][j] = -1;
                continue;
            }
            int diffusion = dust[i][j] / 5;
            tmp[i][j] += dust[i][j];
            if (diffusion < 1) continue;

            for (int k = 0; k < 4; k++){
                int nx = i + dx[k], ny = j + dy[k];

                if (nx < 0 || ny < 0 || nx >= R || ny >= C || dust[nx][ny] < 0) continue;

                tmp[i][j] -= diffusion;
                tmp[nx][ny] += diffusion;
            }
        }
    }

    for (int i = 0; i < R; i++){
        for (int j = 0; j < C; j++){
            dust[i][j] = tmp[i][j];
        }
    }
}

void down_cycle(int x, int y, int dir, int air){
    if (dust[x][y] == -1) return;

    int tmp = dust[x][y];
    dust[x][y] = air;

    int nx = x + dx[dir], ny = y + dy[dir];

    if (nx < 0 || ny < 0 || nx >= R || ny >= C) dir = (dir + 1) % 4;

    nx = x + dx[dir]; ny = y + dy[dir];

    down_cycle(nx, ny, dir, tmp);
}

void up_cycle(int x, int y, int dir, int air){
    if (dust[x][y] == -1) return;

    int tmp = dust[x][y];
    dust[x][y] = air;

    int nx = x + dx[dir], ny = y + dy[dir];

    if (nx < 0 || ny < 0 || nx >= R || ny >= C) dir = (dir + 3) % 4;

    nx = x + dx[dir]; ny = y + dy[dir];

    up_cycle(nx, ny, dir, tmp);
}

void refresh_air(){
    pii AC1 = cleaner[0], AC2 = cleaner[1];

    up_cycle(AC1.first, AC1.second + 1, 0, 0);
    down_cycle(AC2.first, AC2.second + 1, 0, 0);
}

int simulate(){
    while (T--){
        spread_air();
        refresh_air();
    }

    int ret = 2;
    for (int i = 0; i < R; i++){
        for (int j = 0; j < C; j++){
            ret += dust[i][j];
        }
    }

    return ret;
}

void solution(){
    input();
    cout << simulate();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    solution();
}