#include <iostream>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;
const int INF = 2e9;
int N, M, H;
bool adj[31][11];

int dx[3] = { 1, 1, 1 };
int dy[3] = { 1, -1, 0 };

void input() {
    cin >> N >> M >> H;

    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        adj[a][b] = true;
    }
}


bool check(int src) {
    int x = 1, y = src;
    int dir;

    for (int h = 1; h <= H; h++) {
        if (adj[h][y]) dir = 0;
        else if (adj[h][y - 1]) dir = 1;
        else dir = 2;

        x += dx[dir];
        y += dy[dir];
    }

    return y == src;
}

int solve(int cnt, int x, int y) {
    if (y >= N) return solve(cnt, x + 1, 0);

    if (cnt == 3 || x == H+1) {
        for (int i = 1; i <= N; i++) {
            if (!check(i)) return INF;
        }
        return cnt;
    }

    int ret = INF;

    ret = min(ret, solve(cnt, x, y + 1));

    if (adj[x][y - 1] || adj[x][y] || adj[x][y + 1]) {
        return ret;
    }

    adj[x][y] = true;
    ret = min(ret, solve(cnt + 1, x, y + 2));
    adj[x][y] = false;

    return ret;
}

void solution() {
    input();
    int cnt = solve(0, 1, 1);
    cout << (cnt < INF ? cnt : -1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    solution();
}