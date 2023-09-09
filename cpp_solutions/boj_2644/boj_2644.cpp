#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;
typedef pair<int, int> pii;
int N, M, T1, T2;
bool v[101][101];
bool visited[101];

void input(){
    cin >> N >> T1 >> T2 >> M;

    int x, y;

    for (int i = 0; i < M; i++) {
        cin >> x >> y;

        v[x][y] = v[y][x] = true;
    }
}

int solve(){
    queue<pii> order;

    order.push({T1, 0});

    while(!order.empty()){
        int node, cost;
        tie(node, cost) = order.front();
        order.pop();

        for (int i = 1; i <= N; i++){
            if (!v[node][i] || visited[i]) continue;

            if (i == T2) return cost + 1;

            order.push({i, cost + 1});
            visited[i] = true;
        }
    }

    return -1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    input();
    cout << solve();
}