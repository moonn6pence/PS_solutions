#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
int R, C, N;
bool mineral[101][100];
int height[100];
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, -1, 1, 0};
bool visited[101][101];
int clusterFloor[100];

void input()
{
    cin >> R >> C;

    string s;

    for (int i = R; i > 0; i--){
        cin >> s;
        for (int j = 0; j < C; j++){
            mineral[i][j] = (s[j] == 'x');
        }
    }

    cin >> N;

    for (int i = 0; i < N; i++){
        cin >> height[i];
    }
}

pii breakMineral(int h, bool dir){

    if (dir){
        for (int i = 0; i < C; i++){
            if(mineral[h][i]) {
                mineral[h][i] = false;
                return {h, i};
            }
        }
    }

    for (int i = C - 1; i >= 0; i--){
        if(mineral[h][i]) {
            mineral[h][i] = false;
            return {h, i};
        }
    }

    return {0, 0};
}

bool BFS(int x, int y){
    queue<pii> order;
    order.push({x, y});
    visited[x][y] = true;

    while (!order.empty()){
        int curx = order.front().first, cury = order.front().second;
        order.pop();
        clusterFloor[cury] = min(clusterFloor[cury], curx);

        for (int i = 0; i < 4; i++){
            int nx = curx + dx[i], ny = cury + dy[i];
            if (nx < 1 || ny < 0 || nx > R || ny >= C) continue;
            if (!mineral[nx][ny] || visited[nx][ny]) continue;

            if (nx == 1) return false;
            visited[nx][ny] = true;
            order.push({nx, ny});
        }
    }

    return true;
}

void classifyCluster(pii broken){

    for (int i = 0; i < 4; i++){
        int nx = broken.first + dx[i], ny = broken.second + dy[i];
        if (nx < 1 || ny < 0 || nx > R || ny >= C) continue;

        fill(&visited[0][0], &visited[100][101], false);
        fill(clusterFloor, clusterFloor + C, R + 1);
        if (mineral[nx][ny]){
            if (!BFS(nx, ny)){
                continue;
            }

            return;
        }
    }
}

int getDropHeight(){
    int ret = R;
    for (int i = 0; i < C; i++){
        if (clusterFloor[i] == R + 1){
            continue;
        }

        int low = 0;

        for (int j = 1; j <= R; j++){
            if (visited[j][i]) break;
            if (mineral[j][i] && !visited[j][i]){
                low = j;
            }
        }

        ret = min(ret, clusterFloor[i] - low);
    }

    return ret - 1;
}

void dropCluster(int dropHeight){
    if (!dropHeight) return;

    for (int i = 1; i <= R; i++){
        for (int j = 0; j < C; j++){
            if(visited[i][j]){
                mineral[i][j] = false;
                mineral[i - dropHeight][j] = true;
            }
        }
    }
}

void output(){
    for (int i = R; i > 0; i--){
        for (int j = 0; j < C; j++){
            if(mineral[i][j]) cout << 'x';
            else cout << '.';
        }
        cout << '\n';
    }
}


void simulate(){
    for (int i = 0; i < N; i++){
        pii broken = breakMineral(height[i], i % 2 == 0);
        classifyCluster(broken);
        int h = getDropHeight();
        dropCluster(h);
    }
}

void solution(){
    input();
    simulate();
    output();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    solution();
}