#include <algorithm>
#include <queue>
#include <iostream>

using namespace std;
typedef tuple<int, int, bool> elem;
int W, H;
char graph[1000][1000];
int visited[1000][1000];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

bool isBorder(int x, int y){
    return (x == 0 || y == 0 || x == H - 1 || y == W - 1);
}

int bfs() {

    queue<elem> order;

    bool flag = false;

    for (int i = 0; i < H; i++){
        for (int j = 0; j < W; j++){
            if (graph[i][j] == '*') {
                order.push({i, j, true});
                visited[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < H; i++){
        if(flag) break;
        for (int j = 0; j < W; j++){
            if (graph[i][j] == '@') {
                if (isBorder(i, j)) return 1;

                order.push({i, j, false});
                visited[i][j] = 1;
                flag = true;
                break;
            }
        }
    }

    while(!order.empty()){
        int x, y, isFire;
        tie(x, y, isFire) = order.front();
        order.pop();

        for (int i = 0; i < 4; i++){
            int nx = x + dx[i], ny = y + dy[i];

            if (nx < 0 || nx >= H || ny < 0 || ny >= W || graph[nx][ny] == '#' || visited[nx][ny] != -1) continue;

            visited[nx][ny] = visited[x][y] + 1;

            if (!isFire && isBorder(nx, ny)) return visited[nx][ny];
            
            order.push({nx, ny, isFire});
        }
    }

    return -1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T;
    cin >> T;

    while(T--) {
        fill(&visited[0][0], &visited[999][1000], -1);

        cin >> W >> H;
        for (int i = 0; i < H; i++){
            for (int j = 0; j < W; j++){
                cin >> graph[i][j];
            }
        }

        int answer = bfs();
        if (answer == -1) cout << "IMPOSSIBLE\n";
        else cout << answer << '\n';
    }
}