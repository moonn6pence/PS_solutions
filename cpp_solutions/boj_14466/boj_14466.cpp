#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
int N, K, R;
bool isCow[101][101];
vector<pii> cows;
map<pii, map<pii, bool>> cost;
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
        cows.push_back({a, b});
    }
}

int bfs(pii src){
    int cnt = K - 1;
    bool visited[101][101];
    fill(&visited[0][0], &visited[100][101], false);

    queue<pii> order;
    order.push(src);
    visited[src.first][src.second] = true;

    while (!order.empty()){
        int x = order.front().first, y = order.front().second;
        order.pop();

        for (int i = 0; i < 4; i++){
            int nx = x + dx[i], ny = y + dy[i];

            if (nx < 1 || ny < 1 || nx > N || ny > N) continue;
            if (visited[nx][ny] || cost[{x,y}][{nx,ny}]) continue;

            order.push({nx, ny});
            visited[nx][ny] = true;
            if (isCow[nx][ny]) cnt--;
        }
    }

    return cnt;
}

void solve(){
    int ret = 0;

    for (auto& cow : cows){
        ret += bfs(cow);
    }

    cout << ret / 2;
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