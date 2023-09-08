#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
typedef tuple<int, int, int> info;
int N, answer = 987654321;
pii S;
string graph[50];
int visited[4][50][50];
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void input(){
    cin >> N;

    string line;

    for (int i = 0; i < N; i++){
        cin >> graph[i];
    }

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            if (graph[i][j] == '#') {
                S = {i, j};
                return;
            }
        }
    }

}

int solution(){
    queue<info> pq;

    for (int i = 0; i < 4; i++) {
        visited[i][S.first][S.second] = 0;
        int nx = S.first + dx[i], ny = S.second + dy[i];

        if (nx < 0 || nx >= N || ny < 0 || ny >= N || graph[nx][ny] == '*') continue;
        pq.push({i, nx, ny});
        visited[i][nx][ny] = 0;
    }

    while(!pq.empty()){
        int x, y, preDir;
        tie(preDir, x, y) = pq.front();
        pq.pop();

        if (graph[x][y] == '#') {
            answer = min(answer, visited[preDir][x][y]);
            continue;
        }

        for (int i = 0; i < 4; i++){
            bool isStraight = (i == preDir);

            if (i == (preDir + 2) % 4) continue;

            int nx = x + dx[i], ny = y + dy[i];

            if (nx < 0 || nx >= N || ny < 0 || ny >= N || graph[nx][ny] == '*') continue;
            if (visited[i][nx][ny] != -1 && visited[i][nx][ny] < visited[preDir][x][y] + !isStraight) continue;
            if (!isStraight && graph[x][y] != '!') continue;
            visited[i][nx][ny] = visited[preDir][x][y] + !isStraight;
            pq.push({i, nx, ny});
        }
    }

    return answer;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    input();

    fill(&visited[0][0][0], &visited[3][49][50], -1);

    cout << solution();
}