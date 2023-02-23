#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
int N, K, R;
bool isCow[101][101];
vector<int> cows;
map<pii, map<pii, bool>> cost;
bool visited[101][101];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

void input(){
    cin >> N >> K >> R;
    int a, b, c, d;

    for (int i = 0; i < R; i++){
        cin >> a >> b >> c >> d;
        cost[{a, b}][{c, d}] = true;
        cost[{c, d}][{a, b}] = true;
    }

    for (int i = 0; i < K; i++){
        cin >> a >> b;
        isCow[a][b] = true;
    }
}

void bfs(int srcX, int srcY){
    int cnt = 1;

    queue<pii> order;
    order.push({srcX, srcY});
    visited[srcX][srcY] = true;

    while (!order.empty()){
        int x = order.front().first, y = order.front().second;
        order.pop();

        for (int i = 0; i < 4; i++){
            int nx = x + dx[i], ny = y + dy[i];

            if (nx < 1 || ny < 1 || nx > N || ny > N) continue;
            if (visited[nx][ny] || cost[{x,y}][{nx,ny}]) continue;

            order.push({nx, ny});
            visited[nx][ny] = true;
            if (isCow[nx][ny]) cnt++;
        }
    }

    cows.push_back(cnt);
}

int solve(){
    int ret = 0;
    fill(&visited[0][0], &visited[100][101], false);

    for (int i = 1; i <= N; i++){
        for (int j = 1; j <= N; j++){
            if (!visited[i][j] && isCow[i][j]) bfs(i, j);
        }
    }

    for (int i = 0; i < cows.size(); i++){
        ret += cows[i] * (K - cows[i]);
    }

    return ret / 2;
}

void solution(){
    input();
    cout << solve();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    solution();
}