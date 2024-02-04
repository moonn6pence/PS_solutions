#include <bits/stdc++.h>

using namespace std;

struct info
{
    int x;
    int y;
    int dir;
};

info src, dest;
int graph[100][100], visited[100][100][4];
int M, N;
int dx[4] = {0, 0, 1, -1}; // 3,0,2,1
int dy[4] = {1, -1, 0, 0};
int turn_dir[2][4] = {{3, 2, 0, 1}, {2, 3, 1, 0}};

void normalize_info(info &point) {
    point.x--;
    point.y--;
    point.dir--;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    fill(&visited[0][0][0], &visited[99][99][4], -1);

    cin >> M >> N;

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> graph[i][j];
        }
    }

    cin >> src.x >> src.y >> src.dir;
    cin >> dest.x >> dest.y >> dest.dir;

    normalize_info(src);
    normalize_info(dest);

    visited[src.x][src.y][src.dir] = 0;
    queue<info> order;
    order.push(src);

    while(!order.empty()) {
        info cur = order.front();
        int &cur_cost = visited[cur.x][cur.y][cur.dir];
        order.pop();

        if (cur.x == dest.x && cur.y == dest.y && cur.dir == dest.dir) break;

        int nx = cur.x, ny = cur.y;

        // Go k
        for (int k = 1; k < 4; k++) {
            nx += dx[cur.dir];
            ny += dy[cur.dir];

            if (nx < 0 || nx >= M || ny < 0 || ny >= N || graph[nx][ny] == 1) break;
            if (visited[nx][ny][cur.dir] != -1) continue;

            order.push({nx, ny, cur.dir});
            visited[nx][ny][cur.dir] = cur_cost + 1;
        }

        // Turn dir
        for (int k = 0; k < 2; k++) {
            int ndir = turn_dir[k][cur.dir];

            if (visited[cur.x][cur.y][ndir] != -1) continue;

            order.push({cur.x, cur.y, ndir});
            visited[cur.x][cur.y][ndir] = cur_cost + 1;
        }
    }

    cout << visited[dest.x][dest.y][dest.dir];
}