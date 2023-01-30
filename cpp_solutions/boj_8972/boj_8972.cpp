#include <iostream>
#include <queue>
#include <string>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;
int R, C;
char board[100][100];
pii cur;
queue<pii> robots;
string order;
int nextState[100][100];

int dx[9] = {1, 1, 1, 0, 0, 0, -1, -1, -1};
int dy[9] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};

void input(){
    cin >> R >> C;

    for (int i = 0; i < R; i++){
        string tmp;
        cin >> tmp;
        for (int j = 0; j < C; j++){
            board[i][j] = tmp[j];
            if (tmp[j] == 'I') cur = {i, j};
            else if (tmp[j] == 'R') robots.push({i, j});
        }
    }

    cin >> order;
}

bool moveJongsu(int idx){
    int nx = cur.first + dx[order[idx] - '1'];
    int ny = cur.second + dy[order[idx] - '1'];

    if (board[nx][ny] == 'R') return false;

    cur = {nx, ny};
    return true;
}

pii getCloseDirToCur(pii robot){
    int nx = 0, ny = 0;

    if (cur.first < robot.first) nx = -1;
    else if (cur.first > robot.first) nx = 1;

    if (cur.second < robot.second) ny = -1;
    else if (cur.second > robot.second) ny = 1;

    return {nx, ny};
}

bool moveRobots(){

    while (!robots.empty()){
        pii robot = robots.front();
        robots.pop();
        board[robot.first][robot.second] = '.';
        pii dxdy = getCloseDirToCur(robot);
        int nx = robot.first + dxdy.first;
        int ny = robot.second + dxdy.second;

        if (nx == cur.first && ny == cur.second) return false;

        nextState[nx][ny]++;
    }

    return true;
}

void explodeRobots(){
    for (int i = 0; i < R; i++){
        for (int j = 0; j < C; j++){
            int &next = nextState[i][j];
            if (next > 1) next = 0;
            else if (next == 1) {
                next = 0;
                robots.push({i, j});
                board[i][j] = 'R';
            }
        }
    }
}

void printBoard(){
    char output[100][100];

    fill(&output[0][0], &output[R - 1][C], '.');

    output[cur.first][cur.second] = 'I';

    while (!robots.empty()){
        pii robot = robots.front();
        robots.pop();
        output[robot.first][robot.second] = 'R';
    }

    for (int i = 0; i < R; i++){
        for (int j = 0; j < C; j++){
            cout << output[i][j];
        }
        cout << '\n';
    }
}

void solve(){
    int idx = 0;

    while (idx < order.length()){
        if (!moveJongsu(idx++) || !moveRobots()) {
            cout << "kraj " << idx;
            return;
        }

        explodeRobots();
    }

    printBoard();
}

void solution(){
    input();
    solve();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    solution();
}