#include <bits/stdc++.h>

using namespace std;
const int INF = 2e9;
typedef pair<int, int> pii;
int W, H;
string graph[20];
map<pii, int[20][20]> dist;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
pii robot;
vector<pii> dusts;
int robotIdx;
map<pii, int> cache[1 << 11];

bool input(){
    cin >> W >> H;

    if (W == 0 || H == 0) return false;

    for (int i = 0; i < H; i++){
        cin >> graph[i];
    }

    return true;
}

void searchDirtyLocation(){
    for (int i = 0; i < H; i++){
        for (int j = 0; j < W; j++){
            if (graph[i][j] == '*') dusts.push_back({i, j});
            if (graph[i][j] == 'o') {
                robotIdx = dusts.size();
                dusts.push_back({i, j});
                robot = {i, j};
            }
        }
    }
}

int BFS(pii src){
    for (int i = 0; i < H; i++){
        for (int j = 0; j < W; j++){
            dist[src][i][j] = -1;
        }
    }

    queue<pii> order;
    order.push(src);
    dist[src][src.first][src.second] = 0;
    int cnt = 1;

    while (!order.empty()){
        int x = order.front().first, y = order.front().second;
        order.pop();

        for (int i = 0; i < 4; i++){
            int nx = x + dx[i], ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= H || ny >= W) continue;
            if (dist[src][nx][ny] != -1 || graph[nx][ny] == 'x') continue;

            if (graph[nx][ny] == '*' || graph[nx][ny] == 'o') cnt++;
            order.push({nx, ny});
            dist[src][nx][ny] = dist[src][x][y] + 1;
            if (cnt == dusts.size()) return cnt;
        }
    }

    return cnt;
}

int tsp(int state, pii cur){
    if (state == (1 << dusts.size()) - 1) return 0;

    int &ret = cache[state][cur];

    if (ret > 0) return ret;

    ret = INF;

    for (int i = 0; i < dusts.size(); i++){
        if (!(state & (1 << i))) {
            ret = min(ret, tsp(state | (1 << i), dusts[i]) + dist[cur][dusts[i].first][dusts[i].second]);
        }
    }

    return ret;
}

void solution(){
    while(input()){
        bool flag = true;
        searchDirtyLocation();
        for(auto& src : dusts){
            if (BFS(src) != dusts.size()) {
                flag = false;
                cout << -1 << '\n';
                break;
            }
        }

        if(flag) {
            int initState = (1 << robotIdx);

            cout << tsp(initState, robot) << '\n';
        }


        dist.clear();
        for (int i = 0; i < (1 << dusts.size()); i++){
            cache[i].clear();
        }
        dusts.clear();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    solution();
}