#include <bits/stdc++.h>

using namespace std;
int N, M;
int grid[50][50];
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

bool check_around(int x, int y) {
    for (int i = 0; i < 4; i++) {
        if (grid[x + dx[i]][y + dy[i]] == 0)
            return true;
    }

    return false;
}

int simulate(int r, int c, int dir){
    int cnt = 0;

    while (true) {
        if (grid[r][c] == 0) {
            grid[r][c] = 2;
            cnt++;
        }

        if (check_around(r, c)) {
            dir = (dir + 3) % 4;
            int nx = r + dx[dir], ny = c + dy[dir];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M || grid[nx][ny] == 1) continue;

            if (grid[nx][ny] != 0) continue;

            r = nx;
            c = ny;
        } else {
            int back = (dir + 2) % 4;
            int nx = r + dx[back], ny = c + dy[back];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M || grid[nx][ny] == 1) return cnt;

            r = nx;
            c = ny;
        }
    }

    return cnt;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    int r, c, d;

    cin >> N >> M >> r >> c >> d;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++){
            cin >> grid[i][j];
        }
    }

    cout << simulate(r, c, d);
}