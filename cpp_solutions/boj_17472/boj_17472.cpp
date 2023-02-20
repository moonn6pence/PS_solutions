#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef pair<int, pii> pipii;
const int INF = 2e9;
int N, M, cnt = 1;
int land[10][10], graph[7][7], visited[10][10];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
queue<pipii> checker;
int parent[7] = {0, 1, 2, 3, 4, 5, 6};

void input(){
    cin >> N >> M;
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            cin >> land[i][j];
        }
    }
}

void bfs(pii src, int num){
    queue<pii> order;
    order.push(src);
    visited[src.first][src.second] = num;

    while (!order.empty()){
        int x, y;
        tie(x, y) = order.front();
        order.pop();

        for (int i = 0; i < 4; i++){
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if (visited[nx][ny]) continue;
            if (!land[nx][ny]) {
                checker.push({i, {x, y}});
                continue;
            }

            order.push({nx, ny});
            visited[nx][ny] = num;
        }
    }
}

void separateIsland(){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            if (land[i][j] && !visited[i][j]){
                bfs({i, j}, cnt++);
                if (cnt == 7) return;
            }
        }
    }
}

void setDist(){

    while (!checker.empty()){
        int dir = checker.front().first, x, y;
        tie(x, y) = checker.front().second;
        checker.pop();

        int dist = -1;
        int nx = x, ny = y;
        int &land1 = visited[x][y];

        while (true){
            nx += dx[dir];
            ny += dy[dir];
            if (nx < 0 || ny < 0 || nx >= N || ny >= M) break;
            if (visited[nx][ny] == land1) break;

            dist++;
            int &land2 = visited[nx][ny];
            if (land2){
                if (dist == 1) break;
                if (graph[land1][land2] >= dist)
                    graph[land1][land2] = graph[land2][land1] = dist;
                break;
            }
        }
    }
}

int find(int x){
    if(x == parent[x]) return x;

    return parent[x] = find(parent[x]);
}

void Union(int a, int b){
    a = find(a);
    b = find(b);

    if (a < b) parent[b] = a;
    else parent[a] = b;
}

int kruskal(){
    priority_queue<pipii, vector<pipii>, greater<pipii>> edges;
    for (int i = 1; i < cnt - 1; i++){
        for (int j = i + 1; j < cnt; j++){
            if(graph[i][j] < INF) edges.push({graph[i][j], {i, j}});
        }
    }

    int ret = 0, c, a, b;

    while (!edges.empty()){
        c = edges.top().first;
        tie(a, b) = edges.top().second;
        edges.pop();

        if (find(a) == find(b)) continue;

        Union(a, b);
        ret += c;
    }

    // for (int i = 1; i < cnt;i++){
    //     cout << parent[i] << ' ';
    // }

    // cout << '\n';

    int x = find(parent[1]);

    for (int i = 2; i < cnt; i++){
        if (x != find(parent[i])) return -1;
    }

    return ret;
}

void solution(){
    input();
    fill(&graph[0][0], &graph[6][7], INF);
    separateIsland();
    setDist();

    cout << '\n';
    for (int i = 1; i < cnt;i++)
    {
        for (int j = 1; j < cnt;j++){
            cout << (graph[i][j] < INF ? graph[i][j] : 0) << ' ';
        }
        cout << '\n';
    }
    cout << kruskal();
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    solution();
}