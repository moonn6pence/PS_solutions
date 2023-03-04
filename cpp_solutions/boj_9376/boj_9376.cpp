#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
const int INF = 2e9;
int T, H, W;
char prison[102][102];
int visited[3][102][102];
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};
vector<pii> prisoner;

void input(){
    cin >> H >> W;

    fill(&prison[0][0], &prison[101][102], '.');

    string s;
    for (int i = 1; i <= H; i++) {
        cin >> s;
        for (int j = 1; j <= W; j++){
            prison[i][j] = s[j - 1];
        }
    }
}

void init(){
    memset(visited, -1, sizeof(visited));
    prisoner.clear();

    prisoner.push_back({0, 0});

    for (int i = 1; i < H + 1; i++){
        for (int j = 1; j < W + 1; j++){
            if (prison[i][j] == '$') prisoner.push_back({i, j});
            if (prisoner.size() == 3) return;
        }
    }
}

void bfs(int num, pii src){
    queue<pii> order;
    order.push(src);
    visited[num][src.first][src.second] = 0;

    while (!order.empty()){
        int x, y;
        tie(x, y) = order.front();
        order.pop();

        for (int i = 0; i < 4; i++){
            int nx = x + dx[i], ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx > H + 1 || ny > W + 1 || prison[nx][ny] == '*') continue;

            int nextCost = visited[num][x][y] + (prison[nx][ny] == '#');
            int& nextDist = visited[num][nx][ny];

            if (nextDist == -1 || nextCost < nextDist){
                nextDist = nextCost;
                order.push({nx, ny});
            }
        }
    }
}

int solve(){
    int ret = 2e9;

    for (int i = 0; i < 3; i++) bfs(i, prisoner[i]);

    for (int i = 1; i < H + 1; i++){
        for (int j = 1; j < W + 1; j++){
            if (prison[i][j] == '*' || visited[0][i][j] == -1) continue;
            int sum = (prison[i][j] == '#' ? -2 : 0);

            for (int k = 0; k < 3; k++){
                sum += visited[k][i][j];
            }

            ret = min(ret, sum);
        }
    }

    return ret;
}

void solution(){
    cin >> T;

    while (T--){
        input();
        init();
        cout << solve() << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);
    solution();
}