#include <iostream>
#include <queue>

using namespace std;
typedef pair<int, int> pii;

int N, M, T , ans = 0;
int pixel[1000][1000];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
bool visited[1000][1000] = {false,};

void input(){
    cin >> N >> M;
    int r, g, b;

    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cin >> r >> g >> b;
            pixel[i][j] = r + g + b;
        }
    }

    cin >> T;
}

void init(){
    T *= 3;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            pixel[i][j] = (pixel[i][j] < T) ? 0 : 255;
        }
    }
}

void bfs(int x, int y){
    queue<pii> order;
    order.push({x, y});
    visited[x][y] = true;

    while(!order.empty()){
        int curx = order.front().first, cury = order.front().second;
        order.pop();
        for (int i = 0; i < 4; i++){
            int nx = curx + dx[i], ny = cury + dy[i];
            if (nx < 0 || nx >= N) continue;
            if (ny < 0 || ny >= M) continue;
            if (visited[nx][ny] || pixel[nx][ny] == 0) continue;

            visited[nx][ny] = true;
            order.push({nx, ny});
        }
    }
}

void solve(){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            if(pixel[i][j] && !visited[i][j]){
                bfs(i, j);
                ans++;
            }
        }
    }
}

void solution(){
    input();
    init();
    solve();
    cout << ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    solution();

    return 0;
}