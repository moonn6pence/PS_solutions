#include <bits/stdc++.h>

using namespace std;
int N, M, K;
int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
string graph[10];
char tmp[6];
map<string, int> result;

void input(){
    cin >> N >> M >> K;

    for (int i = 0; i < N; i++) cin >> graph[i];
}

void DFS(int x, int y, int k){
    tmp[k] = graph[x][y];
    tmp[k + 1] = '\0';
    result[string(tmp)]++;

    if (k == 4) return;

    for (int i = 0; i < 8; i++){
        int nx = (x + dx[i] + N) % N, ny = (y + dy[i] + M) % M;
        DFS(nx, ny, k + 1);
    }
}

void solve(){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++){
            DFS(i, j, 0);
        }
    }

    for (int i = 0; i < K; i++){
        string s;
        cin >> s;
        cout << result[s] << '\n';
    }
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