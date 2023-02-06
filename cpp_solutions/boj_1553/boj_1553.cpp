#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
int board[8][7];
bool visited[8][7];
int dx[2] = {0, 1};
int dy[2] = {1, 0};
int domino[7][7];

void input(){
    string tmp;
    for (int i = 0; i < 8; i++){
        cin >> tmp;
        for (int j = 0; j < 7; j++){
            board[i][j] = tmp[j] - '0';
        }
    }
}

int solve(int x, int y, int cnt){
    if (x == 8 && cnt == 28) return 1;
    if (y == 7) return solve(x + 1, 0, cnt);
    if (visited[x][y]) return solve(x, y + 1, cnt);

    int ret = 0;

    for (int i = 0; i < 2; i++){
        int nx = x + dx[i], ny = y + dy[i];
        int small = min(board[x][y], board[nx][ny]);
        int big = max(board[x][y], board[nx][ny]);

        if (nx > 7 || ny > 6 || visited[x][y] || visited[nx][ny] || domino[small][big]) continue;

        visited[x][y] = visited[nx][ny] = domino[small][big] = true;
        ret += solve(x, y + 1, cnt + 1);
        visited[x][y] = visited[nx][ny] = domino[small][big] = false;
    }

    return ret;
}

void solution(){
    input();
    cout << solve(0, 0, 0);
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    solution();
}