#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef pair<pii, int> ppiii;
int M, S;
int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int sx[4] = {-1, 0, 1, 0};
int sy[4] = {0, -1, 0, 1};
vector<int> board[4][4];
int smell[4][4], visited[4][4];
pii shark;

void input(){
    cin >> M >> S;

    int fx, fy, d;
    for (int i = 0; i < M; i++){
        cin >> fx >> fy >> d;
        board[fx - 1][fy - 1].push_back(d - 1);
    }

    cin >> fx >> fy;
    shark = {fx - 1, fy - 1};
}

queue<ppiii> copyFish(){
    queue<ppiii> fishs;

    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            for (int k = 0; k < board[i][j].size(); k++){
                fishs.push({{i, j}, board[i][j][k]});
            }
        }
    }

    return fishs;
}

void moveFish(){
    vector<int> tmp[4][4];

    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            for (int k = 0; k < board[i][j].size(); k++){
                bool flag = false;
                for (int d = 0; d < 8; d++){
                    int dir = (board[i][j][k] + 8 - d) % 8;
                    int nx = i + dx[dir], ny = j + dy[dir];

                    if (nx < 0 || ny < 0 || nx > 3 || ny > 3) continue;
                    if (nx == shark.first && ny == shark.second) continue;
                    if (smell[nx][ny] > 0) continue;

                    tmp[nx][ny].push_back(dir);
                    flag = true;
                    break;
                }
                if(!flag) tmp[i][j].push_back(board[i][j][k]);
            }
        }
    }

    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            board[i][j] = tmp[i][j];
        }
    }
}

void sharkBacktrack(int n, int x, int y, int kill, int order, priority_queue<pii>& routes){
    if(n == 3) {
        routes.push({kill, -order});
        return;
    }

    int tmp = kill;

    for (int i = 0; i < 4; i++){
        int nx = x + sx[i], ny = y + sy[i];

        if (nx < 0 || ny < 0 || nx > 3 || ny > 3) continue;
        bool tmp2 = visited[nx][ny];
        if (!visited[nx][ny]) kill += board[nx][ny].size();
        visited[nx][ny] = true;
        sharkBacktrack(n + 1, nx, ny, kill, order * 10 + i, routes);
        visited[nx][ny] = tmp2;
        kill = tmp;
    }
}

void moveShark(){
    priority_queue<pii> routes;
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            visited[i][j] = false;
        }
    }

    int x = shark.first, y = shark.second;

    sharkBacktrack(0, x, y, 0, 0, routes);

    int kill, way, radix = 100;
    tie(kill, way) = routes.top();
    M -= kill;
    way *= -1;

    vector<pii> moves;

    for (int i = 0; i < 3; i++){
        int dir = way % 10;
        way /= 10;
        moves.push_back({sx[dir], sy[dir]});
    }

    reverse(moves.begin(), moves.end());

    for (int i = 0; i < 3; i++){
        x += moves[i].first, y += moves[i].second;
        if(board[x][y].size()) {
            smell[x][y] = 3;
            board[x][y].clear();
        }
        radix /= 10;
    }

    shark = {x, y};
}

void decreaseSmell(){
    for (int i = 0; i < 4; i++){
        for (int j = 0; j < 4; j++){
            smell[i][j]--;
        }
    }
}

void pasteFish(queue<ppiii>& copyQueue){
    while (!copyQueue.empty()){
        int x, y, dir = copyQueue.front().second;
        tie(x, y) = copyQueue.front().first;
        copyQueue.pop();

        board[x][y].push_back(dir);
        M++;
    }
}

void simulate(){
    while (S--){
        queue<ppiii> tmp = copyFish();
        moveFish();
        moveShark();
        decreaseSmell();
        pasteFish(tmp);
    }
}

void solution(){
    input();
    simulate();
    cout << M;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    solution();
}