#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;
int N, M, power[2];
char ground[100][100];
bool visited[100][100];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

int bfs(int sx, int sy, char color){
    int tmp = 1;
    queue<pii> order;
    order.push({sx, sy});
    visited[sx][sy] = 1;

    while(!order.empty()) {
        int x, y;
        tie(x, y) = order.front();
        order.pop();

        for (int i = 0; i < 4; i++){
            int nx = x + dx[i], ny = y + dy[i];

            if (nx < 0 || nx >= M || ny < 0 || ny >= N || ground[nx][ny] != color || visited[nx][ny]) continue;

            visited[nx][ny] = true;
            order.push({nx, ny});
            tmp++;
        }
    }

    return tmp * tmp;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    cin >> N >> M;

    for (int i = 0; i < M; i++){
        for (int j = 0; j < N; j++){
            cin >> ground[i][j];
        }
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (visited[i][j]) continue;
            if (ground[i][j] == 'W') power[0] += bfs(i,j,'W');
            else power[1] += bfs(i,j,'B');
        }
    }

    cout << power[0] << ' ' << power[1];
}