#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef queue<pii> qpii;
typedef vector<pii> vpii;
typedef vector<vpii> vvpii;
int R, C, N;
bool mineral[100][100];
int stick[100];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
bool visited[100][100];

void input(){
    cin >> R >> C;

    string s;

    for (int i = 0; i < R; i++){
        cin >> s;
        for (int j = 0; j < C; j++){
            mineral[i][j] = s[j] == 'x';
        }
    }

    cin >> N;

    for (int i = 0; i < N; i++){
        int row;
        cin >> row;
        stick[i] = R - row;
    }
}

bool crush(int row, int dir){
    int col = dir ? C - 1 : 0;
    int d = dir ? -1 : 1;

    while (0 <= col && col < C){
        if (mineral[row][col]) {
            mineral[row][col] = false;
            return true;
        }
        col += d;
    }

    return false;
}

int fall(int num, int tmp[][100], qpii &q){
    int ret = 0;

    while (!q.empty()){
        int len = q.size();

        while (len--){
            int x, y;
            tie(x, y) = q.front();
            q.pop();

            if (x == R - 1) return ret;
            else if (x + 1 < R && mineral[x + 1][y] && tmp[x + 1][y] != num) return ret;

            if (x + 1 < R && tmp[x + 1][y] != num) q.push({x+1,y});

            // if (x + 1 >= R) continue;
            // if (tmp[x + 1][y] != num) {
            //     if (mineral[x + 1][y]) return ret;
            //     q.push({x + 1, y});
            // }
        }
        ret++;
    }

    return ret;
}

void group(int x, int y, int num, int tmp[][100], vpii &v){
    visited[x][y] = true;
    tmp[x][y] = num;
    v.push_back({x, y});

    for (int i = 0; i < 4; i++){
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx >= R || ny >= C || !mineral[nx][ny] || visited[nx][ny]) continue;

        group(nx, ny, num, tmp, v);
    }
}

void change(){
    int num = 1, tmp[100][100];
    vvpii clusters;
    memset(tmp, 0, sizeof(tmp));
    memset(visited, false, sizeof(visited));

    for (int i = 0; i < R; i++){
        for (int j = 0; j < C; j++){
            if (mineral[i][j] && !visited[i][j]){
                vpii cluster;
                group(i, j, num++, tmp, cluster);
                clusters.push_back(cluster);
            }
        }
    }

    num = 1;
    for(vpii cluster : clusters){
        qpii points;
        for (pii point : cluster) points.push(point);

        int height = fall(num++, tmp, points);
        if (!height) continue;

        bool after[100][100];

        for(pii xy : cluster){
            after[xy.first + height][xy.second] = mineral[xy.first][xy.second];
            mineral[xy.first][xy.second] = false;
        }

        for(pii xy : cluster) mineral[xy.first + height][xy.second] = after[xy.first + height][xy.second];
        break;
    }
}

void output(){
    for (int i = 0; i < R; i++){
        for (int j = 0; j < C; j++){
            cout << (mineral[i][j] ? 'x' : '.');
        }
        cout << '\n';
    }
    cout << '\n';
}

void simulate(){
    int dir = 1;

    for (int i = 0; i < N;i++) {
        if(crush(stick[i], dir ^= 1)) change();
        output();
    }
}

void solution(){
    input();
    simulate();
    // output();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    solution();
}